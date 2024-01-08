#include <psp2/io/fcntl.h> // File control definitions
#include <psp2/kernel/threadmgr.h>
#include <psp2/kernel/processmgr.h>
#include <stdio.h>
#include <stdbool.h>

#include "debugScreen.h"
#include "models/digimon.h"
#include "save_mappings/digimon_m.h"
#include "save_mappings/ascii_m.h"
#include "save_mappings/item_m.h"

#define printf psvDebugScreenPrintf
#define OFFSET 0x2080
#define BUFFER_SIZE 18
#define LINE_BYTES_LENGTH 16
#define MAX_MAPPING 256 // Assuming 1-byte values

#define CUSTOM_BG_BLUE  0x00003F  // "dark" blue
#define CUSTOM_BG_RED   0x3F0000  // "dark" red
#define CUSTOM_BG_GREEN 0x003F00  // "dark" green

extern Digimon botamon;
extern Digimon poyomon;
extern Digimon punimon;
extern Digimon yuramon;
extern Digimon koromon;
extern Digimon tanemon;
extern Digimon tokomon;
extern Digimon tsunomon;
extern Digimon agumon;
extern Digimon betamon;
extern Digimon biyomon;
extern Digimon elecmon;
extern Digimon gabumon;
extern Digimon kunemon;
extern Digimon palmon;
extern Digimon patamon;
extern Digimon penguinmon;
extern Digimon airdramon;
extern Digimon angemon;
extern Digimon bakemon;
extern Digimon birdramon;
extern Digimon centarumon;
extern Digimon coelamon;
extern Digimon devimon;
extern Digimon drimogemon;
extern Digimon frigimon;
extern Digimon garurumon;
extern Digimon greymon;
extern Digimon kabuterimon;
extern Digimon kokatorimon;
extern Digimon kuwagamon;
extern Digimon leomon;
extern Digimon meramon;
extern Digimon mojyamon;
extern Digimon monochromon;
extern Digimon nanimon;
extern Digimon ninjamon;
extern Digimon numemon;
extern Digimon ogremon;
extern Digimon seadramon;
extern Digimon shellmon;
extern Digimon sukamon;
extern Digimon tyrannomon;
extern Digimon unimon;
extern Digimon vegiemon;
extern Digimon whamon;
extern Digimon andromon;
extern Digimon digitamamon;
extern Digimon etemon;
extern Digimon giromon;
extern Digimon hkabuterimon;
extern Digimon mamemon;
extern Digimon megadramon;
extern Digimon megaseadramon;
extern Digimon metalgreymon;
extern Digimon metalmamemon;
extern Digimon monzaemon;
extern Digimon phoenixmon;
extern Digimon piximon;
extern Digimon skullgreymon;
extern Digimon vademon;

void printDigimonStats(Digimon digimon) {
    // Print all of botamon's data
    printf("%s\n\n", digimon.name);

    printf("HP: %i\n", digimon.req.hp);
    printf("Attack: %i\n", digimon.req.offense);
    printf("Defense: %i\n", digimon.req.defense);
    printf("Speed: %i\n", digimon.req.speed);
    printf("Brains: %i\n", digimon.req.brains);
    printf("Care: %i\n", digimon.req.care);
    printf("Weight: %i\n", digimon.req.weight);
    printf("Discipline: %i\n", digimon.req.discipline);
    printf("Happiness: %i\n\n", digimon.req.happiness);
    printf("Battles: %i\n", digimon.req.battles);
    printf("Tech: %i\n\n", digimon.req.techs);
    printf("MinCare: %i\n", digimon.req.minCare);
    printf("MinBattles: %i\n\n", digimon.req.minBattles);

    printf("%d evolutions: %s\n\n", digimon.evolutionPathSize, getEvolutionNameStrings(&digimon));

    if (digimon.digimonBonus) {
        printf("Bonus digimon: %s", digimon.digimonBonus->name);
    }
}

int main() {
	PsvDebugScreenFont *psvDebugScreenFont_default_1x;
	PsvDebugScreenFont *psvDebugScreenFont_default_2x;
	PsvDebugScreenFont *psvDebugScreenFont_current;

    // TODO: Make this configurable
	char path[] = "ux0:/pspemu/PSP/SAVEDATA/SLUS01032/SCEVMC0.VMP";
	unsigned char buffer[BUFFER_SIZE];

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

	printf("Fippi's Digimon Slots for Vita!\n");

    // Open the file 
    SceUID fh = sceIoOpen( path, SCE_O_RDONLY, 0777 );
    if (fh < 0) {
        printf("Error opening file: %08x\n", fh);
		sceKernelDelayThread(5*1000000); // Wait for 3 seconds
        return -1;
    }

    printf("Read PS1 save file successfully\n");
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
    if (sceIoPread(fh, buffer, sizeof(buffer), 0x2080 + 0x0667) < 0) {
        printf("Failed to read data from file\n");
		sceKernelDelayThread(5*1000000); // Wait for 3 seconds
        return -1;
    }

	// Close the file
    sceIoClose(fh);

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
    
    printDigimonStats(shellmon);

	return sceKernelDelayThread(~0);
}