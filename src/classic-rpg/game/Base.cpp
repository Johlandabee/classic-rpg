#include "Console.h"
#include "Base.h"

using namespace Engine;

Base::Base() {
	isRunning = true;	
}

Base::~Base() {
	if (console != nullptr) {
		delete console;
		console = nullptr;
	}

	if (gameTime != nullptr) {
		delete console;
		console = nullptr;
	}

	if (input != nullptr) {
		delete console;
		console = nullptr;
	}
}

void Engine::Base::initialize()
{
	console = new Console();
	gameTime = new GameTime(isFixedFrameRate, desiredFrameRate);
	input = new Input();

	isInitialized = true;
}

void Base::run() {
	// Main game loop:

	while (isRunning) {
		if (isInitialized) {
			gameTime->begin();
			input->processEvents();
			update(gameTime);
			draw(gameTime);
			gameTime->end();
		}
	}
}


