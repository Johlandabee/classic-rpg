#include "h/Game.h"
#include "h/Config.h"

Game::Game() {
	Game::initialize();
}

Game::~Game() {
}

void Game::initialize() {
	pRenderer->setWindowTitle(config_.getStringValue("sWindowTitle", "Default"));
	pRenderer->isFullscreen = config_.getBooleanValue("bFullscreen", false);
	pRenderer->setWindowSize(config_.getIntValue("iScreenWidth", 1280),
		config_.getIntValue("iScreenHeight", 720));

	GameLoop::initialize();
}

void Game::update(GameTime* gameTime) {
}

void Game::draw(GameTime* gameTime) {
	pRenderer->draw(gameTime);
}

