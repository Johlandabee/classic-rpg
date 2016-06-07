#include "Console.h"
#include "Logger.h"
#include "Utils.h"

using namespace Engine;

Console::Console() {

}


Console::~Console() {
	delete consoleRect;
}

void Console::setFullscreen(const bool& isFullscreen) {
	this->isFullscreen = isFullscreen;
}

void Console::setWindowSize(const unsigned short& x, const unsigned short& y) {

}

void Console::setWindowTitle(const string& windowTitle) {
	Utils::checkStatus(SetConsoleTitle(windowTitle.c_str()),
		"WINAPI SetConsoleTitle() failed!", false);

	windowTitle_ = windowTitle;
}

void Console::updateBufferInfo() {

}

void Console::updateBufferSize() const {

}


string Console::getTitle() const {
	return windowTitle_;
}

void Console::toggleFullscreeen() {

}

