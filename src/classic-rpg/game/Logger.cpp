#include "Logger.h"
#include <iostream>
#include <sstream>
#include <time.h>

Logger* Logger::pInstance = nullptr;

Logger::Logger(LogLevel logLevel, string fileName) {
	this->logLevel = logLevel;
	logFile = fileName;
	pInstance = this;
}

Logger::~Logger() {
	if (pInstance != nullptr) {
		delete pInstance;
		pInstance = nullptr;
	}
}

Logger* Logger::instance(string fileName, LogLevel logLevel /*= LogLevelNone */) {
	return pInstance ? pInstance : new Logger(logLevel, fileName);
}

void Logger::log(string message, MessagePrefix messagePrefix, int status) const {
	if (logLevel == LogLevelNone) {
		return;
	}

	ofstream logFileStream;

	logFileStream.open(logFile, ios::app);

	if (logFileStream.good() && logFileStream.is_open()) {
		logFileStream << '[' << getTime() << "]["
			<< getPrefixStr(messagePrefix) << "]:\t\t\t"
			<< message;

		if (status != 0) {
			logFileStream << " Status: " << status;
		}
		logFileStream << endl;

		logFileStream.close();
	}
	else {
		cerr << "Could not write log file";
		exit(0);
	}
}

string Logger::getTime() {
	auto time_ = time(nullptr);
	tm tm_;
	localtime_s(&tm_, &time_);
	char buf[9];
	strftime(buf, sizeof(buf), "%X", &tm_);
	return buf;
}

string Logger::getPrefixStr(MessagePrefix messagePrefix) {
	string str;
	switch (messagePrefix) {
	case MsgPrfxError:
		str = "Error";
		break;
	case MsgPrfxInfo:
		str = "Info";
		break;
	case MsgPrfxWarning:
		str = "Warning";
		break;
	}
	return str;
}