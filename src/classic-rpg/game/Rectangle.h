#pragma once
#include "Types.h"

namespace Engine {
    class Rectangle {
    public:
        Rectangle();
        ~Rectangle();

        int height = 0, width = 0;
        point position;

        bool contains(const point& position) const;
        int surface() const;
    };
}