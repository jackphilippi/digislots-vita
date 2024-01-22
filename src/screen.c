#include <stdio.h>
#include <stdarg.h>

#include "debugScreen.h"
#include "screen.h"

/*
* Printf text onto debug screen
*/
__attribute__((__format__ (__printf__, 1, 2)))
int print(const char *format, ...) {
	char buf[4096];

	va_list opt;
	va_start(opt, format);
	int ret = vsnprintf(buf, sizeof(buf), format, opt);
	psvDebugScreenPuts(buf);
	va_end(opt);
	
	psvDebugScreenSetFgColor(0xFFFFFFFF);
	psvDebugScreenSetBgColor(0x00000000);

	return ret;
}

void setupScreen() {
    PsvDebugScreenFont *psvDebugScreenFont_default_1x;
	PsvDebugScreenFont *psvDebugScreenFont_default_2x;
	PsvDebugScreenFont *psvDebugScreenFont_current;

    // --- LOAD FONT AND DEBUG SCREEN STUFF ---
	psvDebugScreenInit();
    
    // get default font
	psvDebugScreenFont_default_1x = psvDebugScreenGetFont();
	// create a scaled by 2 version of default font
	psvDebugScreenFont_default_2x = psvDebugScreenScaleFont2x(psvDebugScreenFont_default_1x);
	if (!psvDebugScreenFont_default_2x) {
		// TODO: error message check font data
		psvDebugScreenFont_default_2x = psvDebugScreenFont_default_1x;
        print("Error: Check font data\n");
	} else {
		// set scaled default font
		psvDebugScreenFont_current = psvDebugScreenSetFont(psvDebugScreenFont_default_2x);
		if (psvDebugScreenFont_current != psvDebugScreenFont_default_2x) { // font was not set
            print("Unable to set font\n");
		}
	}
}

void clearScreen() {
    print("\e[H\e[2J");
}

