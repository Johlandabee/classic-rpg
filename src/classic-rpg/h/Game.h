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
	Config config_ = Config("game.ini");

	bool showPerformanceInfo_;
	bool perfTitle = false; // Todo: Proper name and init...
	string title_;
	Input input_;

	void initialize() override;
	void update(GameTime* gameTime) override;
	void draw(GameTime* gameTime) override;
};

