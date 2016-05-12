#include "h/GameLoop.h"

GameLoop::GameLoop() {
	m_pGameTime = new GameTime();
	m_pRenderer = new Renderer();
}


GameLoop::~GameLoop() {
	delete m_pGameTime;
	delete m_pRenderer;
}

void GameLoop::initialize() {
	m_pRenderer->initialize();

	/*Todo*/
}

void GameLoop::run() {
	while (true) {
		m_pGameTime->update();

		this->update(m_pGameTime);
		this->draw(m_pGameTime);
	}
}

