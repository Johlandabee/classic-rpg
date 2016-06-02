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
	Renderer* renderer;

	bool isFixedFrameRate = true;
	double desiredFrameRate = 59.0;

private:
	GameTime* gameTime;
	bool isRunning;

	virtual void update(GameTime* game_time) abstract;
	virtual void draw(GameTime* game_time) abstract;
};
