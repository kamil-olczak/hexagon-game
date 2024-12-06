#pragma once
#include "Headers.h"


void confirmSelect(GameBoard& gameBoard, const HANDLE& hConsole, char& playerOnMove, bool& higlightAvailable);
void cancelSelect(GameBoard& gameBoard, const HANDLE& hConsole, const char playerOnMove, bool& highligthedAvalable);
void populatePlayer(GameBoard& gameBoard, const char playerOnMove, const Coord& lastChosedPlayerPosXY);



/**
 * Looks for value in row from given center in game board
 * 
 * \param gameBoard   GameBoard object
 * \param valueToLook value to look in gameBoard
 * \param startX      starting position of X coordinate
 * \param gB_EndX X   coordinate of end of the gameboard
 * \param gB_BeginX   X coordinate of beggin of the gameboard
 * \param cLimit      limiter on how much places to check from center in row
 * \param y           Y coordinate to determine row
 * \param lastChose   last chosed place on the left or on the right to determine in which direction look first
 * \return            returns true if function finds given value false if not
 */
template<typename T1>
bool checkRowFromCenterToLimit(GameBoard& gameBoard, const T1 valueToLook, const size_t& startX, const size_t& gB_EndX, const size_t& gB_BeginX, const size_t& cLimit, const size_t& y, char& lastChose) {
    if (lastChose != 'R') {
        for (size_t counterX = 0, x = startX; counterX <= cLimit && x <= gB_EndX; ++counterX, ++x) {
            if (gameBoard.checkGameBoard(valueToLook, x, y)) {
                gameBoard.setChosedXY(x, y);
                lastChose = 'R';
                return true;
            }
        }
        for (size_t counterX = 1, x = startX - 1; counterX <= cLimit && x >= gB_BeginX; ++counterX, --x) {
            if (gameBoard.checkGameBoard(valueToLook, x, y)) {
                gameBoard.setChosedXY(x, y);
                lastChose = 'L';
                return true;
            }
        }
    }
    else {
        for (size_t counterX = 1, x = startX - 1; counterX <= cLimit && x >= gB_BeginX; ++counterX, --x) {
            if (gameBoard.checkGameBoard(valueToLook, x, y)) {
                gameBoard.setChosedXY(x, y);
                lastChose = 'L';
                return true;
            }
        }
        for (size_t counterX = 0, x = startX; counterX <= cLimit && x <= gB_EndX; ++counterX, ++x) {
            if (gameBoard.checkGameBoard(valueToLook, x, y)) {
                gameBoard.setChosedXY(x, y);
                lastChose = 'R';
                return true;
            }
        }
    }
    return false;
}


/**
 * Looks for value in column from given center in game board
 * 
 * \param gameBoard   GameBoard object     
 * \param valueToLook value to look in gameBoard
 * \param startY      starting position of Y coordinate
 * \param gB_EndY     coordinate of end of the gameboard
 * \param gB_BeginY   Y coordinate of begin of the gameboard
 * \param cLimit      limiter on how much places to check from center in column
 * \param x           X coordinate to determine column
 * \param lastChose   last chosed place on the left or on the right to determine in which direction look first
 * \return            returns true if function finds given value false if not
 */
template<typename T1>
bool checkColumnFromCenterToLimit(GameBoard& gameBoard, const T1 valueToLook, const size_t& startY, const size_t& gB_EndY, const size_t& gB_BeginY, const size_t& cLimit, const size_t& x, char& lastChose) {
    if (lastChose != 'D') {
        for (size_t counterY = 0, y = startY; counterY <= cLimit && y <= gB_EndY; ++counterY, ++y) {
            if (gameBoard.checkGameBoard(valueToLook, x, y)) {
                gameBoard.setChosedXY(x, y);
                lastChose = 'D';
                return true;
            }
        }
        for (size_t counterY = 1, y = startY - 1; counterY <= cLimit && y >= gB_BeginY; ++counterY, --y) {
            if (gameBoard.checkGameBoard(valueToLook, x, y)) {
                gameBoard.setChosedXY(x, y);
                lastChose = 'U';
                return true;
            }
        }
    }
    else {
        for (size_t counterY = 1, y = startY - 1; counterY <= cLimit && y >= gB_BeginY; ++counterY, --y) {
            if (gameBoard.checkGameBoard(valueToLook, x, y)) {
                gameBoard.setChosedXY(x, y);
                lastChose = 'U';
                return true;
            }
        }
        for (size_t counterY = 0, y = startY; counterY <= cLimit && y <= gB_EndY; ++counterY, ++y) {
            if (gameBoard.checkGameBoard(valueToLook, x, y)) {
                gameBoard.setChosedXY(x, y);
                lastChose = 'D';
                return true;
            }
        }
    }
    return false;
}

/**
 * Looks for value in row from given center in game board
 *
 * \param gameBoard    GameBoard object
 * \param valueToLook  first value to look in gameBoard
 * \param valueToLook1 second value to look in gameBoard
 * \param startX       starting position of X coordinate
 * \param gB_EndX X    coordinate of end of the gameboard
 * \param gB_BeginX    X coordinate of beggin of the gameboard
 * \param cLimit       limiter on how much places to check from center in row
 * \param y            Y coordinate to determine row
 * \param lastChose    last chosed place on the left or on the right to determine in which direction look first
 * \return             returns true if function finds given value false if not
 */
template<typename T1>
bool checkRowFromCenterToLimit(GameBoard& gameBoard, const T1 valueToLook, const T1 valueToLook1, const size_t& startX, const size_t& gB_EndX, const size_t& gB_BeginX, const size_t& cLimit, const size_t& y, char& lastChose) {
    if (lastChose != 'R') {
        for (size_t counterX = 0, x = startX; counterX <= cLimit && x <= gB_EndX; ++counterX, ++x) {
            if (gameBoard.checkGameBoard(valueToLook, valueToLook1, x, y)) {
                gameBoard.setChosedXY(x, y);
                lastChose = 'R';
                return true;
            }
        }
        for (size_t counterX = 1, x = startX - 1; counterX <= cLimit && x >= gB_BeginX; ++counterX, --x) {
            if (gameBoard.checkGameBoard(valueToLook, valueToLook1, x, y)) {
                gameBoard.setChosedXY(x, y);
                lastChose = 'L';
                return true;
            }
        }
    }
    else {
        for (size_t counterX = 1, x = startX - 1; counterX <= cLimit && x >= gB_BeginX; ++counterX, --x) {
            if (gameBoard.checkGameBoard(valueToLook, valueToLook1, x, y)) {
                gameBoard.setChosedXY(x, y);
                lastChose = 'L';
                return true;
            }
        }
        for (size_t counterX = 0, x = startX; counterX <= cLimit && x <= gB_EndX; ++counterX, ++x) {
            if (gameBoard.checkGameBoard(valueToLook, valueToLook1, x, y)) {
                gameBoard.setChosedXY(x, y);
                lastChose = 'R';
                return true;
            }
        }
    }
    return false;
}

/**
 * Looks for value in column from given center in game board
 *
 * \param gameBoard    GameBoard object
 * \param valueToLook  value to look in gameBoard
 * \param valueToLook1 value to look in gameBoard
 * \param startY       starting position of Y coordinate
 * \param gB_EndY      coordinate of end of the gameboard
 * \param gB_BeginY    Y coordinate of begin of the gameboard
 * \param cLimit       limiter on how much places to check from center in column
 * \param x            X coordinate to determine column
 * \param lastChose    last chosed place on the left or on the right to determine in which direction look first
 * \return             returns true if function finds given value false if not
 */
template<typename T1>
bool checkColumnFromCenterToLimit(GameBoard& gameBoard, const T1 valueToLook, const T1 valueToLook1, const size_t& startY, const size_t& gB_EndY, const size_t& gB_BeginY, const size_t& cLimit, const size_t& x, char& lastChose) {
    if (lastChose != 'D') {
        for (size_t counterY = 0, y = startY; counterY <= cLimit && y <= gB_EndY; ++counterY, ++y) {
            if (gameBoard.checkGameBoard(valueToLook, valueToLook1, x, y)) {
                gameBoard.setChosedXY(x, y);
                lastChose = 'D';
                return true;
            }
        }
        for (size_t counterY = 1, y = startY - 1; counterY <= cLimit && y >= gB_BeginY; ++counterY, --y) {
            if (gameBoard.checkGameBoard(valueToLook, valueToLook1, x, y)) {
                gameBoard.setChosedXY(x, y);
                lastChose = 'U';
                return true;
            }
        }
    }
    else {
        for (size_t counterY = 1, y = startY - 1; counterY <= cLimit && y >= gB_BeginY; ++counterY, --y) {
            if (gameBoard.checkGameBoard(valueToLook, valueToLook1, x, y)) {
                gameBoard.setChosedXY(x, y);
                lastChose = 'U';
                return true;
            }
        }
        for (size_t counterY = 0, y = startY; counterY <= cLimit && y <= gB_EndY; ++counterY, ++y) {
            if (gameBoard.checkGameBoard(valueToLook, valueToLook1, x, y)) {
                gameBoard.setChosedXY(x, y);
                lastChose = 'D';
                return true;
            }
        }
    }
    return false;
}

/**
 * Finds given value in gameborad in given direction depending on pressed key.
 * Pattern to search in game board is a triangle which base is as long as a destination from starting
 * element to border of the gameboard
 * 
 * \param gameBoard   GameBoard object
 * \param valueToLook value to look in game board, color or char value of element
 * \param keyPressed  which key is pressed
 * \param lastChose   last chosed place on the left or on the right to determine in which direction look first
 * \return            returns true if function finds given value false if not
 */
template<typename T1, typename T2>
bool choseOption(GameBoard& gameBoard, const T1 valueToLook, const T2 keyPressed, char& lastChose) {
    const size_t gB_EndX = gameBoard.getGameBoardEndX();
    const size_t gB_EndY = gameBoard.getGameBoardEndY();
    const size_t gB_BeginX = gameBoard.getOffsetX();
    const size_t gB_BeginY = gameBoard.getOffsetY();
    const size_t startY = gameBoard.getChosedYindex();
    const size_t startX = gameBoard.getChosedXindex();

    switch(keyPressed){
    case VK_UP: {
        
        const size_t limiter = startY - gB_BeginY;

        for (size_t cLimit = 1, y = startY - 1; cLimit <= limiter; ++cLimit, --y) {
            if (checkRowFromCenterToLimit(gameBoard, valueToLook, startX, gB_EndX, gB_BeginX, cLimit, y, lastChose)) {
                return true;
            }
        }
        break; 
    }
    case VK_DOWN: {
        
        const size_t limiter = gB_EndY - startY;

        for (size_t cLimit = 1, y = startY + 1; cLimit <= limiter; ++cLimit, ++y) {
            if (checkRowFromCenterToLimit(gameBoard, valueToLook, startX, gB_EndX, gB_BeginX, cLimit, y, lastChose)) {
                return true;
            }
        }
        break;
    }
    case VK_LEFT: {
        
        const size_t limiter = startX - gB_BeginX;

        for (size_t cLimit = 1, x = startX - 1; cLimit <= limiter; ++cLimit, --x) {
            if (checkColumnFromCenterToLimit(gameBoard, valueToLook, startY, gB_EndY, gB_BeginY, cLimit, x, lastChose)) {
                return true;
            }
        }
        break;
    }
    case VK_RIGHT: {
        
        const size_t limiter = gB_EndX - startX;

        for (size_t cLimit = 1, x = startX + 1; cLimit <= limiter; ++cLimit, ++x) {
            if (checkColumnFromCenterToLimit(gameBoard, valueToLook, startY, gB_EndY, gB_BeginY, cLimit, x, lastChose)) {
                return true;
            }
        }
        break;
    }
    default:
        for (size_t y = gB_BeginY; y < gB_EndY; ++y) {
            for (size_t x = gB_BeginX; x < gB_EndX; ++x) {
                if (gameBoard.checkGameBoard(valueToLook, x, y)) {
                    gameBoard.setChosedXY(x, y);
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * Finds two given value in gameborad in given direction depending on pressed key.
 * Pattern to search in game board is a triangle which base is as long as a destination from starting
 * element to border of the gameboard
 *
 * \param gameBoard    GameBoard object
 * \param valueToLook  first value to look in game board, color or char value of element
 * \param valueToLook1 second value to look in game board, color or char value of element
 * \param keyPressed   which key is pressed
 * \param lastChose    last chosed place on the left or on the right to determine in which direction look first
 * \return             returns true if function finds given value false if not
 */
template<typename T1, typename T2>
bool choseOption(GameBoard& gameBoard, const T1 valueToLook, const T1 valueToLook1, const T2 keyPressed, char& lastChose) {
    const size_t gB_EndX = gameBoard.getGameBoardEndX();
    const size_t gB_EndY = gameBoard.getGameBoardEndY();
    const size_t gB_BeginX = gameBoard.getOffsetX();
    const size_t gB_BeginY = gameBoard.getOffsetY();
    const size_t startY = gameBoard.getChosedYindex();
    const size_t startX = gameBoard.getChosedXindex();

    switch (keyPressed) {
    case VK_UP: {

        const size_t limiter = startY - gB_BeginY;

        for (size_t cLimit = 1, y = startY - 1; cLimit <= limiter; ++cLimit, --y) {
            if (checkRowFromCenterToLimit(gameBoard, valueToLook, valueToLook1, startX, gB_EndX, gB_BeginX, cLimit, y, lastChose)) {
                return true;
            }
        }
        break;
    }
    case VK_DOWN: {

        const size_t limiter = gB_EndY - startY;

        for (size_t cLimit = 1, y = startY + 1; cLimit <= limiter; ++cLimit, ++y) {
            if (checkRowFromCenterToLimit(gameBoard, valueToLook, valueToLook1, startX, gB_EndX, gB_BeginX, cLimit, y, lastChose)) {
                return true;
            }
        }
        break;
    }
    case VK_LEFT: {

        const size_t limiter = startX - gB_BeginX;

        for (size_t cLimit = 1, x = startX - 1; cLimit <= limiter; ++cLimit, --x) {
            if (checkColumnFromCenterToLimit(gameBoard, valueToLook, valueToLook1, startY, gB_EndY, gB_BeginY, cLimit, x, lastChose)) {
                return true;
            }
        }
        break;
    }
    case VK_RIGHT: {

        const size_t limiter = gB_EndX - startX;

        for (size_t cLimit = 1, x = startX + 1; cLimit <= limiter; ++cLimit, ++x) {
            if (checkColumnFromCenterToLimit(gameBoard, valueToLook, valueToLook1, startY, gB_EndY, gB_BeginY, cLimit, x, lastChose)) {
                return true;
            }
        }
        break;
    }
    default:
        break;
    }
    return false;
}


