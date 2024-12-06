#include "computerPlayer.h"
#include <vector>
#include <algorithm> 

/**
 * Controls computer player, finds best move and sets it
 * 
 * \param gameBoard - GameBoard object
 * \param playerOnMove - char player currently on move
 * \param hConsole  - HANDLE console I/O interface to control console
 */
void computerOnMove(GameBoard& gameBoard, char& playerOnMove, const HANDLE& hConsole) {
    struct PlaceOnGB {
        Coord xy;
        Coord fromXY;
        short pointsToGet;
    };

    const size_t gB_EndX = gameBoard.getGameBoardEndX();
    const size_t gB_EndY = gameBoard.getGameBoardEndY();
    const size_t gB_BeginX = gameBoard.getOffsetX();
    const size_t gB_BeginY = gameBoard.getOffsetY();


    const char playerOnHold = 'R';
    Coord xy{ 0,0 };
    PlaceOnGB placeOnGBToRate = { 0,0,0 };
    std::vector <PlaceOnGB> placesToRate;


    for (size_t y = gB_BeginY; y < gB_EndY; ++y) {
        for (size_t x = gB_BeginX; x < gB_EndX; ++x) {
            if (gameBoard.checkGameBoard(playerOnMove, x, y)) {
                xy = { x, y };

                gameBoard.checkHexagonPattern(
                    true,
                    'O',
                    [&gameBoard, &placeOnGBToRate, &placesToRate, &xy](GBElement& first_gBElement) mutable -> void {
                        gameBoard.checkHexagonPattern(
                            false,
                            playerOnHold,
                            [&first_gBElement, &placeOnGBToRate](GBElement& gBElement) mutable -> void {
                                placeOnGBToRate.pointsToGet++;
                            },
                            first_gBElement.xy);

                placeOnGBToRate.xy = first_gBElement.xy;
                placeOnGBToRate.fromXY = xy;
                placesToRate.push_back(placeOnGBToRate);
                placeOnGBToRate = { 0,0,0 };
                    },
                    xy);

            }
        }
    }



    auto compare = [](PlaceOnGB a, PlaceOnGB b) -> bool {
        return a.pointsToGet > b.pointsToGet;
    };

    std::sort(placesToRate.begin(), placesToRate.end(), compare);


    gameBoard.setChosedXY(placesToRate[0].fromXY.X, placesToRate[0].fromXY.Y);

    gameBoard.setGameBoardELement('O', console::whiteColor, placesToRate[0].xy.X, placesToRate[0].xy.Y);

    console::resetCursor(hConsole);
    gameBoard.printGameBoard(hConsole);
    Sleep(1000);

    gameBoard.setChosedAsActive();
    gameBoard.setLastActivePlayerPosXY();
    const Coord currentlyActiveXY = gameBoard.getActivePlayerPosXY();
    gameBoard.checkHexagonPattern('O',
        [](GBElement& gBElement) -> void {
            gBElement.colorValue = console::greenColor;
        },
        [](GBElement& gBElement) -> void {
            gBElement.colorValue = console::cyanColor;
        },
            currentlyActiveXY);

    gameBoard.setChosedXY(placesToRate[0].xy.X, placesToRate[0].xy.Y);
    gameBoard.setChosedAsActive();
    const Coord previouslyActiveXY = gameBoard.getLastActivePlayerPosXY();

    populatePlayer(gameBoard, playerOnMove, previouslyActiveXY);

    gameBoard.checkHexagonPattern('O',
        [](GBElement& gBElement) -> void {
            gBElement.colorValue = console::grayColor;
        },
        [](GBElement& gBElement) -> void {
            gBElement.colorValue = console::grayColor;
        },
            previouslyActiveXY);

    playerOnMove = 'R';

    char null;
    choseOption(gameBoard, playerOnMove, NULL, null);
    console::resetCursor(hConsole);
    gameBoard.countPoints();
    console::clearScoreBoard(hConsole);
    gameBoard.printGameBoard(hConsole);
    Sleep(100);
      

}

