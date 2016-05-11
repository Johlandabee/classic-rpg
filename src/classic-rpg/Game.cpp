#include "lib/Game.h"

Game::Game() {
}

Game::~Game() {
}

void Game::initialize() {
	m_pRenderer->setWindowSize(1280, 720);

	GameLoop::initialize();
}

void Game::update(GameTime* gameTime) {
}

void Game::draw(GameTime* gameTime) {
	m_pRenderer->draw(gameTime);
}

