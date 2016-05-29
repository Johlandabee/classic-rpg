#pragma once
#include "GameLoop.h"
#include "GameTime.h"
#include "Config.h"
#include "Input.h"

class Game :
	public GameLoop {
public:
	Game();
	~Game();

private:
	Config config = Config("game.ini");
	Input input;
	string title;

	bool showPerformanceInfo;

	void initialize() override;
	void loadConfig();
	void update(GameTime* gameTime) override;
	void draw(GameTime* gameTime) override;
};
