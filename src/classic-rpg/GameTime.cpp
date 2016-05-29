#include "h/GameTime.h"
#include <thread>

GameTime::GameTime(bool const& isFixedFps, double const& desiredFps) {
	this->isFixedFps = isFixedFps;
	this->desiredFps = desiredFps;

	frameCount = 0;

	dMinFrameTime = duration<double>(1. / desiredFps);

	tframeBegin = system_clock::now();
	tframeEnd = system_clock::now();

	tStart = system_clock::now();
}


GameTime::~GameTime() {
}


void GameTime::begin() {
	tframeBegin = system_clock::now();
}


void GameTime::end() {
	tframeEnd = system_clock::now();
	dFrameTime = elapsed();

	if (isFixedFps) {
		wait();
	}

	if (frameCount >= LONG_MAX - 1) {
		frameCount = 0;
	}

	frameCount++;
}


void GameTime::wait() const {
	if (dFrameTime < dMinFrameTime) {
		this_thread::sleep_for(dMinFrameTime - dFrameTime);
	}
}


double GameTime::fps() const
{
	auto s = duration_cast<seconds>(runTime()).count();
	auto f = frameCount;

	double fps = 0;

	if (f > 0 && s > 0) {
		fps = f / s;
	}

	return fps;
}


duration<double> GameTime::frameTime() const {
	return dFrameTime;
}


double GameTime::frameTimeNs() const {
	return duration_cast<nanoseconds>(dFrameTime).count();
}


duration<double> GameTime::elapsed() const {
	return (system_clock::now() - tframeBegin);
}


duration<double> GameTime::runTime() const {
	return (system_clock::now() - tStart);
}