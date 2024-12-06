#include "loadSaveGame.h"

/**
 * Saves game progress to a file
 * 
 * \param gameBoard - GameBoard object
 * \param hConsole  - HANDLE console I/O interface to control console
 * \param playerOnTurn - player on turn
 * \param gameWithComputer - is game with computer active
 * \return if function saves game returns true
 */
bool saveGame(const GameBoard& gameBoard, const HANDLE& hConsole, const char playerOnTurn, const bool gameWithComputer) {
	
	std::ofstream out;
	std::string fileName = "";


	console::clear(hConsole);
	std::cout << "Type Q to quit \n";
	std::cout << "Gamesave name: \n";


	std::cin >> fileName;

	if (fileName.at(0) == 'q' || fileName.at(0) == 'Q') {
		return false;
	}

	std::ifstream inFile;
	inFile.open(fileName, std::ios::in);
	

	if (inFile.good()) {
		bool choiceLoop = true;
		while (choiceLoop) {
			console::setCursorOnStartInfoPos(hConsole);
			std::cout << "\n";
			console::setCursorOnInfoPosAndGetLine(hConsole);
			std::cout << "Savegame file exists, overwrite?\n";
			console::setCursorOnInfoPosAndGetLine(hConsole);
			std::cout << "\t\t Y. Yes  N. No\n";
			char choice = ' ';
			std::cin >> choice;
			if (choice == 'N' || choice == 'n') {
				out.close();
				inFile.close();
				return false;
			}
			else if (choice != 'Y' && choice != 'y') {
				console::setCursorOnStartInfoPos(hConsole);
				SetConsoleTextAttribute(hConsole, console::redColor);
				std::cout << "Use only specified options";
				SetConsoleTextAttribute(hConsole, console::whiteColor);
				choice = ' ';
			}
			else {
				choiceLoop = false;
			}
			
		}
	}

	out.open(fileName, std::ios::out);

	const size_t gB_EndX = gameBoard.getGameBoardEndX();
	const size_t gB_EndY = gameBoard.getGameBoardEndY();
	const size_t gB_BeginX = gameBoard.getOffsetX();
	const size_t gB_BeginY = gameBoard.getOffsetY();


	for (size_t y = gB_BeginY; y < gB_EndY; ++y) {
		for (size_t x = gB_BeginX; x < gB_EndX; ++x) {
			out << gameBoard.getGBElementValue(x, y);
		}
	}
	out << "\n";
	out << gameWithComputer;
	out << "\n";
	out << playerOnTurn;
	
	out.close();
	inFile.close();
	return true;
}

/**
 * Loads game state from a file
 * 
 * \param gameBoard - GameBoard object
 * \param hConsole  - HANDLE console I/O interface to control console
 * \param playerOnMove - player on turn
 * \param gameWithComputer - is game with computer active
 * \return if function loads game returns true
 */
bool loadGame(GameBoard& gameBoard, const HANDLE& hConsole, char& playerOnMove, bool& gameWithComputer) {

	std::ifstream inFile;
	std::string fileName = "";
	bool inLoop = true;

	console::clear(hConsole);
	std::cout << "Type Q to quit \n";
	std::cout << "Gamesave name: \n";
	

	while (inLoop) {
		fileName = "";
		std::cin >> fileName;
		if (fileName.at(0) == 'q' || fileName.at(0) == 'Q') {
			return false;
		}
		inFile.open(fileName, std::ios::in);

		if (!inFile.good()) {
			console::setCursorOnStartInfoPos(hConsole);
			std::cout << "\n";
			console::setCursorOnInfoPosAndGetLine(hConsole);
			std::cout << "SaveGame don't exist\n";
			//inFile.close();
		}
		else {
			inLoop = false;
		}
	}
	
	std::string inLine = "";
	std::getline(inFile, inLine);
	gameBoard.initGameBoardFromString(hConsole, inLine);

	std::getline(inFile, inLine);
	
	if (inLine.at(0) == '0') {
		gameWithComputer = false;
	}
	else {
		gameWithComputer = true;
	}

	std::getline(inFile, inLine);
	playerOnMove = inLine.at(0);

	char null;
	choseOption(gameBoard, playerOnMove, NULL, null);

	inFile.close();
	return true;
}