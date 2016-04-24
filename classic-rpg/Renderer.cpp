#include "Renderer.h"

Renderer::Renderer()
{
	SetConsoleTitle("Classic RPG");

	const short i = 20;

	m_conSize = { i, i };
	m_conCoord = {};
	m_conRect = new _SMALL_RECT { 0,0,i,i };;
	//m_conInfo[i*i];

	for (int j = 0; j < (i*i); j++)
	{
		m_conInfo[j].Char.AsciiChar = 219;
		m_conInfo[j].Attributes = FOREGROUND_GREEN;
	}
}


Renderer::~Renderer()
{
	delete m_conRect;
}

void Renderer::draw(GameTime* game_time) const
{
	WriteConsoleOutput(hwndConsole, m_conInfo, m_conSize, m_conCoord, m_conRect);
}
