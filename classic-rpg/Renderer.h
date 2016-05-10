#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include "GameTime.h"
#include "Logger.h"
#include "Utils.h"

using namespace std;

class Renderer {
public:
	Renderer();
	~Renderer();
	
	void setWindowTitle(string title);
	void draw(GameTime* game_time);

private:
	const HANDLE hOut_ = CreateFile("CONOUT$",
		GENERIC_WRITE | GENERIC_READ, NULL, nullptr, OPEN_ALWAYS, NULL, nullptr);

	CONSOLE_SCREEN_BUFFER_INFOEX screenBufferInfo_;
	COORD screenBufferSize_, screenBufferPos;
	PSMALL_RECT consoleRect_;

	CHAR_INFO charInfos_;

	string windowTitle_;

	void initialize();
	void updateBufferInfo();
	void updateBufferSize();
	void toggleFullscreeen();

	bool isFullscreen_ = false;
};

