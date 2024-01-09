#include <psp2/io/fcntl.h> // File control definitions
#include <psp2/kernel/threadmgr.h>
#include <psp2/kernel/processmgr.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "offsets.h"
#include "debugScreen.h"
#include "models/digimon.h"
#include "save_mappings/ascii_m.h"
#include "save_mappings/item_m.h"

#define printf psvDebugScreenPrintf
#define BUFFER_SIZE 8192 // 0x2000
#define LINE_BYTES_LENGTH 32
#define MAX_MAPPING 256 // Assuming 1-byte values

#define CUSTOM_BG_BLUE  0x00003F  // "dark" blue
#define CUSTOM_BG_RED   0x3F0000  // "dark" red
#define CUSTOM_BG_GREEN 0x003F00  // "dark" green

void printDigimonStats(Digimon* digimon) {
    // Print all of botamon's data
    printf("%s\n\n", digimon->name);

    // printf("HP: %i\n", digimon->req.hp);
    // printf("Attack: %i\n", digimon->req.offense);
    // printf("Defense: %i\n", digimon->req.defense);
    // printf("Speed: %i\n", digimon->req.speed);
    // printf("Brains: %i\n", digimon->req.brains);
    // printf("Care: %i\n", digimon->req.care);
    // printf("Weight: %i\n", digimon->req.weight);
    // printf("Discipline: %i\n", digimon->req.discipline);
    // printf("Happiness: %i\n\n", digimon->req.happiness);
    // printf("Battles: %i\n", digimon->req.battles);
    // printf("Tech: %i\n\n", digimon->req.techs);
    // printf("MinCare: %i\n", digimon->req.minCare);
    // printf("MinBattles: %i\n\n", digimon->req.minBattles);

    printf("HP: %d\n", digimon->stats.hp);
    printf("MP: %d\n", digimon->stats.mp);
    printf("Offense: %d\n", digimon->stats.offense);
    printf("Defense: %d\n", digimon->stats.defense);
    printf("Speed: %d\n", digimon->stats.speed);
    printf("Brains: %d\n", digimon->stats.brains);
    printf("Care: %d\n", digimon->stats.care);
    printf("Weight: %d\n", digimon->stats.weight);
    printf("Discipline: %d\n", digimon->stats.discipline);
    printf("Happiness: %d\n\n", digimon->stats.happiness);
    printf("Battles: %d\n", digimon->stats.battles);
    printf("Tech: %d\n\n", digimon->stats.techs);

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
    
    // put the PS1 save into our buffer
    if (sceIoPread(fh, buffer, BUFFER_SIZE, OFS_PS1_SAVE_START) < 0) {
        printf("Failed to read data from file\n");
		sceKernelDelayThread(5*1000000); // Wait for 3 seconds
        return -1;
    }

	// Close the file
    sceIoClose(fh);

    unsigned int digiSearchId = buffer[OFS_DIGIMON_TYPE];
    printf("\e[31mCurrent digimon has ID [0x%X]:\e[39;49m\n", digiSearchId);

    // Convert the string to an integer
    Digimon* digi = NULL;
    for (int i = 0; i < DIGIMON_MAPPING_SIZE; i++) {
        if (digimonMap[i].searchId == digiSearchId) {
            digi = digimonMap[i].digimon;
            break;
        }
    }

    if (digi == NULL) {
        printf("ERROR: Failed to find a digimon with ID: 0x%X\n", digiSearchId);
    	return sceKernelDelayThread(~0);
    }

    int getStatValue(int highByte, int lowByte) {
        return buffer[OFS_DIGIMON_STATS + highByte] + (buffer[OFS_DIGIMON_STATS + lowByte] << 8);
    }

    int getPartnerValue(int highByte, int lowByte) {
        return buffer[OFS_DIGIMON_PARTNER_STATS + highByte] + (buffer[OFS_DIGIMON_PARTNER_STATS + lowByte] << 8);
    }

    DigimonStats ds = {
        // Come from 0x0470
        .offense = getStatValue(0x00, 0x01),
        .defense = getStatValue(0x02, 0x03),
        .speed = getStatValue(0x04, 0x05),
        .brains = getStatValue(0x06, 0x07),
        .techs = getStatValue(0x0C, 0x0D), // TODO: Decode the bit field for techs
        .hp = getStatValue(0x10, 0x11),
        .mp = getStatValue(0x12, 0x13),

        // Come from 0x03E0
        .care = getPartnerValue(0x52, 0x53),
        .weight = getPartnerValue(0x42, 0x43),
        .discipline = getPartnerValue(0x28, 0x29),
        .happiness = getPartnerValue(0x2A, 0x2B),
        .battles = getPartnerValue(0x54, 0x55),
    };

    digi->stats = ds;

    // Print first x chars of buffer
    // for (int i = OFS_DIGIMON_TYPE_START; i < 2000; i++) {
    //     if (i%LINE_BYTES_LENGTH == 0) {
    //         printf("\n");
    //         printf("%-5X", i);
    //     }
    //     printf("%02X ", buffer[i]);
    // }
    // printf("\n");

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