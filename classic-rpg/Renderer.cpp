#include "Renderer.h"
#include <iostream>

using namespace std;

//ToDo: Error handling/logging on all WINAPI calls

Renderer::Renderer() {
	
	//SetConsoleTitle("Classic RPG");

	const short i = 20;

	/*
	m_conSize = { i, i };
	m_conCoord = {};
	m_conRect = new _SMALL_RECT { 0,0,i,i };;
	//m_conInfo[i*i];

	for (int j = 0; j < (i*i); j++)
	{
		m_conInfo[j].Char.AsciiChar = 219;
		m_conInfo[j].Attributes = FOREGROUND_GREEN;
	}
	*/

	initialize();
}


Renderer::~Renderer() {
	delete _conRect;
}


void Renderer::initialize() {
	//updateBufferInfo();
	updateBufferSize();
	toggleFullscreeen();
	setWindowTitle("Classic RPG");
}

void Renderer::setWindowTitle(string title) {
	Logger* _logger = Logger::instance();
	_status = SetConsoleTitle(_wndTitle.c_str());
	if (_status == 0) {
		_status = GetLastError();
		_logger->log("WINAPI SetConsoleTitle() failed!", Logger::MsgPrfxError, _status);
		exit(_status);
	}
	_wndTitle = title;
}

void Renderer::updateBufferInfo() {
	Logger* _logger = Logger::instance();
	_status = GetConsoleScreenBufferInfoEx(_hOut, &_sbInfo);
	if (_status == 0) {
		_status = GetLastError();
		_logger->log("WINAPI GetConsoleBufferInfoEx() failed!", Logger::MsgPrfxError, _status);
		exit(_status);
	}
}

void Renderer::updateBufferSize() {
	Logger* _logger = Logger::instance();
	_status = SetConsoleScreenBufferSize(_hOut, _conSize);
	if (_status == 0) {
		_status = GetLastError();
		_logger->log("WINAPI SetConsoleBufferSize() failed!", Logger::MsgPrfxError, _status);
		exit(_status);
	}
}

void Renderer::draw(GameTime* game_time) {
	Logger* _logger = Logger::instance();
	_status = WriteConsoleOutput(_hOut, _chInfo, _conSize, _conCoord, _conRect);
	if (_status == 0) {
		_status = GetLastError();
		_logger->log("WINAPI WriteConsoleOutput() failed!", Logger::MsgPrfxError, _status);
		exit(_status);
	}
}

void Renderer::toggleFullscreeen() {
	Logger* _logger = Logger::instance();
	if (_isFullscreen) {
		_status = SetConsoleDisplayMode(_hOut, CONSOLE_WINDOWED_MODE, &_conSize);
		if (_status == 0) {
			_status = GetLastError();
			_logger->log("WINAPI SetConsoleDisplayMode() failed!", Logger::MsgPrfxError, _status);
			exit(_status);
		}
		_isFullscreen = false;
	}
	else if (_sbInfo.bFullscreenSupported){
		_status = SetConsoleDisplayMode(_hOut, CONSOLE_FULLSCREEN_MODE, &_conSize);
		if (_status == 0) {
			_status = GetLastError();
			_logger->log("WINAPI SetConsoleDisplayMode() failed!", Logger::MsgPrfxError, _status);
			exit(_status);
		}
		_isFullscreen = true;
	}

	updateBufferSize();
}

bool Renderer::isFullscreen() {
	return _isFullscreen;
}


