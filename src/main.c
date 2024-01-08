#include <psp2/io/fcntl.h> // File control definitions
#include <psp2/kernel/threadmgr.h>
#include <psp2/kernel/processmgr.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "debugScreen.h"
#include "models/digimon.h"
#include "save_mappings/ascii_m.h"
#include "save_mappings/item_m.h"

#define printf psvDebugScreenPrintf
#define OFFSET 0x2080
#define BUFFER_SIZE 4
#define LINE_BYTES_LENGTH 16
#define MAX_MAPPING 256 // Assuming 1-byte values

#define CUSTOM_BG_BLUE  0x00003F  // "dark" blue
#define CUSTOM_BG_RED   0x3F0000  // "dark" red
#define CUSTOM_BG_GREEN 0x003F00  // "dark" green

void printDigimonStats(Digimon* digimon) {
    // Print all of botamon's data
    printf("%s\n\n", digimon->name);

    printf("HP: %i\n", digimon->req.hp);
    printf("Attack: %i\n", digimon->req.offense);
    printf("Defense: %i\n", digimon->req.defense);
    printf("Speed: %i\n", digimon->req.speed);
    printf("Brains: %i\n", digimon->req.brains);
    printf("Care: %i\n", digimon->req.care);
    printf("Weight: %i\n", digimon->req.weight);
    printf("Discipline: %i\n", digimon->req.discipline);
    printf("Happiness: %i\n\n", digimon->req.happiness);
    printf("Battles: %i\n", digimon->req.battles);
    printf("Tech: %i\n\n", digimon->req.techs);
    printf("MinCare: %i\n", digimon->req.minCare);
    printf("MinBattles: %i\n\n", digimon->req.minBattles);

    printf("%d evolutions: %s\n\n", digimon->evolutionPathSize, getEvolutionNameStrings(digimon));

    if (digimon->digimonBonus != NULL) {
        printf("Bonus digimon: %s", digimon->digimonBonus->name);
    }
}

int main() {
	PsvDebugScreenFont *psvDebugScreenFont_default_1x;
	PsvDebugScreenFont *psvDebugScreenFont_default_2x;
	PsvDebugScreenFont *psvDebugScreenFont_current;

    // TODO: Make this configurable
	char path[] = "ux0:/pspemu/PSP/SAVEDATA/SLUS01032/SCEVMC0.VMP";
	unsigned char buffer[1];

    // --- LOAD FONT AND DEBUG SCREEN STUFF ---
	psvDebugScreenInit();
    // get default font
	psvDebugScreenFont_default_1x = psvDebugScreenGetFont();
	// create a scaled by 2 version of default font
	psvDebugScreenFont_default_2x = psvDebugScreenScaleFont2x(psvDebugScreenFont_default_1x);
	if (!psvDebugScreenFont_default_2x) {
		// TODO: error message check font data
		psvDebugScreenFont_default_2x = psvDebugScreenFont_default_1x;
        printf("Error: Check font data\n");
	} else {
		// set scaled default font
		psvDebugScreenFont_current = psvDebugScreenSetFont(psvDebugScreenFont_default_2x);
		if (psvDebugScreenFont_current != psvDebugScreenFont_default_2x) { // font was not set
            printf("Unable to set font\n");
		}
	}

	printf("Fippi's Digimon Slots for Vita!\n\n");

    // Open the file 
    SceUID fh = sceIoOpen( path, SCE_O_RDONLY, 0777 );
    if (fh < 0) {
        printf("Error opening file: %08x\n", fh);
		sceKernelDelayThread(5*1000000); // Wait for 3 seconds
        return -1;
    }

    printf("Read PS1 save file successfully from:\n");
    printf(path);
    printf("\n\n");

	// Go to the start of the PS1 save (0x2080) inside the PSP savedata
    if (sceIoLseek(fh, OFFSET, SCE_SEEK_SET) != OFFSET) {
        printf("Failed to seek to offset 0x%X\n", OFFSET);
		sceKernelDelayThread(5*1000000); // Wait for 3 seconds
        return -1;
    }

	// Go to the location of the Tamer Name (0x0667), offset from 0x2080
    // if (sceIoLseek(fh, 0x0667, SCE_SEEK_CUR) != OFFSET+0x0667) {
    //     printf("Failed to seek to offset a second time 0x%X\n", 0x0667);
	// 	sceKernelDelayThread(5*1000000); // Wait for 3 seconds
    //     return -1;
    // }
    
    // pull 19 bytes
    if (sceIoPread(fh, buffer, sizeof(buffer), 0x2080 + 0x03B8) < 0) {
        printf("Failed to read data from file\n");
		sceKernelDelayThread(5*1000000); // Wait for 3 seconds
        return -1;
    }

	// Close the file
    sceIoClose(fh);

    printf("Current digimon has ID [0x%X]:\n", buffer[0]);

    // Convert the string to an integer
    Digimon* digi = NULL;
    for (int i = 0; i < DIGIMON_MAPPING_SIZE; i++) {
        if (digimonMap[i].searchId == buffer[0]) {
            digi = digimonMap[i].digimon;
            break;
        }
    }

    if (digi == NULL) {
        printf("Failed to fetch digimon with ID: 0x%X\n", buffer[0]);
    }

    // Print the bytes in hexadecimal format
    // printf("Tamer Name (bytes):\n");
    // for (int i = 0; i < sizeof(buffer); i++) {
    //     if (i != 0 && i%LINE_BYTES_LENGTH == 0) {
    //         printf("\n");
    //     }
    //     printf("%02X ", buffer[i]);
    // }
    // printf("\n\n");

    // Print digimon name from byte ID
    // char* digimon = getDigimonName(0x1F);
    // printf("Digimon: %s\n\n", digimon);

    // Print item name from byte ID
    // char* item = getItemName(0x45);
    // printf("Item: %s\n\n", item);

    // Print a string given a number of digi ascii words
    // int asciiString[] = {0x8290, 0x828F, 0x826D, 0x826A, 0x826E};
    // int size = sizeof(asciiString) / sizeof(asciiString[0]);
    // char outputString[size + 1]; // +1 for null terminator
    // wordsArrayToString(asciiString, size, outputString);
    // printf("Converted string: %s\n\n", outputString);

    initialiseDigimon();
    
    printDigimonStats(digi);

	return sceKernelDelayThread(~0);
}