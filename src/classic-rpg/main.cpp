#include "game/Logger.h"
#include "game/Game.h"
#include "game/Config.h"
#include <sstream>

int main(int argc, char* argv[], char* envp[]) {
	auto config = Config("game.ini");
	auto logFile = config.getStringValue("sLogFile", "engine.log");

	short logLevel = config.getIntValue("iLogLevel", 0);

	Logger::instance(logFile, static_cast<Logger::LogLevel>(logLevel));
	Logger::instance()->log("Firing the oven...", Logger::MsgPrfxInfo);

	try {
		auto game = Game(config);
		game.run();
	}
	catch (exception e) {
		auto ss = stringstream();
		ss << "An error occurred within the game instance: " << e.what();

		Logger::instance()->log(ss.str(), Logger::MsgPrfxError);
	}

	return 0;
}
