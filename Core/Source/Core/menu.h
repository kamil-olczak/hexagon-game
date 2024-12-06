#pragma once
#include "Headers.h"
#include "loadSaveGame.h"


void printMainMenu();
void printInGameMenu();
int initMenu(const HANDLE& hConsole, bool& gameLoopStarted);
int initInGameMenu(GameBoard& gameBoard, const HANDLE& hConsole, bool& gameLoopStarted, char& playerOnMove, bool& gameWithComputer);

