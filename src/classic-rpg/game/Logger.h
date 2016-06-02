#pragma once
#include <fstream>

using namespace std;

class Logger {
public:
	enum LogLevel {
		LogLevelNone = 0,
		LogLevelError = 1,
		LogLevelInfo = 2,
		LogLevelWarning = 3,
		LogLevelVerbose = 4
	};

	enum MessagePrefix {
		MsgPrfxError,
		MsgPrfxInfo,
		MsgPrfxWarning
	};

	void log(string message, MessagePrefix messagePrefix = MsgPrfxInfo, int status = 0) const;
	static Logger* instance(string fileName = "engine.log", LogLevel logLevel = LogLevelNone);

private:
	Logger(const Logger&);
	Logger(LogLevel log_level, string fileName);

	LogLevel logLevel;

	static Logger* pInstance;
	static string getPrefixStr(MessagePrefix messagePrefix);
	static string getTime();

	string lastMessage;
	string logFile;
};
