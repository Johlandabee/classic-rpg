#pragma once
#include <fstream>

using namespace std;

class Logger
{
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
	void log(string message, MessagePrefix messagePrefix = MsgPrfxInfo,  int status = 0);
	static Logger* instance(LogLevel log_level=Logger::LogLevelNone, char* fileName="engine.log");

private:
	static Logger* pInstance_;
	LogLevel logLevel_;

	Logger(LogLevel log_level, string fileName);
	~Logger();

	Logger(const Logger&);

	string getTime() const;
	string getPrefixStr(Logger::MessagePrefix messagePrefix) const;

	string logFile_;
	ofstream logFileStream_;
};

