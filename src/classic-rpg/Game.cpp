#include "h/Game.h"
#include "h/Config.h"
#include <iostream>

using namespace std;

Game::Game() {
	Game::initialize();
}

/*-----------------------------------------------------------------------------------------------*/
Game::~Game() {
}

/*-----------------------------------------------------------------------------------------------*/
void Game::initialize() {
	
	// Loading config file and set values
	// Todo: eventually move things into base.ini
	pRenderer->setWindowTitle(config_.getStringValue("sWindowTitle", "Default"));
	pRenderer->isFullscreen = config_.getBooleanValue("bFullscreen", false);

	auto x = config_.getIntValue("iScreenWidth", 640);
	auto y = config_.getIntValue("iScreenHeight", 360);

	pRenderer->setWindowSize(x, y);

	isFixedFrameRate = config_.getBooleanValue("bFixedFrameRate", true);
	desiredFrameRate = config_.getDoubleValue("dDesiredFrameRate", 60.0);

	GameLoop::initialize();
}

/*-----------------------------------------------------------------------------------------------*/
void Game::update(GameTime* gameTime) {
}

/*-----------------------------------------------------------------------------------------------*/
void Game::draw(GameTime* gameTime) {
	cout << gameTime->fps() << endl;
	pRenderer->draw(gameTime);
}

