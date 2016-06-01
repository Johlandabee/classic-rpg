#include "h/GameTime.h"
#include <thread>

GameTime::GameTime(bool const& isFixedFps, double const& desiredFps) {
	this->isFixedFps = isFixedFps;
	this->desiredFps = desiredFps;

	minFrameTime = duration<double>(1. / desiredFps);
	frameBegin = system_clock::now();

	start = system_clock::now();
}

GameTime::~GameTime() {
}


void GameTime::begin() {
	frameBegin = system_clock::now();
}

void GameTime::end() {
	internalFrameTime = elapsed();

	if (isFixedFps) {
		wait();
	}

	completeFrameTime = elapsed();
}

void GameTime::wait() const {
	if (internalFrameTime < minFrameTime) {
		this_thread::sleep_for(minFrameTime - internalFrameTime);
	}
}

double GameTime::fps() const {
	return 1 / completeFrameTime.count();
}


duration<double> GameTime::frameTime() const {
	return internalFrameTime;
}


double GameTime::internalFrameTimeNs() const {
	return duration_cast<nanoseconds>(internalFrameTime).count();
}

double GameTime::completeFrameTimeMs() const {
	return duration_cast<milliseconds>(completeFrameTime).count();
}

duration<double> GameTime::elapsed() const {
	return (system_clock::now() - frameBegin);
}


duration<double> GameTime::elapsedSinceBegin() const {
	return (system_clock::now() - start);
}
