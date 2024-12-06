#include "onMove.h"

/**
 * Confirms selection of place on game board
 * 
 * \param gameBoard - GameBoard object
 * \param hConsole  - HANDLE console I/O interface to control console
 * \param playerOnMove - player currently on move
 * \param highlightAvailable - is available moves highlighted 
 */
void confirmSelect(GameBoard& gameBoard, const HANDLE& hConsole, char& playerOnMove, bool& highlightAvailable) {
    
    if (!highlightAvailable) {

        gameBoard.setChosedAsActive();
        gameBoard.setLastActivePlayerPosXY();

        const Coord currentlyActiveXY = gameBoard.getActivePlayerPosXY();

        short countAvailable = 0;

        gameBoard.checkHexagonPattern('O',
            [&countAvailable](GBElement& gBElement) -> void {
                gBElement.colorValue = console::greenColor;
                countAvailable++;
            },
            [&countAvailable](GBElement& gBElement) -> void {
                gBElement.colorValue = console::cyanColor;
                countAvailable++;
            },
            currentlyActiveXY);

        if (countAvailable == 0) {
            console::clearInfoFirstLine(hConsole);
            console::setCursorOnStartInfoPos(hConsole);
            SetConsoleTextAttribute(hConsole, console::redColor);
            std::cout << "Unavailable move! Chose different place";
            SetConsoleTextAttribute(hConsole, console::whiteColor);
        }
        else {
            highlightAvailable = true;
            console::clearInfo(hConsole);
            printInfoOnAccept(hConsole, playerOnMove);

            char null;
            if (!choseOption(gameBoard, console::greenColor, NULL, null)) {
                choseOption(gameBoard, console::cyanColor, NULL, null);
            }
        }

        

    }
    else {
        const Coord previouslyActiveXY = gameBoard.getLastActivePlayerPosXY();

        gameBoard.setChosedAsActive();
        populatePlayer(gameBoard, playerOnMove, previouslyActiveXY);
        gameBoard.checkHexagonPattern('O',
            [](GBElement& gBElement) -> void {
                gBElement.colorValue = console::grayColor;
            },
            [](GBElement& gBElement) -> void {
                gBElement.colorValue = console::grayColor;
            },
            previouslyActiveXY);

        highlightAvailable = false;
       
        
        if (playerOnMove == 'R') {
            playerOnMove = 'W';
        }
        else {
            playerOnMove = 'R';
        }

        console::clearInfo(hConsole);
        printInfo(hConsole, playerOnMove);

        char null;
        choseOption(gameBoard, playerOnMove, NULL, null);
        gameBoard.countPoints();
        console::clearScoreBoard(hConsole);

    }
}

/**
 * Cancels selection of place on gameboard
 * 
 * \param gameBoard - GameBoard object
 * \param hConsole  - HANDLE console I/O interface to control console
 * \param playerOnMove - player currently on move
 * \param highlightAvailable - is available moves highlighted
 */
void cancelSelect(GameBoard& gameBoard, const HANDLE& hConsole, const char playerOnMove, bool& highligthedAvalable) {
    Coord currentlyActiveXY = gameBoard.getActivePlayerPosXY();

    gameBoard.checkHexagonPattern(true, 'O',
        [](GBElement& gBElement) -> void {
            gBElement.colorValue = console::grayColor;
        },
        currentlyActiveXY);
    
    highligthedAvalable = false;
    console::clearInfo(hConsole);
    printInfo(hConsole, playerOnMove);
    
    char null;
    choseOption(gameBoard, playerOnMove, NULL, null);
}
    
/**
 * Copy player or move it, depending on chosed place
 * 
 * \param gameBoard GameBoard object
 * \param playerOnMove player on move
 * \param previouslyActiveXY position from which copy player or move
 */
void populatePlayer(GameBoard& gameBoard, const char playerOnMove, const Coord& previouslyActiveXY) {
    const Coord currentlyActiveXY = gameBoard.getActivePlayerPosXY();

    if (gameBoard.checkGameBoard(console::cyanColor, currentlyActiveXY.X, currentlyActiveXY.Y)) {
        gameBoard.setGameBoardELement('O', console::grayColor, previouslyActiveXY.X, previouslyActiveXY.Y);
        if (playerOnMove == 'R') {
            gameBoard.setGameBoardELement(playerOnMove, console::redColor, currentlyActiveXY.X, currentlyActiveXY.Y);
        } 
        else {
            gameBoard.setGameBoardELement(playerOnMove, console::whiteColor, currentlyActiveXY.X, currentlyActiveXY.Y);
        }

        if (playerOnMove == 'R') {
            gameBoard.checkHexagonPattern(false, 'W',
                [&playerOnMove](GBElement& gBElement) -> void {
                    gBElement.value = playerOnMove;
                    gBElement.colorValue = console::redColor;
                },
                currentlyActiveXY);
        }
        else {
            gameBoard.checkHexagonPattern(false, 'R',
                [&playerOnMove](GBElement& gBElement) -> void {
                    gBElement.value = playerOnMove;
                    gBElement.colorValue = console::whiteColor;
                },
                currentlyActiveXY);
        }
    }
    else {
        if (playerOnMove == 'R') {
            gameBoard.setGameBoardELement(playerOnMove, console::redColor, currentlyActiveXY.X, currentlyActiveXY.Y);
        }
        else {
            gameBoard.setGameBoardELement(playerOnMove, console::whiteColor, currentlyActiveXY.X, currentlyActiveXY.Y);
        }

        if (playerOnMove == 'R') {
            gameBoard.checkHexagonPattern(false, 'W',
                [&playerOnMove](GBElement& gBElement) -> void {
                    gBElement.value = playerOnMove;
                    gBElement.colorValue = console::redColor;
                },
                currentlyActiveXY);
        } 
        else {
            gameBoard.checkHexagonPattern(false, 'R',
                [&playerOnMove](GBElement& gBElement) -> void {
                    gBElement.value = playerOnMove;
                    gBElement.colorValue = console::whiteColor;
                },
                currentlyActiveXY);
        }
    }

}



