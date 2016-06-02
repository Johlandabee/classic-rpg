#include "Console.h"
#include "Base.h"

using namespace Engine;

// ReSharper disable once CppPossiblyUninitializedMember
Base::Base() {
	isRunning = true;

	/* Needs to be initialized before Game()! */
	console = new Console();
}


Base::~Base() {
	delete gameTime;
	delete console;
}


void Base::initialize() {
	gameTime = new GameTime(isFixedFrameRate, desiredFrameRate);
	console->initialize();

	/*ToDo*/
}


void Base::run() {
	// Main game loop:
	while (isRunning) {
		gameTime->begin();
		input.processEvents();
		this->update(gameTime);
		this->draw(gameTime);
		gameTime->end();
	}
}