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
	// Load config
	loadConfig();
	// Init base; Console, Input, GameTime
	Base::initialize();
	// Key-bindings
	input->loadBindings(config);
	// Set window-title
	console->setWindowTitle(windowTitle);
	// Set window-size
	console->setWindowSize(windowX, windowY);
}

void Game::loadConfig() {
	windowTitle = config.getStringValue("sWindowTitle", "Default");
	startFullscreen = config.getBooleanValue("bFullscreen", false);

	windowX = config.getIntValue("iScreenWidth", 640);
	windowY = config.getIntValue("iScreenHeight", 360);
	//console->setWindowSize(x, y);

	isFixedFrameRate = config.getBooleanValue("bFixedFrameRate", true);
	desiredFrameRate = config.getDoubleValue("dDesiredFrameRate", 60.0);
	showPerformanceInfo = config.getBooleanValue("bShowPerformanceInfo", false);
	useInputEvents = config.getBooleanValue("bUseInputEvents", false);
}

void Game::update(const GameTime* gameTime) {
	// Process actual input events if enabled. Currently WIP
	if (useInputEvents) {
		input->processEvents();
	}

	// Exit on escape
	if (input->isAction(EngineShutDown)) {
		Logger::instance()->log("Shutting down...", Logger::MsgPrfxInfo);
		exit(0);
	}

	// Toggle performance info
	if (input->isAction(EngineTogglePerfInfo)) {
		if (showPerformanceInfo) {
			console->setWindowTitle(windowTitle);
		}
		showPerformanceInfo = !showPerformanceInfo;
	}

	// Logic 
	// Update performance information if enabled (Window title)
	if (showPerformanceInfo) {
		auto ss = stringstream();
		ss.precision(6);

		ss << windowTitle;
		ss << " | FPS: " << gameTime->fps()
			<< " | FT: " << gameTime->internalFrameTimeUs() << "us"
			<< " | CFT: " << gameTime->completeFrameTimeMs() << "ms";

		console->setWindowTitle(ss.str());
	}
}

void Game::draw(const GameTime* gameTime) {
	
}