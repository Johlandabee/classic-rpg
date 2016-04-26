#include "Logger.h"
#include <time.h>
#include <iostream>
#include <sstream>

Logger* Logger::_instance = nullptr;

Logger::Logger(LogLevel log_level, string file_name) {
	_log_level = log_level;
	_log_file = file_name;
	_instance = this;
}

Logger::~Logger()
{
	if(_instance != nullptr) {
		delete _instance;
		_instance = nullptr;
	}
}

Logger* Logger::instance(LogLevel log_level /*= LogLevelNone */, char* file_name) {
	return _instance ? _instance : new Logger(log_level, file_name);
}

void Logger::log(string message, MessagePrefix message_prefix, int status)
{
	if (_log_level == LogLevelNone) {
		return;
	}

	_log_file_stream.open(_log_file, ios::app);

	if(_log_file_stream.good() && _log_file_stream.is_open()) {
		_log_file_stream << '[' << get_time() << "][" 
			<< get_prefix_str(message_prefix) << "]:\t\t\t" 
			<< message;

		if (status != 0) {
			_log_file_stream << " Status: " << status;
		}
		_log_file_stream << endl;

		_log_file_stream.close();
	} else {
		cerr << "Could not write log file";
		exit(0);
	}
}

string Logger::get_time() {
	time_t time_ = time(nullptr);
	tm tm_;
	localtime_s(&tm_, &time_);
	char buf[9];
	strftime(buf, sizeof(buf), "%X", &tm_);
	return buf;
}

string Logger::get_prefix_str(MessagePrefix message_prefix) {
	string str;
	switch (message_prefix) {
		case Logger::MsgPrfxError:
			str = "Error";
			break;
		case Logger::MsgPrfxInfo:
			str = "Info";
			break;
		case Logger::MsgPrfxWarning:
			str = "Warning";
			break;
	}
	return str;
}
