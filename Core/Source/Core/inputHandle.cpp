#include "inputHandle.h"


/**
 * Checks wheter key is pressed or was pressed 
 * 
 * \return if function finds a pressed key or not 
 */
const short checkKey() {
    if (GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(0x31) || GetAsyncKeyState(0x32) || GetAsyncKeyState(0x33) || GetAsyncKeyState(0x34) || GetAsyncKeyState(0x35) || GetAsyncKeyState(0x36)) {
        return 0;
    }


    for (short i = 0x8; i <= 0xBE; ++i) {
        if (GetAsyncKeyState(i)) {
            return i;
        }
    }
    return 0;
}