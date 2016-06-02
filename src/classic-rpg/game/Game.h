#pragma once
#include "Config.h"
#include "GameLoop.h"
#include "GameTime.h"

class Game :
	public GameLoop {
public:
	explicit Game(const Config& config);
	~Game();

private:
	bool showPerformanceInfo;

	Config config;
	string title;

	void draw(GameTime* gameTime) override;
	void initialize() override;
	void loadConfig();
	void update(GameTime* gameTime) override;
};
