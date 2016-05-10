#include "Renderer.h"

Renderer::Renderer() {
	initialize();
}


Renderer::~Renderer() {
	delete _conRect;
}


void Renderer::initialize() {
	///////// Do not move //////////
	_sbInfo.cbSize = 96;
	////////////////////////////////


	// Set inital window and buffer size
	getBufferInfo();

	if(_isFullscreen){
		toggleFullscreeen();
	}
}

void Renderer::setWindowSize(int x, int y){
	Utils::checkStatus([](){}, "");
}

void Renderer::setWindowTitle(string windowTitle) {
	Utils::checkStatus(SetConsoleTitle(windowTitle.c_str()),
		"WINAPI SetConsoleTitle() failed!");
	windowTitle_ = windowTitle;
}

void Renderer::getBufferInfo() {
	checkStatus(GetConsoleScreenBufferInfoEx(hOut_, &_sbInfo),
		"WINAPI GetConsoleScreenBufferInfoEx() failed!");
}

void Renderer::setBufferSize() {
	checkStatus(SetConsoleScreenBufferSize(hOut_, _conSize),
		"WINAPI SetConsoleScreenBufferSize() failed!");
}

void Renderer::draw(GameTime* game_time) {
	checkStatus(WriteConsoleOutputA(hOut_, _chInfo, _conSize, _conCoord, _conRect),
		"WINAPI WriteConsoleOutput() failed!");
}

void Renderer::toggleFullscreeen() {
	if (_isFullscreen) {
		checkStatus(SetConsoleDisplayMode(hOut_, CONSOLE_WINDOWED_MODE, &_conSize),
			"WINAPI SetConsoleDisplayMode() failed!")
		_isFullscreen = false;
	}
	else if (_sbInfo.bFullscreenSupported){
		checkStatus(SetConsoleDisplayMode(hOut_, CONSOLE_FULLSCREEN_MODE, &_conSize)),
			"WINAPI SetConsoleDisplayMode() failed!");
		_isFullscreen = true;
	}

	updateBufferSize();
}

bool Renderer::isFullscreen() {
	return _isFullscreen;
}


