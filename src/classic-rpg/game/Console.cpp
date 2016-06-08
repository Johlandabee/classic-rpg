#include "Console.h"
#include "Colors.h"
#include "Logger.h"
#include <sstream>

using namespace Engine;

Console::Console() {
	if(hStdHandle == INVALID_HANDLE_VALUE) {
		throw runtime_error("Could not receive console handle");
	}
}


Console::~Console() {
	// Clean-up, delete pointer
	if(camera != nullptr) {
		delete camera;
		camera = nullptr;
	}

	if(buffer != nullptr) {
		delete buffer;
		buffer = nullptr;
	}
}

void Console::initialize() {
	hideCursor();
	updateFontSize();
	camera = new Camera();
}

void Console::setFullscreen(const bool& isFullscreen) {
	this->isFullscreen = isFullscreen;
}

void Console::setBufferSizePx(const ushort& resX, const ushort& resY) {
	CONSOLE_SCREEN_BUFFER_INFOEX screenBufferInfo;

	screenBufferInfo.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

	ushort step = 0;
	auto status = GetConsoleScreenBufferInfoEx(hStdHandle, &screenBufferInfo);

	if(status && isFontSizeSet) {
		step++;
		auto newBufferX = resX / fontSizeX;
		auto newBufferY = resY / fontSizeY;

		screenBufferInfo.dwSize.X = newBufferX + 1;
		screenBufferInfo.dwSize.Y = newBufferY + 1;

		screenBufferInfo.dwMaximumWindowSize.X = newBufferX;
		screenBufferInfo.dwMaximumWindowSize.Y = newBufferY;

		status = SetConsoleScreenBufferInfoEx(hStdHandle, &screenBufferInfo);

		if (status) {
			step++;
			 
			SMALL_RECT windowRect{ 0, 0, newBufferX, newBufferY };
			status = SetConsoleWindowInfo(hStdHandle, true, &windowRect);
			if(status) {
				// Update camera rectangle
				camera->setSize(newBufferX, newBufferY);
				// Update private console rectangle
				rectangle.width = newBufferX + 1;
				rectangle.height = newBufferY + 1;

				// Set actual output buffer size
				allocateBuffer();
				return;
			}
		} 
	}

	status = GetLastError();
	auto ss = stringstream();
	ss << "CONSOLE: Failed to set console buffer size by resolution at step " << step;
	Logger::instance()->log(ss.str(), Logger::MsgPrfxError, status);
}

void Console::setWindowTitle(const string& windowTitle) {
	this->windowTitle = windowTitle;
	auto status = SetConsoleTitle(this->windowTitle.c_str());
	if(!status) {
		status = GetLastError();
		Logger::instance()->log("CONSOLE: Failed to set window title", Logger::MsgPrfxError, status);
	}
}

uint Console::getBufferWidth() const {
	return rectangle.width;
}

uint Console::getBufferHeight() const {
	return rectangle.height;
}

uint Console::getBufferSize() const {
	return bufferSize;
}

Camera* Console::getCamera() const {
	return camera;
}


string Console::getTitle() const {
	return windowTitle;
}

void Console::print() const {
	COORD size = { rectangle.width, rectangle.height };
	COORD coord = { 0, 0 };
	SMALL_RECT region = { 0, 0, rectangle.width, rectangle.height };

	auto status = WriteConsoleOutput(hStdHandle, buffer, size, coord, &region);

	if (status) return;

	status = GetLastError();
	Logger::instance()->log("CONSOLE: Failed to write console buffer", Logger::MsgPrfxError, status);
}

void Console::allocateBuffer() {
	// If already allocated, delete and set to null pointer for reallocation
	if(buffer != nullptr) {
		delete buffer;
		buffer = nullptr;
	}

	bufferSize = rectangle.surface() + 2;
	buffer = new CHAR_INFO[bufferSize];

	if(buffer == nullptr) {
		throw runtime_error("CONSOLE: Could not (re)allocate console buffer");
	}

	// Default char info
	CHAR_INFO charInfo;

	// Default char = space
	charInfo.Char.AsciiChar = 32;
	charInfo.Char.UnicodeChar = 32;

	// Default colours
	charInfo.Attributes = BG_Blue | FG_Gray;

	for(auto i = 0; i < bufferSize; i++) {
		buffer[i] = charInfo;
	}
}

void Console::updateFontSize() {
	CONSOLE_FONT_INFOEX fontInfo;

	fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);

	auto status = GetCurrentConsoleFontEx(hStdHandle, false, &fontInfo);

	if(status) {
		fontSizeX = fontInfo.dwFontSize.X;
		fontSizeY = fontInfo.dwFontSize.Y;
		isFontSizeSet = true;
		return;
	}

	status = GetLastError();
	Logger::instance()->log("CONSOLE: Failed to update console font size", Logger::MsgPrfxError, status);
}

void Console::hideCursor() const {
	CONSOLE_CURSOR_INFO cursorInfo;

	ushort step = 0;
	auto status = GetConsoleCursorInfo(hStdHandle, &cursorInfo);

	if (status) {
		step++;
		cursorInfo.bVisible = false;
		status = SetConsoleCursorInfo(hStdHandle, &cursorInfo);

		if (status) return;
	}

	status = GetLastError();
	auto ss = stringstream();
	ss << "CONSOLE: Failed to hide console cursor at step " << step;
	Logger::instance()->log(ss.str(), Logger::MsgPrfxError, status);
}
