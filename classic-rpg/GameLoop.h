#pragma once
#include "GameTime.h"

class GameLoop
{
public:
	GameLoop();
	virtual ~GameLoop();
	void run();

protected:
	virtual void initialize();

private:
	virtual void update(GameTime* game_time) abstract;
	virtual void draw(GameTime* game_time) abstract;
};

