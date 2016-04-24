#pragma once
#include "GameTime.h"
#include "Renderer.h"

class GameLoop
{
public:
	GameLoop();
	virtual ~GameLoop();
	void run();

protected:
	virtual void initialize();
	GameTime* m_pGameTime;
	Renderer* m_pRenderer;

private:
	const int FPS = 60;

	virtual void update(GameTime* game_time) abstract;
	virtual void draw(GameTime* game_time) abstract;
};

