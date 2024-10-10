/**
 * utilsconsole_extern_c.cpp
 *   by Zy
 */


#include <iostream>

extern "C" {

#include "utilsconsole_extern_c.h"
#include <3ds.h>
#include <stdarg.h>
#include <string.h>

using namespace std;

void uc_pause(void) {
    cout << "\e[0;2mPress (A) to continue...\e[0m" << endl;
    while (aptMainLoop()) {
        hidScanInput();
        if (hidKeysDown() & KEY_A)
            break;
        gfxFlushBuffers();
    }
}

char	*uc_keyboard(const char *def)
{
	char *buf;
	SwkbdState swkbd;

	buf = new char[1000];
	if (!buf)
		return (NULL);
	swkbdInit(&swkbd, SWKBD_TYPE_NORMAL, 1, -1);
	swkbdSetInitialText(&swkbd, def);
	swkbdInputText(&swkbd, buf, 1000);
	return (buf);
}

}
