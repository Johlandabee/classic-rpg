#pragma once
#include <chrono>

using namespace std;
using namespace chrono;

namespace Engine
{
    class GameTime {
    public:
        explicit GameTime(bool const& isFixedFrameRate, double const& desiredFrameRate);
        ~GameTime();

        void begin();
        void end();

        duration<double> frameTime() const;
        duration<double> elapsed() const;
        duration<double> elapsedSinceBegin() const;

        double fps() const;
        double internalFrameTimeNs() const;
        double completeFrameTimeMs() const;

    private:
        void wait() const;

        system_clock::time_point frameBegin, start;
        duration<double> internalFrameTime, minFrameTime, completeFrameTime;

        bool isFixedFps;
        double desiredFps;
    };

}