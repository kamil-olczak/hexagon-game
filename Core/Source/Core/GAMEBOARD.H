#pragma once
#include <iostream>
#include <Windows.h>
#include <functional>

#include "consoleHandle.h"





struct Coord {
    size_t X;
    size_t Y;
};

struct GBElement {
    char value;
    short colorValue;
    Coord xy;
};

class GameBoard {
private:
    GBElement gameBoard[25][13];

    const size_t gameBoardEndX = 11;
    const size_t gameBoardEndY = 21;
    const size_t offsetX = 2;
    const size_t offsetY = 4;

    size_t chosedXIndex = 6;
    size_t chosedYIndex = 4;
    size_t activeXIndex = 0;
    size_t activeYIndex = 0;
    size_t lastChosedPlayerPosX = 0;
    size_t lastChosedPlayerPosY = 0;
    short redPoints = 0;
    short whitePoints = 0;
    short turnsCount = 0;
    



public:

    GameBoard();
    
    ~GameBoard();

    void newGame(const HANDLE& hConsole, char& playerOnMove);
    void initGameBoard(const HANDLE& hConsole);
    void initGameBoardFromString(const HANDLE& hConsole, std::string gBState);
    void printGameBoard(const HANDLE& hConsole) const;
    void countPoints();
    bool checkIfWin() const;

    size_t getGameBoardEndX() const;
    size_t getGameBoardEndY() const;
    size_t getOffsetX() const;
    size_t getOffsetY() const;
    size_t getChosedYindex() const;
    size_t getChosedXindex() const;
    char getGBElementValue(const size_t& x, const size_t& y) const;
    short getWPoints() const;
    
    Coord getLastActivePlayerPosXY() const;
    Coord getActivePlayerPosXY() const;

    GameBoard& setGameBoardELement(const char value, const short colorValue, const size_t& xIndex, const size_t& yIndex);
    GameBoard& setChosedXY(const size_t& aXIndex, const size_t& aYIndex);
    GameBoard& setChosedAsActive();
    GameBoard& setLastActivePlayerPosXY();

    void checkHexagonPattern(const bool doublePattern, const char valueToCheck, std::function<void(GBElement&)> func, const Coord& indexXYtoCheckAround);
    void checkHexagonPattern(const char valueToCheck, std::function<void(GBElement&)> func, std::function<void(GBElement&)> func1, const Coord& indexXYtoCheckAround);

    bool checkHexagonPattern(const char valueToCheck, std::function<bool(GBElement&)> func, const Coord& indexXYtoCheckAround);


    template <typename T>
    bool checkGameBoard(const T value, const size_t& x, const size_t& y) const {
        return gameBoard[y][x].value == value || gameBoard[y][x].colorValue == value;
    }
    
    template <typename T>
    bool checkGameBoard(const T value, const T value1 , const size_t& x, const size_t& y) const {
        return (gameBoard[y][x].value == value || gameBoard[y][x].colorValue == value) || ((gameBoard[y][x].value == value1 || gameBoard[y][x].colorValue == value1));
    }


};