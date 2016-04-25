#include "Logger.h"
#include <time.h>
#include <iostream>

Logger* Logger::_instance = nullptr;

Logger::Logger(LogLevel log_mode) {
	_log_mode = log_mode;
}

Logger::~Logger()
{
	if(_instance != nullptr) {
		delete _instance;
		_instance = nullptr;
	}
}


Logger* Logger::instance(LogLevel log_mode) {
	return _instance ? _instance : new Logger(log_mode);
}

void Logger::log(char* message, MessagePrefix message_prefix)
{
	if (!_log_mode) {
		_log_mode = LogLevelVerbose;
	}
	else if (_log_mode == LogLevelNone) {
		return;
	}

	_log_file_stream.open(_log_file, ios::app);

	if(_log_file_stream.good() && _log_file_stream.is_open()) {
		_log_file_stream << get_prefix(message_prefix) << message;
		_log_file_stream.close();
	} else {
		cerr << "Could not write log file";
		exit(0);
	}
}

char* Logger::get_prefix(MessagePrefix message_prefix) const {
	time_t time_ = time(nullptr);
	tm tm_;
	char ascii_time[32];

	localtime_s(&tm_, &time_);
	asctime_s(ascii_time, sizeof(ascii_time), &tm_);

	char* selected_prefix = "";

	switch(message_prefix) {
		case Logger::MsgPrfxError:
			selected_prefix = "[Error]:      ";
			break;
		case Logger::MsgPrfxInfo:
			selected_prefix = "[Info]:       ";
			break;
		case Logger::MsgPrfxWarning:
			selected_prefix = "[Warning]:    ";
			break;
	}

	const int t_size = strlen(ascii_time),
		s_size = strlen(selected_prefix),
		r_size = t_size + s_size;

	int r_i = 0;

	char* result = new char[r_size - 3];

	for(int i = 0; i < t_size; i++) {
		if (i == 0) {
			result[r_i] = '[';
			r_i++;
		}

		if(i == t_size - 1) {
			result[r_i] = ']';
			r_i++;
			break;
		}

		result[r_i] = ascii_time[i];
		r_i++;
	}

	for (int j = 0; j < s_size; j++) {
		result[r_i] = selected_prefix[j];
		r_i++;
	}

	return result;
}
