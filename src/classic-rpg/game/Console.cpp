#include "Console.h"
#include "Logger.h"
#include "Utils.h"

using namespace Engine;

// ReSharper disable once CppPossiblyUninitializedMember
Console::Console() {
	charBufferSize = 255;

	/////////////// Do not move /////////////
	screenBufferInfo.cbSize = charBufferSize;
	/////////////////////////////////////////

	if (isFullscreen) {
		toggleFullscreeen();
	}
}


Console::~Console() {
	delete consoleRect;
}

void Console::addBuffer(char*, unsigned length, unsigned short layer) {
}

void Console::compose(const char& c) {
}

void Console::setFullscreen(const bool& isFullscreen) {
	this->isFullscreen = isFullscreen;
}

void Console::setWindowSize(short x, short y) {
	// Set console window size
}

void Console::setWindowTitle(string windowTitle) {
	Utils::checkStatus(SetConsoleTitle(windowTitle.c_str()),
		"WINAPI SetConsoleTitle() failed!", false);

	windowTitle_ = windowTitle;
}

void Console::updateBufferInfo() {
	// ToDo: Fetch buffer info correctly
}

void Console::updateBufferSize() const {
	// ToDo: Update buffer size properly
}

void Console::print() {
	
}

string Console::getTitle() const {
	return windowTitle_;
}

void Console::toggleFullscreeen() {

}

