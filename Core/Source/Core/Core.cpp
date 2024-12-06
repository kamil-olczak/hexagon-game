#include "Headers.h"
#include "Core.h"
/**
 * Starts main Thread
 *
 * \return
 */
namespace Core {

	int launch() {

		const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		console::setConsoleFont(hConsole);
		console::resetCursor(hConsole);

		bool gameLoopStarted = false;

		return initMenu(hConsole, gameLoopStarted);

	}
}