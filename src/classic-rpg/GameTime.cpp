#include "h/GameTime.h"
#include <thread>

GameTime::GameTime(bool const& isFixedFps, double const& desiredFps) {

	isFixedFps_ = isFixedFps;
	desiredFps_ = desiredFps;

	dMinFrameTime_ = duration<double>(1. / desiredFps_);

	tframeBegin_ = system_clock::now();
	tframeEnd_ = system_clock::now();
}

/*-----------------------------------------------------------------------------------------------*/
GameTime::~GameTime() {
	tStart_ = system_clock::now();
}

/*-----------------------------------------------------------------------------------------------*/
void GameTime::begin() {
	tframeBegin_ = system_clock::now();
}

/*-----------------------------------------------------------------------------------------------*/
void GameTime::end() {
	tframeEnd_ = system_clock::now();
	dFrameTime_ = elapsed();
}

/*-----------------------------------------------------------------------------------------------*/
void GameTime::wait() const {
	if(elapsed() < dMinFrameTime_) {
		this_thread::sleep_for(dMinFrameTime_ - dFrameTime_);
	}
}

/*-----------------------------------------------------------------------------------------------*/
double GameTime::fps() const
{	
	// Todo
	return 0.0;
}

/*-----------------------------------------------------------------------------------------------*/
duration<double> GameTime::frameTime() const {
	// Todo: return actual average milliseconds
	return dFrameTime_;
}

/*-----------------------------------------------------------------------------------------------*/
duration<double> GameTime::elapsed() const {
	return (tframeBegin_ - system_clock::now());
}
