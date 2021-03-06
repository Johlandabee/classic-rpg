#pragma once
#include "Keys.h"
#include "Types.h"
#include <chrono>

using namespace std::chrono;

namespace Engine
{
    class Binding {
        Keys key;
        system_clock::time_point lastCall;
        uint timeout;

    public:
        explicit Binding(Keys key, unsigned const int timeout) {
            this->key = key;
            this->timeout = timeout;
        }
        ~Binding() {
        }

        Keys getKey() const {
            return key;
        }

        bool ready() {
            if (timeout == 0 || duration_cast<milliseconds>(
                duration<double>(system_clock::now() - lastCall)).count() >= timeout) {
                lastCall = system_clock::now();
                return true;
            }

            return false;
        }

        bool pressed = false;
    };

}