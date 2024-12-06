#include "GameBoard.h"


GameBoard::GameBoard() {

}
GameBoard::~GameBoard() {

}

size_t GameBoard::getGameBoardEndX() const {
    return gameBoardEndX;
}

size_t GameBoard::getGameBoardEndY() const {
    return gameBoardEndY;
}

size_t GameBoard::getOffsetX() const {
    return offsetX;
}
size_t GameBoard::getOffsetY() const {
    return offsetY;
}

size_t GameBoard::getChosedYindex() const {
    return chosedYIndex;
}

size_t GameBoard::getChosedXindex() const {
    return chosedXIndex;
}

Coord GameBoard::getLastActivePlayerPosXY() const {
    Coord xy{ lastChosedPlayerPosX,lastChosedPlayerPosY };
    return xy;
}

Coord GameBoard::getActivePlayerPosXY() const {
    Coord xy{ activeXIndex, activeYIndex };
    return xy;
}

char GameBoard::getGBElementValue(const size_t& x, const size_t& y) const {
    return gameBoard[y][x].value;
}

short GameBoard::getWPoints() const {
    return whitePoints;
}


/**
 * Starts new game
 * 
 * \param hConsole  - HANDLE console I/O interface to control console
 * \param playerOnMove - char player on move
 */
void GameBoard::newGame(const HANDLE& hConsole, char& playerOnMove) {
    this->initGameBoard(hConsole);
    playerOnMove = 'R';
    turnsCount = 0;
}

/**
 * Initializes game board
 * 
 * \param hConsole  - HANDLE console I/O interface to control console
 */
void GameBoard::initGameBoard(const HANDLE& hConsole) {
    char tmp[25][13] { {'.','.','.','.','.','.','.','.','.','.','.','.','.'},
                       {'.','.','.','.','.','.','.','.','.','.','.','.','.'},
                       {'.','.','.','.','.','.','.','.','.','.','.','.','.'},
                       {'.','.','.','.','.','.','.','.','.','.','.','.','.'},
                       {'.','.','.','.','.','.','R','.','.','.','.','.','.'},
                       {'.','.','.','.','.','O','.','O','.','.','.','.','.'},
                       {'.','.','.','.','O','.','O','.','O','.','.','.','.'},
                       {'.','.','.','O','.','O','.','O','.','O','.','.','.'},
                       {'.','.','W','.','O','.','O','.','O','.','W','.','.'},
                       {'.','.','.','O','.','O','.','O','.','O','.','.','.'},
                       {'.','.','O','.','O','.','.','.','O','.','O','.','.'},
                       {'.','.','.','O','.','O','.','O','.','O','.','.','.'},
                       {'.','.','O','.','O','.','O','.','O','.','O','.','.'},
                       {'.','.','.','O','.','.','.','.','.','O','.','.','.'},
                       {'.','.','O','.','O','.','O','.','O','.','O','.','.'},
                       {'.','.','.','O','.','O','.','O','.','O','.','.','.'},
                       {'.','.','R','.','O','.','O','.','O','.','R','.','.'},
                       {'.','.','.','O','.','O','.','O','.','O','.','.','.'},
                       {'.','.','.','.','O','.','O','.','O','.','.','.','.'},
                       {'.','.','.','.','.','O','.','O','.','.','.','.','.'},
                       {'.','.','.','.','.','.','W','.','.','.','.','.','.'},
                       {'.','.','.','.','.','.','.','.','.','.','.','.','.'},
                       {'.','.','.','.','.','.','.','.','.','.','.','.','.'},
                       {'.','.','.','.','.','.','.','.','.','.','.','.','.'},
                       {'.','.','.','.','.','.','.','.','.','.','.','.','.'} };


    char currentValue = ' ';
    const size_t tmpH = 25;
    const size_t tmpW = 13;
    for (size_t y = 0; y < tmpH; ++y) {
        for (size_t x = 0; x < tmpW; ++x){
            currentValue = tmp[y][x];
            gameBoard[y][x].value = currentValue;
            gameBoard[y][x].xy = {x,y};
            if (currentValue == 'R') {
                gameBoard[y][x].colorValue = console::redColor;
            }
            else if (currentValue == 'W') {
                gameBoard[y][x].colorValue = console::whiteColor;
            }
            else {
                 gameBoard[y][x].colorValue = console::grayColor;
            }
            
        }
    }
}
/**
 * Intinitializes game board from file
 * 
 * \param hConsole  - HANDLE console I/O interface to control console
 * \param gBState   - string sate of gameboard from save file
 */
void GameBoard::initGameBoardFromString(const HANDLE& hConsole, std::string gBState) {
    
    char currentValue = ' ';
    const size_t gBH = 25;
    const size_t gBW = 13;
    for (size_t y = 0; y < gBH; ++y) {
        for (size_t x = 0; x < gBW; ++x) {
            gameBoard[y][x].value = '.';
        }
    }
    
    size_t i = 0;

    for (size_t y = offsetY ; y < gameBoardEndY; ++y) {
        for (size_t x = offsetX; x < gameBoardEndX; ++x) {
            
            currentValue = gBState.at(i++);
            gameBoard[y][x].value = currentValue;
            gameBoard[y][x].xy = { x,y };
            if (currentValue == 'R') {
                gameBoard[y][x].colorValue = console::redColor;
            }
            else if (currentValue == 'W') {
                gameBoard[y][x].colorValue = console::whiteColor;
            }
            else {
                gameBoard[y][x].colorValue = console::grayColor;
            }
        }
    }
}

/**
 * Prints game Board 
 * 
 * \param hConsole  - HANDLE console I/O interface to control console
 */
void GameBoard::printGameBoard(const HANDLE& hConsole) const {
    std::cout << "\n\n ";
    for (size_t y = offsetY; y < gameBoardEndY; ++y) {
        std::cout << "\t\t  ";
        for (size_t x = offsetX; x < gameBoardEndX; ++x) {
            if (gameBoard[y][x].value != '.') {
                    SetConsoleTextAttribute(hConsole, gameBoard[y][x].colorValue);
                    if (chosedXIndex == x && chosedYIndex == y) {
                        std::cout << "\b<" << gameBoard[y][x].value << ">  ";
                    }
                    else {
                        std::cout << gameBoard[y][x].value << "   ";
                    }
            }
            else {
                std::cout << "    ";
            }
        }
        std::cout << "\n";
    }
    
    SetConsoleTextAttribute(hConsole, console::whiteColor);
    std::cout << "\t\t\t\t\t\t\t" << "Red: " << redPoints;
    std::cout << "\n\t\t\t\t\t\t\t" << "White: " << whitePoints;
    std::cout << "\n";

}

/**
 * Conuts points on game board and check if win
 * 
 */
void GameBoard::countPoints() {
    redPoints = 0;
    whitePoints = 0;
    short freePlaces = 0;
    for (size_t y = offsetY; y < gameBoardEndY; ++y) {
        for (size_t x = offsetX; x < gameBoardEndX; ++x) {
            if (gameBoard[y][x].value == 'R') {
                redPoints++;
            }
            else if (gameBoard[y][x].value == 'W') {
                whitePoints++;
            }
            else if (gameBoard[y][x].value == 'O') {
                freePlaces++;
            }
        }
        
    }
    if(whitePoints == 0){
        std::cout << "Red wins";
    }
    if (redPoints == 0) {
        std::cout << "White wins";
    }
    if (freePlaces == 0) {
        if (redPoints > whitePoints) {
            std::cout << "Red wins";
        }
        else {
            std::cout << "White wins";
        }
    }


}



/**
 * Sets game board element to given values
 * 
 * \param value - char value to set
 * \param colorValue - short color value to set
 * \param xIndex - size_t x coordinate on game board
 * \param yIndex - size_t y coordinate on game board
 * \return - GameBoard changed object 
 */

GameBoard& GameBoard::setGameBoardELement(const char value, const short colorValue, const size_t& xIndex, const size_t& yIndex) {
    this->gameBoard[yIndex][xIndex].value = value;
    this->gameBoard[yIndex][xIndex].colorValue = colorValue;
    return *this;
}

/**
 * Marks gameboard element as currently chosed
 * 
 * \param chosedXIndex - x coordinate to set
 * \param chosedYIndex - y coordinate to set
 * \return changed object 
 */
GameBoard& GameBoard::setChosedXY(const size_t& chosedXIndex, const size_t& chosedYIndex) {
    this->chosedXIndex = chosedXIndex;
    this->chosedYIndex = chosedYIndex;
    return *this;
}

/**
 * Marks currently chosed game board element as active
 * 
 * \return changed object
 */
GameBoard& GameBoard::setChosedAsActive() {
    this->activeXIndex = chosedXIndex;
    this->activeYIndex = chosedYIndex;
    return *this;
}

/**
 * Sets place from which player makes move
 * 
 * \return changed object
 */
GameBoard& GameBoard::setLastActivePlayerPosXY() {
    lastChosedPlayerPosX = chosedXIndex;
    lastChosedPlayerPosY = chosedYIndex;
    return *this;
}

/**
 * Checks hexagon pattern around given coordinates to look for given value, 
 * if value is found given lambda expression sets functionality
 * 
 * \param valueToCheck value to look
 * \param func lambda to determine functionality
 * \param indexXYtoCheckAround check hexagon pattern around coordinates
 * \return returns boolean if function succedes or not
 */
bool GameBoard::checkHexagonPattern(const char valueToCheck, std::function<bool(GBElement&)> func, const Coord & indexXYtoCheckAround) {

    const size_t x = indexXYtoCheckAround.X;
    const size_t y = indexXYtoCheckAround.Y;

    if (gameBoard[y - 1][x - 1].value == valueToCheck) {
        return func(gameBoard[y - 1][x - 1]);
    }
    if (gameBoard[y - 2][x].value == valueToCheck) {
        return func(gameBoard[y - 2][x]);
    }
    if (gameBoard[y - 1][x + 1].value == valueToCheck) {
        return func(gameBoard[y - 1][x + 1]);
    }
    if (gameBoard[y + 1][x + 1].value == valueToCheck) {
        return func(gameBoard[y + 1][x + 1]);
    }
    if (gameBoard[y + 2][x].value == valueToCheck) {
        return func(gameBoard[y + 2][x]);
    }
    if (gameBoard[y + 1][x - 1].value == valueToCheck) {
        return func(gameBoard[y + 1][x - 1]);
    }
    return false;
}

/**
* Checks hexagon pattern around given coordinates to look for given value,
* if value is found given lambda expression sets functionality.
* On doubled pattern second lambda sets the functionality
*
* \param doubles the pattern
* \param valueToCheck value to look
* \param func lambda to determine functionality
* \param indexXYtoCheckAround check hexagon pattern around coordinates
*/
void GameBoard::checkHexagonPattern(const bool doublePattern, const char valueToCheck, std::function<void(GBElement&)> func, const Coord& indexXYtoCheckAround) {

    const size_t x = indexXYtoCheckAround.X;
    const size_t y = indexXYtoCheckAround.Y;

    if (gameBoard[y - 1][x - 1].value == valueToCheck) {
        func(gameBoard[y - 1][x - 1]);
    }
    if (gameBoard[y - 2][x].value == valueToCheck) {
        func(gameBoard[y - 2][x]);
    }
    if (gameBoard[y - 1][x + 1].value == valueToCheck) {
        func(gameBoard[y - 1][x + 1]);
    }
    if (gameBoard[y + 1][x + 1].value == valueToCheck) {
        func(gameBoard[y + 1][x + 1]);
    }
    if (gameBoard[y + 2][x].value == valueToCheck) {
        func(gameBoard[y + 2][x]);
    }
    if (gameBoard[y + 1][x - 1].value == valueToCheck) {
        func(gameBoard[y + 1][x - 1]);
    }

    if (doublePattern) {
        if (gameBoard[y - 2][x - 2].value == valueToCheck) {
            func(gameBoard[y - 2][x - 2]);
        }
        if (gameBoard[y - 3][x - 1].value == valueToCheck) {
            func(gameBoard[y - 3][x - 1]);
        }
        if (gameBoard[y - 4][x].value == valueToCheck) {
            func(gameBoard[y - 4][x]);
        }
        if (gameBoard[y - 3][x + 1].value == valueToCheck) {
            func(gameBoard[y - 3][x + 1]);
        }
        if (gameBoard[y - 2][x + 2].value == valueToCheck) {
            func(gameBoard[y - 2][x + 2]);
        }
        if (gameBoard[y][x + 2].value == valueToCheck) {
            func(gameBoard[y][x + 2]);
        }
        if (gameBoard[y + 2][x + 2].value == valueToCheck) {
            func(gameBoard[y + 2][x + 2]);
        }
        if (gameBoard[y + 3][x + 1].value == valueToCheck) {
            func(gameBoard[y + 3][x + 1]);
        }
        if (gameBoard[y + 4][x].value == valueToCheck) {
            func(gameBoard[y + 4][x]);
        }
        if (gameBoard[y + 3][x - 1].value == valueToCheck) {
            func(gameBoard[y + 3][x - 1]);
        }
        if (gameBoard[y + 2][x - 2].value == valueToCheck) {
            func(gameBoard[y + 2][x - 2]);
        }
        if (gameBoard[y][x - 2].value == valueToCheck) {
            func(gameBoard[y][x - 2]);
        }
    }

}
/**
* Checks hexagon pattern around given coordinates to look for given value,
* if value is found given lambda expression sets functionality.
* On doubled pattern second lambda sets the functionality
*
* \param doubles the pattern
* \param valueToCheck value to look
* \param func lambda to determine functionality
* \param func1 lambda to determine functionality in doubled pattern
* \param indexXYtoCheckAround check hexagon pattern around coordinates
*/

void GameBoard::checkHexagonPattern(const char valueToCheck, std::function<void(GBElement&)> func, std::function<void(GBElement&)> func1, const Coord& indexXYtoCheckAround) {

    const size_t x = indexXYtoCheckAround.X;
    const size_t y = indexXYtoCheckAround.Y;

    if (gameBoard[y - 1][x - 1].value == valueToCheck) {
        func(gameBoard[y - 1][x - 1]);
    }
    if (gameBoard[y - 2][x].value == valueToCheck) {
        func(gameBoard[y - 2][x]);
    }
    if (gameBoard[y - 1][x + 1].value == valueToCheck) {
        func(gameBoard[y - 1][x + 1]);
    }
    if (gameBoard[y + 1][x + 1].value == valueToCheck) {
        func(gameBoard[y + 1][x + 1]);
    }
    if (gameBoard[y + 2][x].value == valueToCheck) {
        func(gameBoard[y + 2][x]);
    }
    if (gameBoard[y + 1][x - 1].value == valueToCheck) {
        func(gameBoard[y + 1][x - 1]);
    }


    if (gameBoard[y - 2][x - 2].value == valueToCheck) {
        func1(gameBoard[y - 2][x - 2]);
    }
    if (gameBoard[y - 3][x - 1].value == valueToCheck) {
        func1(gameBoard[y - 3][x - 1]);
    }
    if (gameBoard[y - 4][x].value == valueToCheck) {
        func1(gameBoard[y - 4][x]);
    }
    if (gameBoard[y - 3][x + 1].value == valueToCheck) {
        func1(gameBoard[y - 3][x + 1]);
    }
    if (gameBoard[y - 2][x + 2].value == valueToCheck) {
        func1(gameBoard[y - 2][x + 2]);
    }
    if (gameBoard[y][x + 2].value == valueToCheck) {
        func1(gameBoard[y][x + 2]);
    }
    if (gameBoard[y + 2][x + 2].value == valueToCheck) {
        func1(gameBoard[y + 2][x + 2]);
    }
    if (gameBoard[y + 3][x + 1].value == valueToCheck) {
        func1(gameBoard[y + 3][x + 1]);
    }
    if (gameBoard[y + 4][x].value == valueToCheck) {
        func1(gameBoard[y + 4][x]);
    }
    if (gameBoard[y + 3][x - 1].value == valueToCheck) {
        func1(gameBoard[y + 3][x - 1]);
    }
    if (gameBoard[y + 2][x - 2].value == valueToCheck) {
        func1(gameBoard[y + 2][x - 2]);
    }
    if (gameBoard[y][x - 2].value == valueToCheck) {
        func1(gameBoard[y][x - 2]);
    }

}