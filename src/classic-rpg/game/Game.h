#pragma once
#include "Config.h"
#include "Base.h"
#include "GameTime.h"

namespace Engine
{
	class Game :
		public Base {

	public:
		explicit Game(const Config& config);
		~Game();

	private:
		bool showPerformanceInfo;
		bool startFullscreen;
		bool useInputEvents;

		unsigned short windowX = 640, windowY = 360;

		Config config;
		string windowTitle;

		void loadConfig();

		void initialize() override;
		void draw(const GameTime* gameTime) override;
		void update(const GameTime* gameTime) override;
	};
}
