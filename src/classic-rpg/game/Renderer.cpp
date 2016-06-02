#include "Renderer.h"
#include "Utils.h"
#include "Logger.h"

// ReSharper disable once CppPossiblyUninitializedMember
Renderer::Renderer() {
}


Renderer::~Renderer() {
	delete consoleRect_;
}

void Renderer::initialize() {
	if (isInitialized_) return;

	charBufferSize = 255;

	/////////////// Do not move /////////////
	screenBufferInfo_.cbSize = charBufferSize;
	/////////////////////////////////////////

	// Set inital window and buffer size
	//updateBufferInfo();

	if (isFullscreen) {
		toggleFullscreeen();
	}

	isInitialized_ = true;
}

void Renderer::setWindowSize(short x, short y) {
	// TODO: All the things

	CONSOLE_FONT_INFOEX fontInfo;
	CONSOLE_CURSOR_INFO cursorInfo;
	CONSOLE_SCREEN_BUFFER_INFOEX screenBufferInfo;

	fontInfo.cbSize = sizeof(fontInfo);
	screenBufferInfo.cbSize = sizeof(screenBufferInfo);

	GetConsoleScreenBufferInfoEx(handle_, &screenBufferInfo);
	GetCurrentConsoleFontEx(handle_, false, &fontInfo);
	GetConsoleCursorInfo(handle_, &cursorInfo);

	cursorInfo.bVisible = false;

	windowRect_.Bottom = y / fontInfo.dwFontSize.Y;
	windowRect_.Left = 0;
	windowRect_.Right = x / fontInfo.dwFontSize.X;
	windowRect_.Top = 0;

	screenBufferInfo.dwSize.X = windowRect_.Right + 1;
	screenBufferInfo.dwSize.Y = windowRect_.Bottom + 1;

	SetConsoleScreenBufferInfoEx(handle_, &screenBufferInfo);
	SetConsoleCursorInfo(handle_, &cursorInfo);

	SetConsoleWindowInfo(handle_, true, &windowRect_);

	/*
	COORD newScreenBufferDimensions;

	HWND windowHandle = GetConsoleWindow();

	LONG lStyle = GetWindowLong(windowHandle, GWL_STYLE);

	lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU);
	SetWindowLong(windowHandle, GWL_STYLE, lStyle);

	LONG lExStyle = GetWindowLong(windowHandle, GWL_EXSTYLE);
	LONG savelExStyle = lExStyle;
	lExStyle &= ~(WS_EX_DLGMODALFRAME | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE);
	SetWindowLong(windowHandle, GWL_EXSTYLE, lExStyle);

	//SetWindowPos(windowHandle, HWND_TOP, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_FRAMECHANGED| SWP_SHOWWINDOW);

	*/
}

void Renderer::setWindowTitle(string windowTitle) {
	Utils::checkStatus(SetConsoleTitle(windowTitle.c_str()),
		"WINAPI SetConsoleTitle() failed!");

	windowTitle_ = windowTitle;
}

void Renderer::updateBufferInfo() {
	// Todo
}

void Renderer::updateBufferSize() const {
	// Todo
}

void Renderer::draw(GameTime* game_time) const {
	// Todo
}

string Renderer::title() const {
	return windowTitle_;
}

void Renderer::toggleFullscreeen() {
	if (isFullscreen) {
	}

	updateBufferSize();
}