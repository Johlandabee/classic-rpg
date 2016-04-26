#pragma once
#include <fstream>
#include <string>

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
	void log(string message, MessagePrefix message_prefix = MsgPrfxInfo,  int status = 0);
	static Logger* instance(LogLevel log_level=Logger::LogLevelNone, char* file_name="engine.log");

private:
	static Logger* _instance;
	LogLevel _log_level;

	Logger(LogLevel log_level, string file_name);
	~Logger();

	Logger(const Logger&);

	string get_time();
	string get_prefix_str(Logger::MessagePrefix message_prefix);
	string _log_file;
	ofstream _log_file_stream;
};

