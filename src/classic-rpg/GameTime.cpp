#include "lib/GameTime.h"

GameTime::GameTime() {
	update();
}


GameTime::~GameTime() {
}

void GameTime::update() {
	time_stamp = high_resolution_clock::now();
}

__int64 GameTime::elapsed() const {
	return duration_cast<microseconds>
		((high_resolution_clock::now()) - time_stamp).count();
}

