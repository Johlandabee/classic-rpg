#pragma once
#include "interfaces/IDrawable.h"
#include "Input.h"

namespace Engine
{
    class Player : public IDrawable {
    public:
        Player();
        ~Player();

        Input* input = nullptr;

        void injectInput(Input* input);

        void move(const point& position) override;
        void update(const GameTime* gameTime) override;
        void draw(const Console* console) override;
    };
}
