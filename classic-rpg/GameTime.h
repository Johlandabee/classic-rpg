#pragma once
#include <chrono>
using namespace std::chrono;

class GameTime
{
public:
	GameTime();
	~GameTime();

	void update();
	__int64 elapsed() const;
private:
	high_resolution_clock::time_point time_stamp;
};

