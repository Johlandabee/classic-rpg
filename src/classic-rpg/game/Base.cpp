#include "Console.h"
#include "Base.h"

using namespace Engine;

// ReSharper disable once CppPossiblyUninitializedMember
Base::Base() {
	isRunning = true;

	/* Needs to be initialized before Game! */
	console = new Console();
}

Base::~Base() {
	delete gameTime;
	delete console;
}

void Engine::Base::initialize()
{
	gameTime = new GameTime(isFixedFrameRate, desiredFrameRate);
	input = new Input()
}

void Base::run() {
	// Main game loop:

	while (isRunning) {
		if (isInitialized) {
			gameTime->begin();
			input.processEvents();
			this->update(gameTime);
			this->draw(gameTime);
			gameTime->end();
		}
	}
}


