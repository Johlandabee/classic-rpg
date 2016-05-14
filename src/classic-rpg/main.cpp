#include "h/Logger.h"
#include "h/Game.h"
#include "h/List.h"

using namespace common;

int main(int argc, char* argv[], char* envp[]) {
	// ToDo: Load log level from config file
	auto logger = Logger::instance(Logger::LogLevelVerbose);
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

