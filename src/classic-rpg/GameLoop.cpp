#include "h/GameLoop.h"

// ReSharper disable once CppPossiblyUninitializedMember
GameLoop::GameLoop() {
	running_ = true;


	/* Needs to be initialized before Game()! */
	pRenderer = new Renderer();

}

/*-----------------------------------------------------------------------------------------------*/
GameLoop::~GameLoop() {
	delete pGameTime;
	delete pRenderer;
}

/*-----------------------------------------------------------------------------------------------*/
void GameLoop::initialize() {
	pGameTime = new GameTime(isFixedFrameRate, desiredFrameRate);
	pRenderer->initialize();

	/*Todo*/
}

/*-----------------------------------------------------------------------------------------------*/
void GameLoop::run() {

	while (running_) {
		pGameTime->begin();
		
		this->update(pGameTime);
		this->draw(pGameTime);
		
		pGameTime->end();
		pGameTime->wait();
	}
}

