#pragma once
#include "h/Game.h"
#include "h/Config.h"
#include <sstream>
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
	title_ = pRenderer->title();
	pRenderer->isFullscreen = config_.getBooleanValue("bFullscreen", false);

	auto x = config_.getIntValue("iScreenWidth", 640);
	auto y = config_.getIntValue("iScreenHeight", 360);

	pRenderer->setWindowSize(x, y);

	isFixedFrameRate = config_.getBooleanValue("bFixedFrameRate", true);
	desiredFrameRate = config_.getDoubleValue("dDesiredFrameRate", 60.0);

	showPerformanceInfo_ = config_.getBooleanValue("bShowPerformanceInfo", false);

	input_ = Input();

	input_.bind(PlayerMoveDown, GAME_S);

	GameLoop::initialize();
}

/*-----------------------------------------------------------------------------------------------*/
void Game::update(GameTime* gameTime) {

	// Update performance information if enabled (Window title)
	if (showPerformanceInfo_) {
		auto ss = stringstream();
		ss << title_;
		ss << " | FPS: " << gameTime->fps()
			<< " FrameTime: " << gameTime->frameTimeNs() << "ns";
		pRenderer->setWindowTitle(ss.str());
	}

	// Test key binding
	if(input_.isAction(PlayerMoveDown)) {
		cout << "Player moving down" << endl;
	}
}

/*-----------------------------------------------------------------------------------------------*/
void Game::draw(GameTime* gameTime) {
	pRenderer->draw(gameTime);
}

