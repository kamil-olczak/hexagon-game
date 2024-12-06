#include "consoleHandle.h"

namespace console {


    /**
     * Resets console cursor to x 0 y 0
     * 
     * \param hConsole  - HANDLE console I/O interface to control console
     */
    void resetCursor(const HANDLE& hConsole) {
        COORD startPosXY = { 0,0 };
        SetConsoleCursorPosition(hConsole, startPosXY);
    }
    /**
     * Sets console cursor to x 70 y 2
     *
     * \param hConsole  - HANDLE console I/O interface to control console
     */
    void setCursorOnStartInfoPos(const HANDLE& hConsole) {
        COORD infoPosXY = { 70,2 };
        SetConsoleCursorPosition(hConsole, infoPosXY);
    }
    /**
     * Sets console cursor to x 70 y - gets current line
     *
     * \param hConsole  - HANDLE console I/O interface to control console
     */
    void setCursorOnInfoPosAndGetLine(const HANDLE& hConsole) {
        CONSOLE_SCREEN_BUFFER_INFO screenBufferI;
        GetConsoleScreenBufferInfo(hConsole, &screenBufferI);
        COORD infoPosXY = { 70, screenBufferI.dwCursorPosition.Y};
        SetConsoleCursorPosition(hConsole, infoPosXY);
    }

    /**
     * Disables visibility of cursor
     *
     * \param hConsole  - HANDLE console I/O interface to control console
     */
    void disableCursor(const HANDLE& hConsole) {
        CONSOLE_CURSOR_INFO cci {false, 10};

        SetConsoleCursorInfo(hConsole, &cci);
    }
    /**
     * Clears visible console screen
     *
     * \param hConsole  - HANDLE console I/O interface to control console
     */
    void clear(const HANDLE& hConsole) {
   
        CONSOLE_SCREEN_BUFFER_INFO screenBufferI;
        DWORD cWritten = 0;
        GetConsoleScreenBufferInfo(hConsole, &screenBufferI);
        FillConsoleOutputCharacter(hConsole, ' ', (screenBufferI.dwSize.X) * (screenBufferI.dwSize.X /2), { 0,0 }, &cWritten);
        resetCursor(hConsole);
    }
    /**
     * Clears inf part of screen
     *
     * \param hConsole  - HANDLE console I/O interface to control console
     */
    void clearInfo(const HANDLE& hConsole) {

        CONSOLE_SCREEN_BUFFER_INFO screenBufferI;
        DWORD cWritten = 0;
        GetConsoleScreenBufferInfo(hConsole, &screenBufferI);
        for (short y = 2; y < screenBufferI.dwSize.X / 2; ++y) {
            FillConsoleOutputCharacter(hConsole, ' ', (screenBufferI.dwSize.X - 70), { 70,y }, &cWritten);
        }
        resetCursor(hConsole);
    }
    /**
     * Clears first line of info part of screen
     *
     * \param hConsole  - HANDLE console I/O interface to control console
     */
    void clearInfoFirstLine(const HANDLE& hConsole) {

        CONSOLE_SCREEN_BUFFER_INFO screenBufferI;
        DWORD cWritten = 0;
        GetConsoleScreenBufferInfo(hConsole, &screenBufferI);
        FillConsoleOutputCharacter(hConsole, ' ', (screenBufferI.dwSize.X - 70), { 70,2 }, &cWritten);

        resetCursor(hConsole);
    }
    /**
     * Clears scoreBoard part of screen
     *
     * \param hConsole  - HANDLE console I/O interface to control console
     */
    void clearScoreBoard(const HANDLE& hConsole) {
        CONSOLE_SCREEN_BUFFER_INFO screenBufferI;
        DWORD cWritten = 0;
        const short scoreBoardW = 10;
        GetConsoleScreenBufferInfo(hConsole, &screenBufferI);
        for (short y = 19; y < 21; ++y) {
            FillConsoleOutputCharacter(hConsole, ' ', scoreBoardW, { 56,y }, &cWritten);
        }
        resetCursor(hConsole);
    }


    /**
     * Sets console current font 
     * 
     * \param hConsole  - HANDLE console I/O interface to control console
     */
    void setConsoleFont(const HANDLE& hConsole) {
        
        CONSOLE_FONT_INFOEX fontInfo;

        fontInfo.cbSize = sizeof(fontInfo);
        fontInfo.nFont = 0;
        fontInfo.dwFontSize.X = 0;
        fontInfo.dwFontSize.Y = 21;
        fontInfo.FontFamily = FF_DONTCARE;
        fontInfo.FontWeight = FW_NORMAL;
        wcscpy_s(fontInfo.FaceName, L"Consolas");

        SetCurrentConsoleFontEx(hConsole, false, &fontInfo);
        SetConsoleTextAttribute(hConsole, console::whiteColor);
    }

}