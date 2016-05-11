#include "lib/Renderer.h"
#include "lib/Utils.h"
#include "lib/Logger.h"

// ReSharper disable once CppPossiblyUninitializedMember
Renderer::Renderer() {}


Renderer::~Renderer() {
	delete consoleRect_;
}


void Renderer::initialize() {
	if (isInitialized_) return;

	if(!resolution_.X || !resolution_.Y) {
		Logger::instance()->log("RENDERER INIT Resolution not set properly!", Logger::MsgPrfxError);
		exit(0);
	}

	charBufferSize = 1024;

	/////////////// Do not move /////////////
	screenBufferInfo_.cbSize = charBufferSize;
	/////////////////////////////////////////

	// Set inital window and buffer size
	updateBufferInfo();

	if(isFullscreen_){
		toggleFullscreeen();
	}

	isInitialized_ = true;
}

void Renderer::setWindowSize(int x, int y){
	resolution_ = { x, y };
}

void Renderer::setWindowTitle(string windowTitle) {
	Utils::checkStatus(SetConsoleTitle(windowTitle.c_str()),
		"WINAPI SetConsoleTitle() failed!");
	windowTitle_ = windowTitle;
}

void Renderer::updateBufferInfo() {
	Utils::checkStatus(GetConsoleScreenBufferInfoEx(hOut_, &screenBufferInfo_),
		"WINAPI GetConsoleScreenBufferInfoEx() failed!");
}

void Renderer::updateBufferSize() const {
	Utils::checkStatus(SetConsoleScreenBufferSize(hOut_, screenBufferSize_),
		"WINAPI SetConsoleScreenBufferSize() failed!");
}

void Renderer::draw(GameTime* game_time) const {
	/*Utils::checkStatus(WriteConsoleOutputA(hOut_, &charInfos_, screenBufferSize_, screenBufferPos_, consoleRect_),
		"WINAPI WriteConsoleOutput() failed!");*/
}

void Renderer::toggleFullscreeen() {
	if (isFullscreen_) {
		Utils::checkStatus(SetConsoleDisplayMode(hOut_, CONSOLE_WINDOWED_MODE, &screenBufferSize_),
			"WINAPI SetConsoleDisplayMode() failed!");
		isFullscreen_ = false;
	}
	else if (screenBufferInfo_.bFullscreenSupported){
		Utils::checkStatus(SetConsoleDisplayMode(hOut_, CONSOLE_FULLSCREEN_MODE, &screenBufferSize_),
			"WINAPI SetConsoleDisplayMode() failed!");
		isFullscreen_ = true;
	}

	updateBufferSize();
}

bool Renderer::isFullscreen() const {
	return isFullscreen_;
}

