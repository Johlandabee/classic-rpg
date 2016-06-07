#pragma once
#include "Config.h"
#include "Game.h"
#include "Logger.h"
#include <iostream>
#include <sstream>

using namespace Engine;
using namespace std;

Game::Game(const Config& config) : config(config) {
	showPerformanceInfo = false;
	startFullscreen = false;
	useInputEvents = false;

	initialize();
}

Game::~Game() {
}

void Game::initialize() {
	// Init Game; Load config and set vars
	loadConfig();
	console->setWindowTitle(title);

	// Init base
	Base::initialize();
}

void Game::loadConfig() {
	title = config.getStringValue("sWindowTitle", "Default");
	startFullscreen = config.getBooleanValue("bFullscreen", false);

	//auto x = config.getIntValue("iScreenWidth", 640);
	//auto y = config.getIntValue("iScreenHeight", 360);
	//console->setWindowSize(x, y);

	isFixedFrameRate = config.getBooleanValue("bFixedFrameRate", true);
	desiredFrameRate = config.getDoubleValue("dDesiredFrameRate", 59.0);
	showPerformanceInfo = config.getBooleanValue("bShowPerformanceInfo", false);
	useInputEvents = config.getBooleanValue("bUseInputEvents", false);

	// Key-bindings
	input.loadBindings(config);
}

void Game::update(GameTime* gameTime) {
	// ### Input ###
	// Exit on escape
	if (input.isAction(EngineShutDown)) {
		Logger::instance()->log("Shutting down...", Logger::MsgPrfxInfo);
		exit(0);
	}

	// Toggle performance info
	if (input.isAction(EngineTogglePerfInfo)) {
		if (showPerformanceInfo) {
			console->setWindowTitle(title);
		}
		showPerformanceInfo = !showPerformanceInfo;
	}

	// ### Logic ###
	// Update performance information if enabled (Window title)
	if (showPerformanceInfo) {
		auto ss = stringstream();

		ss << title;
		ss << " | FPS: " << gameTime->fps()
			<< " | FT: " << gameTime->internalFrameTimeNs() << "ns"
			<< " | CFT: " << gameTime->completeFrameTimeMs() << "ms";

		console->setWindowTitle(ss.str());
	}
}

void Game::draw(GameTime* gameTime) {

	console->print();
}