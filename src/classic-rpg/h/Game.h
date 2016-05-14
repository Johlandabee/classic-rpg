#pragma once
#include "GameLoop.h"
#include "GameTime.h"
#include "Config.h"

class Game :
	public GameLoop {
public:
	Game();
	~Game();
private:
	Config config_ = Config("game.ini");

	void initialize() override;
	void update(GameTime* gameTime) override;
	void draw(GameTime* gameTime) override;
};

