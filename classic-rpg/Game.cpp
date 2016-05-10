#include "Game.h"
#include "windows.h"

Game::Game() {
}

Game::~Game() {
}

void Game::initialize() {
	GameLoop::initialize();
}

void Game::update(GameTime* gameTime) {
}

void Game::draw(GameTime* gameTime) {
	m_pRenderer->draw(gameTime);
}

