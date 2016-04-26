#pragma once
#include <windows.h>
#include "GameTime.h"
#include "Logger.h"
#include <string>

using namespace std;

class Renderer {
public:
	Renderer();
	~Renderer();
	void initialize();
	void setWindowTitle(string title);
	void updateBufferInfo();
	void updateBufferSize();
	void draw(GameTime* game_time);
	void toggleFullscreeen();

	bool isFullscreen();

private:
	const HANDLE _hOut = CreateFile("CONOUT$",
		GENERIC_WRITE | GENERIC_READ, NULL, nullptr, OPEN_ALWAYS, NULL, nullptr);

	CONSOLE_SCREEN_BUFFER_INFOEX _sbInfo;
	COORD _conSize, _conCoord;
	PSMALL_RECT _conRect;

	// ToDo: Need to solve this...
	CHAR_INFO _chInfo[20 * 20];

	string _wndTitle;
	bool _isFullscreen = false;
	int _status;
};

