#pragma once
#include "Config.h"
#include "Base.h"
#include "GameTime.h"
#include "EntityManager.h"
#include "Player.h"

namespace Engine
{
	class Game :
		public Base {

	public:
		explicit Game(const Config& config);
		~Game();

	private:
        EntityManager* entityManager = nullptr;
        Player player;

		bool showDebugeInfo = false;
		bool startFullscreen = false;
		bool useInputEvents = false;

		ushort windowX = 640, windowY = 360;

		Config config;
		string windowTitle;

		void loadConfig();

		void initialize() override;
		void draw(const GameTime* gameTime) override;
		void update(const GameTime* gameTime) override;
	};
}
