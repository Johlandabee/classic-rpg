#pragma once
class GameTime;

class IDrawable {
public:
	virtual ~IDrawable() {}
	virtual void update(const GameTime& gameTime) {}
	virtual void draw() {}
};
