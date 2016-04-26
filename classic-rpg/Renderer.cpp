#include "Renderer.h"
#include <iostream>

using namespace std;

Renderer::Renderer() {
	initialize();
}


Renderer::~Renderer() {
	delete _conRect;
}


void Renderer::initialize() {
	//////////////////////////////////////
	_sbInfo.cbSize = 96;
	//////////////////////////////////////
	updateBufferInfo();
	//SetConsoleDisplayMode(_hOut, CONSOLE_FULLSCREEN_MODE, &_conSize);
	toggleFullscreeen();
	//setWindowTitle("Classic RPG");

	const short i = 20;

	/*
	_conSize = { i, i };
	_conCoord = {};
	_conRect = new _SMALL_RECT{ 0,0,i,i };;
	_chInfo[i*i];

	for (int j = 0; j < (i*i); j++)
	{
		_chInfo[j].Char.AsciiChar = 219;
		_chInfo[j].Attributes = FOREGROUND_GREEN;
	}
	*/
}

void Renderer::setWindowTitle(string title) {
	_status = SetConsoleTitle(_wndTitle.c_str());
	check_status("WINAPI SetConsoleTitle() failed!");
	_wndTitle = title;
}

void Renderer::updateBufferInfo() {
	_status = GetConsoleScreenBufferInfoEx(_hOut, &_sbInfo);
	check_status("WINAPI GetConsoleScreenBufferInfoEx() failed!");
}

void Renderer::updateBufferSize() {
	_status = SetConsoleScreenBufferSize(_hOut, _conSize);
	check_status("WINAPI SetConsoleScreenBufferSize() failed!");
}

void Renderer::draw(GameTime* game_time) {
	_status = WriteConsoleOutputA(_hOut, _chInfo, _conSize, _conCoord, _conRect);
	_status = 1;
	check_status("WINAPI WriteConsoleOutput() failed!");
}

void Renderer::toggleFullscreeen() {
	if (_isFullscreen) {
		_status = SetConsoleDisplayMode(_hOut, CONSOLE_WINDOWED_MODE, &_conSize);
		check_status("WINAPI SetConsoleDisplayMode() failed!");
		_isFullscreen = false;
	}
	else if (_sbInfo.bFullscreenSupported){
		_status = SetConsoleDisplayMode(_hOut, CONSOLE_FULLSCREEN_MODE, &_conSize);
		check_status("WINAPI SetConsoleDisplayMode() failed!");
		_isFullscreen = true;
	}

	//updateBufferSize();
}

bool Renderer::isFullscreen() {
	return _isFullscreen;
}

void Renderer::check_status(string error_message, bool nuke) {
	Logger* logger = Logger::instance();
	if (_status == 0) {
		_status = GetLastError();
		logger->log(error_message, Logger::MsgPrfxError, _status);

		if (nuke) {
			exit(_status);
		}
	}
}

