#include <psp2/io/fcntl.h> // File control definitions
#include <psp2/kernel/threadmgr.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/ctrl.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "offsets.h"
#include "screen.h"
#include "models/digimon.h"
#include "save_mappings/ascii_m.h"
#include "save_mappings/item_m.h"

#define BUFFER_SIZE 8192 // 0x2000
#define LINE_BYTES_LENGTH 32
#define MAX_MAPPING 256 // Assuming 1-byte values

int numberLoops = 0;

Digimon* randomEvo = NULL;

void waitForButtonPress(SceCtrlButtons expectedButton) {
	// Enable button input
	sceCtrlSetSamplingMode(SCE_CTRL_MODE_DIGITAL);
    SceCtrlData pad;

    // Loop until button is pressed
    while (1) {
        // Read controller state
        sceCtrlPeekBufferPositive(0, &pad, 1);

        if (pad.buttons & expectedButton) {
            // Delay for debounce
            sceKernelDelayThread(300 * 1000); // 300 milliseconds
            break;
        }

        sceKernelDelayThread(10 * 1000); // Wait for 5 seconds before allowing button press again
    }
}

void printStats(Digimon* digi) {
    // Clear the screen
    clearScreen();

    // Print screen title
    print("Fippi's Digimon Slots for Vita! [%d]\n\n", numberLoops);

    printDigimonStats(digi);

    randomEvo = getRandomEvolution(digi);
    printEvolutionRequirements(digi, randomEvo);
}

int readFileToBuffer(char* path, unsigned char* buffer) {
    // Open the file 
    SceUID fh = sceIoOpen( path, SCE_O_RDONLY, 0777 );
    if (fh < 0) {
        print("Error opening file: %08x\n", fh);
        sceKernelDelayThread(5*1000000); // Wait for 3 seconds
        return -1;
    }

    print("Read PS1 save file successfully from:\n");
    print(path);
    print("\n\n");
    
    // put the PS1 save into our buffer
    if (sceIoPread(fh, buffer, BUFFER_SIZE, OFS_PS1_SAVE_START) < 0) {
        print("Failed to read data from file\n");
        sceKernelDelayThread(5*1000000); // Wait for 3 seconds
        return -1;
    }

    // Close the file
    sceIoClose(fh);
    return 0;
}

int main() {

    // Set up the debug screen and print command so that 
    // we can print to the screen
    setupScreen();

    // TODO: Make this configurable
	char path[] = "ux0:/pspemu/PSP/SAVEDATA/SLUS01032/SCEVMC0.VMP"; // SCEVMC0 = Phoenixmon, SCEVMC1 = Kokatorimon, SCEVMC2 = Digitamamon
	unsigned char buffer[BUFFER_SIZE];

    print("Fippi's Digimon Slots for Vita!\n\n");

    readFileToBuffer(path, buffer);

    unsigned int digiSearchId = buffer[OFS_DIGIMON_TYPE];
    print("Current digimon has ID [0x%X]:\n", digiSearchId);

    // Convert the string to an integer
    Digimon* digi = NULL;
    for (int i = 0; i < DIGIMON_MAPPING_SIZE; i++) {
        if (digimonMap[i].searchId == digiSearchId) {
            digi = digimonMap[i].digimon;
            break;
        }
    }

    if (digi == NULL) {
        print("ERROR: Failed to find a digimon with ID: 0x%X\n", digiSearchId);
        return sceKernelDelayThread(~0);
    }

    setDigimonStatsFromBuffer(digi, buffer);

    // Initialise all digimon data
    initialiseDigimon();
    
    while (1) {
        // Set the seed for RNG
        srand(time(NULL));

        print("Press CROSS to continue\n\n");

        waitForButtonPress(SCE_CTRL_CROSS);

        printStats(digi);   
    }

	sceKernelDelayThread(0);
    return 0;
}