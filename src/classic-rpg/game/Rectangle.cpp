#include "Rectangle.h"

using namespace Engine;

Rectangle::Rectangle() {
}

Rectangle::~Rectangle() {
}

bool Engine::Rectangle::contains(const point& position) const {
    if (position.X < (this->position.X + .5*this->width) && position.X > (this->position.X - (.5*this->width)) &&
        position.Y < (this->position.Y + (.5*this->height)) && position.Y >(.5*this->height))
        return true;

    return false;
}

int Rectangle::surface() const {
    return width*height;
}
