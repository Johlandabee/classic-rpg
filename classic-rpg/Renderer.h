#pragma once
#include <windows.h>

class GameTime;

class Renderer
{
public:
	Renderer();
	~Renderer();

	void draw(GameTime* game_time) const;

private:
	const HANDLE hwndConsole = CreateFile("CONOUT$",
		GENERIC_WRITE | GENERIC_READ, NULL, nullptr, OPEN_ALWAYS, NULL, nullptr);

	COORD m_conSize, m_conCoord;
	PSMALL_RECT m_conRect;

	// ToDo: Need to solve this...
	CHAR_INFO m_conInfo[20*20];
};

