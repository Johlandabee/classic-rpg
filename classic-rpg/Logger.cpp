#include "Logger.h"
#include <time.h>
#include <iostream>
#include <sstream>

Logger* Logger::pInstance_ = nullptr;

Logger::Logger(LogLevel logLevel, string fileName) {
	logLevel_ = logLevel;
	logFile_ = fileName;
	pInstance_ = this;
}

Logger::~Logger()
{
	if(pInstance_ != nullptr) {
		delete pInstance_;
		pInstance_ = nullptr;
	}
}

Logger* Logger::instance(LogLevel logLevel /*= LogLevelNone */, char* fileName) {
	return pInstance_ ? pInstance_ : new Logger(logLevel, fileName);
}

void Logger::log(string message, MessagePrefix messagePrefix, int status)
{
	if (logLevel_ == LogLevelNone) {
		return;
	}

	logFileStream_.open(logFile_, ios::app);

	if(logFileStream_.good() && logFileStream_.is_open()) {
		logFileStream_ << '[' << get_time() << "][" 
			<< get_prefix_str(messagePrefix) << "]:\t\t\t" 
			<< message;

		if (status != 0) {
			logFileStream_ << " Status: " << status;
		}
		logFileStream_ << endl;

		logFileStream_.close();
	} else {
		cerr << "Could not write log file";
		exit(0);
	}
}

string Logger::getTime() {
	time_t time_ = time(nullptr);
	tm tm_;
	localtime_s(&tm_, &time_);
	char buf[9];
	strftime(buf, sizeof(buf), "%X", &tm_);
	return buf;
}

string Logger::getPrefixStr(MessagePrefix messagePrefix) {
	string str;
	switch (messagePrefix) {
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
