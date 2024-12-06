#pragma once
#include <fstream>
#include <string>
#include "Headers.h"

//std::ostream& operator<<(std::ostream& out, const GameBoard& gameBoard);

bool saveGame(const GameBoard& gameBoard, const HANDLE& hConsole, const char playerOnTurn, const bool gameWithComputer);
bool loadGame(GameBoard& gameBoard, const HANDLE& hConsole, char& playerOnMove, bool& gameWithComputer);