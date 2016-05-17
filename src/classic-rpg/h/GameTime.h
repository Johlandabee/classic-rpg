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
	void wait() const;
	double fps() const;

	duration<double> frameTime() const;
	duration<double> elapsed() const;

private:
	system_clock::time_point tframeBegin_, tframeEnd_, tStart_;
	duration<double> dFrameTime_, dMinFrameTime_;

	bool isFixedFps_;
	double desiredFps_;
};

