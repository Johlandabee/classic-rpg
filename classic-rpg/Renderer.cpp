#include "Renderer.h"

//ToDo: Error handling/logging on all WINAPI calls

Renderer::Renderer() {
	
	//SetConsoleTitle("Classic RPG");

	const short i = 20;

	/*
	m_conSize = { i, i };
	m_conCoord = {};
	m_conRect = new _SMALL_RECT { 0,0,i,i };;
	//m_conInfo[i*i];

	for (int j = 0; j < (i*i); j++)
	{
		m_conInfo[j].Char.AsciiChar = 219;
		m_conInfo[j].Attributes = FOREGROUND_GREEN;
	}
	*/

	initialize();
}


Renderer::~Renderer() {
	delete m_conRect;
}


void Renderer::initialize() {
	updateBufferInfo();
	//updateBufferSize();
	toggleFullscreeen();
	setWindowTitle("Classic RPG");
}

void Renderer::setWindowTitle(char* title) {
	m_wndTitle = title;
	SetConsoleTitle(m_wndTitle);
}

void Renderer::updateBufferInfo() {
	GetConsoleScreenBufferInfoEx(m_hOut, &m_sbInfo);
}

void Renderer::updateBufferSize() {
	SetConsoleScreenBufferSize(m_hOut, m_conSize);
}

// Public functions
void Renderer::draw(GameTime* game_time) {
	//WriteConsoleOutput(m_hOut, m_conInfo, m_conSize, m_conCoord, m_conRect);
}

void Renderer::toggleFullscreeen() {
	if (m_isFullscreen) {
		m_isFullscreen = SetConsoleDisplayMode(m_hOut, CONSOLE_WINDOWED_MODE, &m_conSize);
		updateBufferSize();

	}
	else if (m_sbInfo.bFullscreenSupported){
		m_isFullscreen = SetConsoleDisplayMode(m_hOut, CONSOLE_FULLSCREEN_MODE, &m_conSize);
		updateBufferSize();
	}
}

bool Renderer::isFullscreen() {
	return m_isFullscreen;
}


