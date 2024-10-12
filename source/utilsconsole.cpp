/**
 * utilsconsole.cpp
 *   by Zy
 */

#include <iostream>
#include <cstring>
extern "C" {
#include "utilsconsole.h"
#include <3ds.h>
#include <stdarg.h>
}

using namespace std;

int uc_menu(vector<s_uc_menu_element> &elements) {
    static void *lastElements = NULL;
    static size_t selected = 0;

    bool confirmed = false;

    if (&elements != lastElements) {
        // init if new menu
        consoleClear();
        lastElements = &elements;
        selected = 0;
    }
    else {
        // read inputs
        hidScanInput();
        if (hidKeysDown() & KEY_UP) {
            if (selected-- == 0)
                selected += elements.size();
        }
        else if (hidKeysDown() & KEY_DOWN) {
            if (++selected >= elements.size())
                selected -= elements.size();
        }
        else if (!elements[selected].is_number_prompt) {
            if (hidKeysDown() & KEY_A) {
                confirmed = true;
                lastElements = NULL;
            }
        }
        else {
            if (hidKeysDown() & KEY_LEFT)
                if (*elements[selected].value > elements[selected].min)
                    (*elements[selected].value)--;
            if (hidKeysDown() & KEY_RIGHT)
                if (*elements[selected].value < elements[selected].max)
                    (*elements[selected].value)++;
        }
    }

    // display
    cout << "\e[H\e[0m";
    for (size_t i = 0; i < elements.size(); i++) {
        cout << (i == selected && !confirmed ? "\e[7m" : "")
            << elements[i].name << "\e[0m";
        if (elements[i].is_number_prompt)
            cout
                << ((*(elements[i].value) == elements[i].min) ? "  " : " <")
                << *(elements[i].value)
                << ((*(elements[i].value) == elements[i].max) ? " " : ">");
        cout << "\e[0K" << endl;
    }
    if (!confirmed)
        cout << "\e[2m" << "[Up/Down] Move / "
            << (elements[selected].is_number_prompt ?
            "[Left/Right] Modify" : "(A) Confirm") << "\e[0K" << endl;
    else
        cout << "\e[2mOK.\e[0K\e[0m" << endl;
    
    return confirmed ? selected : -1;
}

extern "C" {

int uc_menu_quick(const char *str, ...) {
    va_list arguments;
    auto elements = vector<s_uc_menu_element>();
    for (va_start(arguments, str); str; str = va_arg(arguments, const char *))
        elements.push_back({str, false, NULL, 0, 0});
    
    int r = -1;
    while (r < 0 && aptMainLoop())
        r = uc_menu(elements);
    return r;
}

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
