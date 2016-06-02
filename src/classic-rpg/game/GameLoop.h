#pragma once
#include "GameTime.h"
#include "Console.h"
#include "Input.h"

class GameLoop {
public:
	GameLoop();
	virtual ~GameLoop();
	void run();

protected:
	bool isFixedFrameRate = true;
	Console* console;
	double desiredFrameRate = 60.0;
	Input input;
	virtual void initialize();

private:
	GameTime* gameTime;
	

	bool isRunning;

	virtual void update(GameTime* game_time) abstract;
	virtual void draw(GameTime* game_time) abstract;
};
