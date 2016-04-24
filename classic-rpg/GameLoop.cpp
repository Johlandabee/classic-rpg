#include "GameLoop.h"
#include "Renderer.h"

GameTime* m_pGameTime;
Renderer* m_pRenderer;

GameLoop::GameLoop()
{
	m_pGameTime = new GameTime();
	m_pRenderer = new Renderer();
}


GameLoop::~GameLoop()
{
	delete m_pGameTime;
}

void GameLoop::initialize()
{
	// ToDo: Initialize all the things
}

void GameLoop::run()
{
	this->initialize();
	while(true)
	{
		this->update(m_pGameTime);
		this->draw(m_pGameTime);
	}
}
