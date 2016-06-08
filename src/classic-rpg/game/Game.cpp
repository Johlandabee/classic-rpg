#pragma once
#include "Config.h"
#include "Game.h"
#include "Logger.h"
#include <iostream>
#include <sstream>

using namespace Engine;
using namespace std;

Game::Game(const Config& config) : config(config) {
	Game::initialize();
}

Game::~Game() {
    if(entityManager != nullptr) {
        delete entityManager;
        entityManager = nullptr;
    }
}

void Game::initialize() {
	// Load configuration
	loadConfig();
	// Initialize base; Console, Input, GameTime
	Base::initialize();
	// Key-bindings
	input->loadBindings(config);
	// Set window-title
	console->setWindowTitle(windowTitle);
	// Set window-size; This will also set the initial camera size
	console->setBufferSizePx(windowX, windowY);
    // Create EntityManager instance
    entityManager = new EntityManager();

    // Setup player; Inject input and "spawn" entity
    player.injectInput(input);

    // Set @ as display char
    player.setDisplay(64);

    point playerSpawn;
    playerSpawn.X = 0;
    playerSpawn.Y = 0;

    player.move(playerSpawn);

    entityManager->add(dynamic_cast<IEntity*>(&player));
}

void Game::loadConfig() {
	windowTitle = config.getStringValue("sWindowTitle", "Default");
	startFullscreen = config.getBooleanValue("bFullscreen", false);

	windowX = config.getIntValue("iScreenWidth", 640);
	windowY = config.getIntValue("iScreenHeight", 360);

	isFixedFrameRate = config.getBooleanValue("bFixedFrameRate", true);
	desiredFrameRate = config.getDoubleValue("dDesiredFrameRate", 60.0);
	showDebugeInfo = config.getBooleanValue("bShowDebugInfo", false);
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
		if (showDebugeInfo) {
			console->setWindowTitle(windowTitle);
		}
		showDebugeInfo = !showDebugeInfo;
	}

	// Update performance information if enabled (Window title)
	if (showDebugeInfo) {
		auto ss = stringstream();
		ss.precision(6);

		ss << windowTitle;
        ss << " | FPS: " << gameTime->fps()
            << " | FT: " << gameTime->internalFrameTimeUs() << "us"
            << " | CFT: " << gameTime->completeFrameTimeMs() << "ms"
            << " | CBS: " << console->getBufferWidth() << "x" << console->getBufferHeight()
            << " | PPos: " << player.getPosition().X << "X " << player.getPosition().Y << "Y";

		console->setWindowTitle(ss.str());
	}

    // Update EntityManager; Game logic
    entityManager->update(gameTime);

    // Update camera
    console->getCamera()->update(gameTime);
}

void Game::draw(const GameTime* gameTime) {
    entityManager->draw(console);
    // setBufferSizePx() must be called ahead
    console->print();
}