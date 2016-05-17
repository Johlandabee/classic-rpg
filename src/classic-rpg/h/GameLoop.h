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
	Renderer* pRenderer;

	bool isFixedFrameRate = true;
	double desiredFrameRate = 60.0;

private:
	GameTime* pGameTime;
	bool running_;

	virtual void update(GameTime* game_time) abstract;
	virtual void draw(GameTime* game_time) abstract;
};

