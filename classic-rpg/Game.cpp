#include "Game.h"
#include "windows.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::initialize()
{
	GameLoop::initialize();
}

void Game::update(GameTime* game_time)
{	
}

void Game::draw(GameTime* game_time)
{
	m_pRenderer->draw(game_time);
}