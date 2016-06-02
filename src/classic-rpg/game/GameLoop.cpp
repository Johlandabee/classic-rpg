#include "GameLoop.h"

// ReSharper disable once CppPossiblyUninitializedMember
GameLoop::GameLoop() {
	isRunning = true;

	/* Needs to be initialized before Game()! */
	renderer = new Renderer();
}


GameLoop::~GameLoop() {
	delete gameTime;
	delete renderer;
}


void GameLoop::initialize() {
	gameTime = new GameTime(isFixedFrameRate, desiredFrameRate);
	renderer->initialize();

	/*Todo*/
}


void GameLoop::run() {
	while (isRunning) {
		gameTime->begin();

		this->update(gameTime);
		this->draw(gameTime);

		gameTime->end();
	}
}