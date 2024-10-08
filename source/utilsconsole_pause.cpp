/**
 * utilsconsole.cpp
 *   by Zy
 */


#include <iostream>

extern "C" {

#include "utilsconsole_pause.h"
#include <3ds.h>
#include <stdarg.h>

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

}
