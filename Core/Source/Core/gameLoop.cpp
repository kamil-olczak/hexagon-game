#include "gameLoop.h"

/**
 * Starts Game Loop, which is resposible interpreting output from keyboard
 * 
 * \param gameBoard - GameBoard object
 * \param hConsole  - HANDLE console I/O interface to control console
 * \param gameLoopStarted - bool determines if game loop is started
 * \param playerOnMove - player currently on move
 */
void initGameLoop(GameBoard& gameBoard, const HANDLE& hConsole, bool& gameLoopStarted, char& playerOnMove) {
    
    
    bool highligthedAvalable = false;
    char lastChose = 'U';


    console::clear(hConsole);
    gameBoard.countPoints();
    gameBoard.printGameBoard(hConsole);
    printInfo(hConsole, playerOnMove);


    while (gameLoopStarted) {
            switch (checkKey()) {
            case VK_UP:
                Sleep(120);
                if (highligthedAvalable) {
                    if (choseOption(gameBoard, console::greenColor, console::cyanColor, VK_UP, lastChose)) {
                        console::resetCursor(hConsole);
                        gameBoard.printGameBoard(hConsole);
                    }
                }
                else {
                    if (choseOption(gameBoard, playerOnMove, VK_UP, lastChose)) {
                        console::resetCursor(hConsole);
                        gameBoard.printGameBoard(hConsole);
                    }
                }
                break;
            case VK_DOWN:
                Sleep(120);
                if (highligthedAvalable) {
                    if (choseOption(gameBoard, console::greenColor, console::cyanColor, VK_DOWN, lastChose)) {
                        console::resetCursor(hConsole);
                        gameBoard.printGameBoard(hConsole);
                    }
                }
                else {
                    if (choseOption(gameBoard, playerOnMove, VK_DOWN, lastChose)) {
                        console::resetCursor(hConsole);
                        gameBoard.printGameBoard(hConsole);
                    }
                }
                break;
            case VK_RIGHT:
                Sleep(120);
                if (highligthedAvalable) {
                    if (choseOption(gameBoard, console::greenColor, console::cyanColor, VK_RIGHT, lastChose)) {
                        console::resetCursor(hConsole);
                        gameBoard.printGameBoard(hConsole);
                    }
                }
                else {
                    if (choseOption(gameBoard, playerOnMove, VK_RIGHT, lastChose)) {
                        console::resetCursor(hConsole);
                        gameBoard.printGameBoard(hConsole);
                    }
                }
                break;
            case VK_LEFT:
                Sleep(120);
                if (highligthedAvalable) {
                    if (choseOption(gameBoard, console::greenColor, console::cyanColor, VK_LEFT, lastChose)) {
                        console::resetCursor(hConsole);
                        gameBoard.printGameBoard(hConsole);
                    }
                }
                else {
                    if (choseOption(gameBoard, playerOnMove, VK_LEFT, lastChose)) {
                        console::resetCursor(hConsole);
                        gameBoard.printGameBoard(hConsole);
                    }
                }
                break;
            case VK_SPACE:
                Sleep(250);

                confirmSelect(gameBoard, hConsole, playerOnMove, highligthedAvalable);
                console::resetCursor(hConsole);
                gameBoard.printGameBoard(hConsole);
                break;
            case VK_ESCAPE:
                Sleep(80);
                if (highligthedAvalable) {
                    cancelSelect(gameBoard, hConsole, playerOnMove, highligthedAvalable);
                    console::resetCursor(hConsole);
                    gameBoard.printGameBoard(hConsole);
                }
                else {
                    Sleep(200);
                    gameLoopStarted = false;
                    console::clear(hConsole);
                    printInGameMenu();
                }
                break;
            case 0:
                Sleep(10);
                break;
            default:
                Sleep(80);
                console::setCursorOnStartInfoPos(hConsole);
                SetConsoleTextAttribute(hConsole, console::redColor);
                std::cout << "Use only specified keys";
                SetConsoleTextAttribute(hConsole, console::whiteColor);
            }
        
    }
}

/**
 * Starts Game Loop, which is resposible interpreting output from keyboard
 *
 * \param gameBoard - GameBoard object
 * \param hConsole  - HANDLE console I/O interface to control console
 * \param gameLoopStarted - bool determines if game loop is started
 * \param playerOnMove - char player currently on move
 */
void initGameLoopWithComputer(GameBoard& gameBoard, const HANDLE& hConsole, bool& gameLoopStarted, char& playerOnMove) {


    bool highligthedAvalable = false;
    char lastChose = 'U';


    console::clear(hConsole);
    gameBoard.countPoints();
    gameBoard.printGameBoard(hConsole);
    printInfo(hConsole, playerOnMove);


    while (gameLoopStarted) {
        if (playerOnMove == 'R') {
            switch (checkKey()) {
            case VK_UP:
                Sleep(120);
                if (highligthedAvalable) {
                    if (choseOption(gameBoard, console::greenColor, console::cyanColor, VK_UP, lastChose)) {
                        console::resetCursor(hConsole);
                        gameBoard.printGameBoard(hConsole);
                    }
                }
                else {
                    if (choseOption(gameBoard, playerOnMove, VK_UP, lastChose)) {
                        console::resetCursor(hConsole);
                        gameBoard.printGameBoard(hConsole);
                    }
                }
                break;
            case VK_DOWN:
                Sleep(120);
                if (highligthedAvalable) {
                    if (choseOption(gameBoard, console::greenColor, console::cyanColor, VK_DOWN, lastChose)) {
                        console::resetCursor(hConsole);
                        gameBoard.printGameBoard(hConsole);
                    }
                }
                else {
                    if (choseOption(gameBoard, playerOnMove, VK_DOWN, lastChose)) {
                        console::resetCursor(hConsole);
                        gameBoard.printGameBoard(hConsole);
                    }
                }
                break;
            case VK_RIGHT:
                Sleep(120);
                if (highligthedAvalable) {
                    if (choseOption(gameBoard, console::greenColor, console::cyanColor, VK_RIGHT, lastChose)) {
                        console::resetCursor(hConsole);
                        gameBoard.printGameBoard(hConsole);
                    }
                }
                else {
                    if (choseOption(gameBoard, playerOnMove, VK_RIGHT, lastChose)) {
                        console::resetCursor(hConsole);
                        gameBoard.printGameBoard(hConsole);
                    }
                }
                break;
            case VK_LEFT:
                Sleep(120);
                if (highligthedAvalable) {
                    if (choseOption(gameBoard, console::greenColor, console::cyanColor, VK_LEFT, lastChose)) {
                        console::resetCursor(hConsole);
                        gameBoard.printGameBoard(hConsole);
                    }
                }
                else {
                    if (choseOption(gameBoard, playerOnMove, VK_LEFT, lastChose)) {
                        console::resetCursor(hConsole);
                        gameBoard.printGameBoard(hConsole);
                    }
                }
                break;
            case VK_SPACE:
                Sleep(120);

                confirmSelect(gameBoard, hConsole, playerOnMove, highligthedAvalable);
                console::resetCursor(hConsole);
                gameBoard.printGameBoard(hConsole);

                break;
            case VK_ESCAPE:
                Sleep(80);
                if (highligthedAvalable) {
                    cancelSelect(gameBoard, hConsole, playerOnMove, highligthedAvalable);
                    console::resetCursor(hConsole);
                    gameBoard.printGameBoard(hConsole);
                }
                else {
                    Sleep(200);
                    gameLoopStarted = false;
                    console::clear(hConsole);
                    printInGameMenu();
                }
                break;
            case 0:
                Sleep(10);
                break;
            default:
                Sleep(80);
                console::clearInfoFirstLine(hConsole);
                console::setCursorOnStartInfoPos(hConsole);
                SetConsoleTextAttribute(hConsole, console::redColor);
                std::cout << "Use only specified keys";
                SetConsoleTextAttribute(hConsole, console::whiteColor);
            }
        }
        else {
            computerOnMove(gameBoard, playerOnMove, hConsole);


        }

    }
}


/**
 * Prints keyboard input info
 * 
 * \param hConsole  - HANDLE console I/O interface to control console
 * \param palyerOnMove player on move
 */
void printInfo(const HANDLE& hConsole, const char palyerOnMove) {
    console::setCursorOnStartInfoPos(hConsole);
    std::cout << "\n";
    console::setCursorOnInfoPosAndGetLine(hConsole);
    std::cout << "Use arrow keys to chose\n";
    console::setCursorOnInfoPosAndGetLine(hConsole);
    std::cout << "Press SPACE to accept move\n";
    console::setCursorOnInfoPosAndGetLine(hConsole);
    std::cout << "Press ESCAPE to quit to menu\n";
    console::setCursorOnInfoPosAndGetLine(hConsole);
    std::cout << "Player on move: ";
    if (palyerOnMove == 'R') {
        SetConsoleTextAttribute(hConsole, console::redColor);
        std::cout << palyerOnMove;
        SetConsoleTextAttribute(hConsole, console::whiteColor);
    }
    else {
        std::cout << palyerOnMove;
    }
}

/**
 * Prints keyboard input info
 *
 * \param hConsole  - HANDLE console I/O interface to control console
 * \param palyerOnMove player on move
 */
void printInfoOnAccept(const HANDLE& hConsole, const char palyerOnMove) {
    console::setCursorOnStartInfoPos(hConsole);
    std::cout << "\n";
    console::setCursorOnInfoPosAndGetLine(hConsole);
    std::cout << "Use arrow keys to chose\n";
    console::setCursorOnInfoPosAndGetLine(hConsole);
    std::cout << "Press SPACE to accept move\n";
    console::setCursorOnInfoPosAndGetLine(hConsole);
    std::cout << "Press ESCAPE to cancel chose\n";
    console::setCursorOnInfoPosAndGetLine(hConsole);
    std::cout << "Player on move: ";
    if (palyerOnMove == 'R') {
        SetConsoleTextAttribute(hConsole, console::redColor);
        std::cout << palyerOnMove;
        SetConsoleTextAttribute(hConsole, console::whiteColor);
    }
    else {
        std::cout << palyerOnMove;
    }
}