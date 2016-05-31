#pragma once
#include "h/Game.h"
#include "h/Config.h"
#include <sstream>
#include <iostream>
#include "h/Logger.h"

using namespace std;

Game::Game(const Config& config) {
	this->config = config;
	Game::initialize();
}

Game::~Game() {
}

void Game::initialize() {
	loadConfig();
	title = renderer->title();
	
	GameLoop::initialize();
}

void Game::loadConfig() {
	renderer->setWindowTitle(config.getStringValue("sWindowTitle", "Default"));
	renderer->isFullscreen = config.getBooleanValue("bFullscreen", false);

	auto x = config.getIntValue("iScreenWidth", 640);
	auto y = config.getIntValue("iScreenHeight", 360);
	renderer->setWindowSize(x, y);

	isFixedFrameRate = config.getBooleanValue("bFixedFrameRate", true);
	desiredFrameRate = config.getDoubleValue("dDesiredFrameRate", 59.0);
	showPerformanceInfo = config.getBooleanValue("bShowPerformanceInfo", false);

	// Keybindings
	input.loadBindings(config);
}

void Game::update(GameTime* gameTime) {

	// Update performance information if enabled (Window title)
	if (showPerformanceInfo) {
		auto ss = stringstream();
		ss << title;
		ss << " | FPS: " << gameTime->fps()
		   << " FrameTime: " << gameTime->frameTimeNs() << "ns";

		renderer->setWindowTitle(ss.str());
	}

	// Exit on escape
	if (input.isAction(EngineShutDown)) {
		Logger::instance()->log("Shutting down...", Logger::MsgPrfxInfo);
		exit(0);
	}

	// Toggle performance info
	if(input.isAction(EngineTogglePerfInfo)) {
			if (showPerformanceInfo) {
				renderer->setWindowTitle(title);
			}
			showPerformanceInfo = !showPerformanceInfo;
	}
}

void Game::draw(GameTime* gameTime) {
	renderer->draw(gameTime);
}