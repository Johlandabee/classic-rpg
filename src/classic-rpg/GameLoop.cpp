#include "h/GameLoop.h"

GameLoop::GameLoop() {
	pGameTime = new GameTime();
	pRenderer = new Renderer();
}


GameLoop::~GameLoop() {
	delete pGameTime;
	delete pRenderer;
}

void GameLoop::initialize() {
	pRenderer->initialize();

	/*Todo*/
}

void GameLoop::run() {
	while (true) {
		pGameTime->update();

		this->update(pGameTime);
		this->draw(pGameTime);
	}
}

