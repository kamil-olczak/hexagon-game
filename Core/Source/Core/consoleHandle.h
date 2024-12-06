#pragma once
#include <Windows.h>

namespace console {
    enum textColor
    {
        grayColor = 8,
        greenColor = 10,
        cyanColor = 11,
        redColor = 12,
        whiteColor = 15
    };

    void resetCursor(const HANDLE& hConsole);
    void setCursorOnStartInfoPos(const HANDLE& hConsole);
    void setCursorOnInfoPosAndGetLine(const HANDLE& hConsole);
    void disableCursor(const HANDLE& hConsole);
    void clear(const HANDLE& hConsole);
    void clearInfo(const HANDLE& hConsole);
    void clearInfoFirstLine(const HANDLE& hConsole);
    void clearScoreBoard(const HANDLE& hConsole);
    void setConsoleFont(const HANDLE& hConsole);
}



