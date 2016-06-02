#pragma once
class GameTime;

namespace Engine
{
    class IDrawable {
    public:
        virtual ~IDrawable() {}
        virtual void update(const GameTime& gameTime) {}
        virtual void draw() {}
    };
}
