#pragma once
#include "GameLoop.h"
#include "GameTime.h"
#include "Config.h"
#include "Input.h"

class Game :
	public GameLoop {
public:
	explicit Game(const Config& config);
	~Game();

private:
	Config config;
	Input input;
	string title;

	bool showPerformanceInfo;

	void initialize() override;
	void loadConfig();
	void update(GameTime* gameTime) override;
	void draw(GameTime* gameTime) override;
};
