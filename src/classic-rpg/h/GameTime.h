#pragma once
#include <chrono>

using namespace std;
using namespace chrono;

class GameTime {
public:
	explicit GameTime(bool const& isFixedFrameRate, double const& desiredFrameRate);
	~GameTime();

	void begin();
	void end();
	double fps() const;

	duration<double> frameTime() const;
	duration<double> elapsed() const;
	duration<double> runTime() const;

	double frameTimeNs() const;

private:
	void wait() const;

	system_clock::time_point tframeBegin, tframeEnd, tStart;
	duration<double> dFrameTime, dMinFrameTime;

	bool isFixedFps;
	double desiredFps;
	long frameCount;
};
