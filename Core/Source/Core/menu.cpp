#include "menu.h"

/**
 * Prints content of main menu
 * 
 */
void printMainMenu() {
    std::cout << "\n\n Use number keys to select option and press ENTER to accept : \n\n";
    std::cout << " \t1. New game vs computer\n";
    std::cout << " \t2. New game vs player\n";
    std::cout << " \t3. Load game\n";
    std::cout << " \t4. Show Highscores\n";
    std::cout << " \tQ. Quit game\n";
}

/**
 * Prints content of ingame menu 
 * 
 */
void printInGameMenu() {
    std::cout << "\n\n Use number keys to select option and press ENTER to accept: \n\n";
    std::cout << " \t1. Continue game\n";
    std::cout << " \t2. New game vs computer\n";
    std::cout << " \t3. New game vs player\n";
    std::cout << " \t4. Load game\n";
    std::cout << " \t5. Save Game\n";
    std::cout << " \t6. Show Highscores\n";
    std::cout << " \tQ. Quit game\n";
}


/**
 * Initializes main menu, interprets inprut from keyboard
 * 
 * \param hConsole - HANDLE console I/O interface to control console
 * \param gameLoopStarted is game loop running 
 * \return returns 0 on exit 
 */
int initMenu(const HANDLE& hConsole, bool& gameLoopStarted) {
    GameBoard gameBoard;
    char playerOnMove = 'R';
    char choice = ' ';
    bool gameWithComputer = false;
    char null;
    

    printMainMenu();

    while (true) {
        std::cin >> choice;
        if ((choice < '1' || choice > '5') && (choice != 'Q' && choice != 'q')) {
            console::setCursorOnStartInfoPos(hConsole);
            SetConsoleTextAttribute(hConsole, console::redColor);
            std::cout << "Use only specified options";
            SetConsoleTextAttribute(hConsole, console::whiteColor);
            choice = ' ';
        }

        switch (choice) {

        case '1': //New game vs c
            console::clearInfo(hConsole);

            Sleep(200);

            gameBoard.newGame(hConsole, playerOnMove);
            choseOption(gameBoard, playerOnMove, NULL, null);
            gameLoopStarted = true;
            gameWithComputer = true;
            initGameLoopWithComputer(gameBoard, hConsole, gameLoopStarted, playerOnMove);
            console::clear(hConsole);
            Sleep(150);
            initInGameMenu(gameBoard, hConsole, gameLoopStarted, playerOnMove, gameWithComputer);

            break;

        case '2': //New game vs p

            console::clearInfo(hConsole);

            Sleep(200);

            gameBoard.newGame(hConsole, playerOnMove);
            choseOption(gameBoard, playerOnMove, NULL, null);
            gameLoopStarted = true;
            gameWithComputer = false;
            initGameLoop(gameBoard, hConsole, gameLoopStarted, playerOnMove);
            console::clear(hConsole);
            Sleep(150);
            initInGameMenu(gameBoard, hConsole, gameLoopStarted, playerOnMove, gameWithComputer);
            break;

        case '3':// Load game

            if (loadGame(gameBoard, hConsole, playerOnMove, gameWithComputer)) {
                gameLoopStarted = true;
                if (gameWithComputer) {
                    initGameLoopWithComputer(gameBoard, hConsole, gameLoopStarted, playerOnMove);
                }
                else {
                    initGameLoop(gameBoard, hConsole, gameLoopStarted, playerOnMove);
                }
            }
            else {
                console::clear(hConsole);
                printMainMenu();
            }

            break;

        case '4':// Highscore


            break;
        
        case 'q':
            return 0;
            break;
        
        case 'Q':
            return 0;
            break;

        default:
            break;

        }
    }

    return 0;
}

/**
 * Initializes in game menu, interprets input from keyboard
 * 
 * \param gameBoard GameBoard object
 * \param hConsole - HANDLE console I/O interface to control console
 * \param gameLoopStarted is game loop running
 * \param playerOnMove player on move
 * \param gameWithComputer is game with computer started
 * \return returns 0 on exit
 */
int initInGameMenu(GameBoard& gameBoard, const HANDLE& hConsole, bool& gameLoopStarted, char& playerOnMove, bool& gameWithComputer) {
    bool chosedYes = false;
    bool chosedNo = false;
    char choice = ' ';
    char null;

    printInGameMenu();
    

    while (true) {
        std::cin >> choice;
        if ((choice < '1' || choice > '7') && (choice != 'Q' && choice != 'q')) {
            console::setCursorOnStartInfoPos(hConsole);
            SetConsoleTextAttribute(hConsole, console::redColor);
            std::cout << "Use only specified options";
            SetConsoleTextAttribute(hConsole, console::whiteColor);
            choice = ' ';
        }

        switch (choice) {
        case '1':
            console::clearInfo(hConsole);

            Sleep(120);

            gameLoopStarted = true;
            if (gameWithComputer) {
                initGameLoopWithComputer(gameBoard, hConsole, gameLoopStarted, playerOnMove);
            }
            else {
                initGameLoop(gameBoard, hConsole, gameLoopStarted, playerOnMove);
            }

            break;
        case '2':
            console::clearInfo(hConsole);
            console::setCursorOnStartInfoPos(hConsole);
            std::cout << "\n";
            console::setCursorOnInfoPosAndGetLine(hConsole);
            std::cout << "Are you sure you want to start a new Game ?\n";
            console::setCursorOnInfoPosAndGetLine(hConsole);
            std::cout << "\t\tY. Yes      N. No";
            Sleep(200);
            while (!chosedYes && !chosedNo) {
                switch (checkKey()) {
                case 0x59:

                    Sleep(200);
                    chosedYes = true;

                    break;
                case 0x4E:

                    Sleep(200);
                    chosedNo = true;

                    break;
                case VK_ESCAPE:

                    Sleep(200);
                    chosedNo = true;

                    break;
                case 0:
                    break;
                default:
                    Sleep(80);
                    console::setCursorOnStartInfoPos(hConsole);
                    SetConsoleTextAttribute(hConsole, console::redColor);
                    std::cout << "Use only specified keys";
                    SetConsoleTextAttribute(hConsole, console::whiteColor);
                }
            }
            console::clearInfo(hConsole);
            chosedNo = false;
            if (chosedYes) {
                chosedYes = false;
                gameBoard.newGame(hConsole, playerOnMove);
                choseOption(gameBoard, playerOnMove, NULL, null);

                gameLoopStarted = true;
                gameWithComputer = true;
                initGameLoopWithComputer(gameBoard, hConsole, gameLoopStarted, playerOnMove);

            }
            break;
        case '3':
            console::clearInfo(hConsole);
            console::setCursorOnStartInfoPos(hConsole);
            std::cout << "\n";
            console::setCursorOnInfoPosAndGetLine(hConsole);
            std::cout << "Are you sure you want to start a new Game ?\n";
            console::setCursorOnInfoPosAndGetLine(hConsole);
            std::cout << "\t\tY. Yes      N. No";
            Sleep(200);
            while (!chosedYes && !chosedNo) {
                switch (checkKey()) {
                case 0x59:

                    Sleep(200);
                    chosedYes = true;

                    break;
                case 0x4E:

                    Sleep(200);
                    chosedNo = true;

                    break;
                case VK_ESCAPE:

                    Sleep(200);
                    chosedNo = true;

                    break;
                case 0:
                    break;
                default:
                    Sleep(80);
                    console::setCursorOnStartInfoPos(hConsole);
                    SetConsoleTextAttribute(hConsole, console::redColor);
                    std::cout << "Use only specified keys";
                    SetConsoleTextAttribute(hConsole, console::whiteColor);
                }
            }
            console::clearInfo(hConsole);
            chosedNo = false;
            if (chosedYes) {

                chosedYes = false;

                gameBoard.newGame(hConsole, playerOnMove);
                choseOption(gameBoard, playerOnMove, NULL, null);

                gameLoopStarted = true;
                gameWithComputer = false;
                initGameLoop(gameBoard, hConsole, gameLoopStarted, playerOnMove);
            }
            break;
        case '4':

            if (loadGame(gameBoard, hConsole, playerOnMove, gameWithComputer)){
                gameLoopStarted = true;
                if (gameWithComputer) {
                    initGameLoopWithComputer(gameBoard, hConsole, gameLoopStarted, playerOnMove);
                }
                else {
                    initGameLoop(gameBoard, hConsole, gameLoopStarted, playerOnMove);
                }
            }
            else {
                console::clear(hConsole);
                printInGameMenu();
            }
            break;

        case '5': 
            saveGame(gameBoard, hConsole, playerOnMove, gameWithComputer);
            Sleep(100);
            console::clear(hConsole);
            printInGameMenu();
            break;
        
        case '6': //Highscore
            break;
        
        case 'q':
            Sleep(100);
            console::clear(hConsole);
            printMainMenu();
            return 0;
            break;
        
        case 'Q':
            Sleep(100);
            console::clear(hConsole);
            printMainMenu();
            return 0;
            break;
        
        default:
            break;
        }
    }

}

