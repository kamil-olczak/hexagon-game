#include "Headers.h"

/**
 * Starts main Thread
 * 
 * \return 
 */
int launch() {
    
    const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    console::setConsoleFont(hConsole);
    console::resetCursor(hConsole);

    bool gameLoopStarted = false;

    return initMenu(hConsole, gameLoopStarted);

    

}

