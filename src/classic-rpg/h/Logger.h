#pragma once
#include <fstream>

using namespace std;

class Logger {
public:
	enum LogLevel {
		LogLevelVerbose,
		LogLevelWarning,
		LogLevelInfo,
		LogLevelError,
		LogLevelNone
	};

	enum MessagePrefix {
		MsgPrfxWarning,
		MsgPrfxInfo,
		MsgPrfxError
	};

	void log(string message, MessagePrefix messagePrefix = MsgPrfxInfo, int status = 0) const;
	static Logger* instance(string fileName = "engine.log", LogLevel log_level = LogLevelNone);

private:
	static Logger* pInstance_;
	LogLevel logLevel_;

	Logger(LogLevel log_level, string fileName);
	~Logger();

	Logger(const Logger&);

	static string getTime();
	static string getPrefixStr(Logger::MessagePrefix messagePrefix);

	string logFile_;
};

