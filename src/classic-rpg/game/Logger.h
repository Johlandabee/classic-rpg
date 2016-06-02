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
	static Logger* pInstance;
	LogLevel logLevel;
	string lastMessage;

	Logger(LogLevel log_level, string fileName);
	~Logger();

	Logger(const Logger&);

	static string getTime();
	static string getPrefixStr(Logger::MessagePrefix messagePrefix);

	string logFile;
};
