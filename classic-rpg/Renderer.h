#pragma once
#include <windows.h>
#include "GameTime.h"

using namespace std;

class Renderer {
public:
	Renderer();
	~Renderer();
	void initialize();
	void setWindowTitle(char* title);
	void updateBufferInfo();
	void updateBufferSize();
	void draw(GameTime* game_time);
	void toggleFullscreeen();

	bool isFullscreen();

private:
	const HANDLE m_hOut = CreateFile("CONOUT$",
		GENERIC_WRITE | GENERIC_READ, NULL, nullptr, OPEN_ALWAYS, NULL, nullptr);

	CONSOLE_SCREEN_BUFFER_INFOEX m_sbInfo;
	COORD m_conSize, m_conCoord;
	PSMALL_RECT m_conRect;

	// ToDo: Need to solve this...
	CHAR_INFO m_conInfo[20 * 20];

	char* m_wndTitle;
	bool m_isFullscreen;
};

