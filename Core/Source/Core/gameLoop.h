#pragma once
#include "Headers.h"
#include "GameBoard.h"

void initGameLoop(GameBoard& gameBoard, const HANDLE& hConsole, bool& startGameLoop, char& playerOnMove);
void initGameLoopWithComputer(GameBoard& gameBoard, const HANDLE& hConsole, bool& gameLoopStarted, char& playerOnMove);
void printInfo(const HANDLE& hConsole, const char palyerOnMove);
void printInfoOnAccept(const HANDLE& hConsole, const char palyerOnMove);