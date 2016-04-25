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
	void log(char* message, MessagePrefix message_prefix = MsgPrfxInfo);
	static Logger* instance(LogLevel log_mode = LogLevelNone);

private:
	static Logger* _instance;

	Logger(LogLevel log_mode);
	~Logger();

	Logger(const Logger&);

	char* get_prefix(MessagePrefix message_prefix) const;
	char const* _log_file = "engine.log";
	LogLevel _log_mode;
	ofstream _log_file_stream;
};

