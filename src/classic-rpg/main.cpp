#include "h/Logger.h"
#include "h/Game.h"
#include "h/TList.h"

int main(int argc, char* argv[], char* envp[]) {
	// ToDo: Load log level from config file
	auto logger = Logger::instance(Logger::LogLevelVerbose);

	auto intlist = TList<int>();

	for (auto i = 0; i < 100; i++) {
		intlist.add(i);
	}

	auto j = intlist[10];

	auto pGame = new Game();
	// Allocation check
	if (pGame) {
		// Enter main loop
		logger->log("Starting up...");
		pGame->run();
	}
	else {
		logger->log("Could not create Game() instance. Allocation error.", Logger::MsgPrfxError);
	}

	delete pGame , logger;
	return 0;
}

