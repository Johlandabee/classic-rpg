#include "h/GameTime.h"
#include <thread>

GameTime::GameTime(bool const& isFixedFps, double const& desiredFps) {
	isFixedFps_ = isFixedFps;
	desiredFps_ = desiredFps;

	frameCount_ = 0;

	dMinFrameTime_ = duration<double>(1. / desiredFps_);

	tframeBegin_ = system_clock::now();
	tframeEnd_ = system_clock::now();

	tStart_ = system_clock::now();
}

/*-----------------------------------------------------------------------------------------------*/
GameTime::~GameTime() {
}

/*-----------------------------------------------------------------------------------------------*/
void GameTime::begin() {
	tframeBegin_ = system_clock::now();
}

/*-----------------------------------------------------------------------------------------------*/
void GameTime::end() {
	tframeEnd_ = system_clock::now();
	dFrameTime_ = elapsed();

	if(isFixedFps_) {
		wait();
	}

	if(frameCount_ >= LONG_MAX - 1) {
		frameCount_ = 0;
	}

	frameCount_++;
}

/*-----------------------------------------------------------------------------------------------*/
void GameTime::wait() const {
	if(dFrameTime_ < dMinFrameTime_) {
		this_thread::sleep_for(dMinFrameTime_ - dFrameTime_);
	}
}

/*-----------------------------------------------------------------------------------------------*/
double GameTime::fps() const
{	
	auto s = duration_cast<seconds>(runTime()).count();
	auto f = frameCount_;

	double fps = 0;

	if(f > 0 && s > 0) {
		fps = f / s;
	}

	return fps;
}

/*-----------------------------------------------------------------------------------------------*/
duration<double> GameTime::frameTime() const {
	return dFrameTime_;
}

/*-----------------------------------------------------------------------------------------------*/
double GameTime::frameTimeNs() const {
	return duration_cast<nanoseconds>(dFrameTime_).count();
}

/*-----------------------------------------------------------------------------------------------*/
duration<double> GameTime::elapsed() const {
	return (system_clock::now() - tframeBegin_);
}

/*-----------------------------------------------------------------------------------------------*/
duration<double> GameTime::runTime() const {
	return (system_clock::now() - tStart_);
}
