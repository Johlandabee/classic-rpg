#include "h/Logger.h"
#include "h/Game.h"
#include "h/Config.h"

int main(int argc, char* argv[], char* envp[]) {

	auto pConfig = Config("base.ini");
	auto logFile = pConfig.getStringValue("sLogFile", "engine.log");
	
	auto pLogger = Logger::instance(logFile, Logger::LogLevelVerbose);
	
	pLogger->log("Firing the oven...", Logger::MsgPrfxInfo);

	try {
		auto game = Game();
		game.run();
	} catch (exception e) {
		pLogger->log("An error occurred withing the Game() instance", Logger::MsgPrfxError);
	}

	return 0;
}

