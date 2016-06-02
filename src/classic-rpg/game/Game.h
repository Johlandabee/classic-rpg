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

        Config config;
        string title;

        void draw(GameTime* gameTime) override;
        void initialize() override;
        void loadConfig();
        void update(GameTime* gameTime) override;
    };
}
