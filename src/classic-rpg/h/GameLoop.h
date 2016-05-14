#pragma once
#include "GameTime.h"
#include "Renderer.h"

class GameLoop {
public:
	GameLoop();
	virtual ~GameLoop();
	void run();

protected:
	virtual void initialize();
	GameTime* pGameTime;
	Renderer* pRenderer;

private:
	const int drawFps = 60, updateFps = 30;

	virtual void update(GameTime* game_time) abstract;
	virtual void draw(GameTime* game_time) abstract;
};

