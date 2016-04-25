#pragma once
#include "GameLoop.h"
#include "GameTime.h"

class Game :
	public GameLoop {
public:
	Game();
	~Game();
private:
	void initialize() override;
	void update(GameTime* game_time) override;
	void draw(GameTime* game_time) override;
};

