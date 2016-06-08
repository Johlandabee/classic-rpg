#include "Rectangle.h"
#include <windows.h>

using namespace Engine;

Rectangle::Rectangle() {
}

Rectangle::~Rectangle() {
}

bool Engine::Rectangle::contains(const point& position) const {
    POINT point = { position.X, position.Y };
    RECT rect = { this->position.X, this->position.Y, width, height };
    
    return PtInRect(&rect, point);
}

int Rectangle::surface() const {
    return width*height;
}
