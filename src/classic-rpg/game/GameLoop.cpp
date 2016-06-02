#include "Console.h"
#include "GameLoop.h"

// ReSharper disable once CppPossiblyUninitializedMember
GameLoop::GameLoop() {
	isRunning = true;

	/* Needs to be initialized before Game()! */
	console = new Console();
}


GameLoop::~GameLoop() {
	delete gameTime;
	delete console;
}


void GameLoop::initialize() {
	gameTime = new GameTime(isFixedFrameRate, desiredFrameRate);
	console->initialize();

	/*Todo*/
}


void GameLoop::run() {
	// Main game loop:
	while (isRunning) {
		gameTime->begin();
		input.processEvents();
		this->update(gameTime);
		this->draw(gameTime);
		gameTime->end();
	}
}