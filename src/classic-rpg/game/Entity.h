#pragma once
class GameTime;

class Entity {
public:
	Entity();
	~Entity();

	void update(const GameTime& gameTime);
};
