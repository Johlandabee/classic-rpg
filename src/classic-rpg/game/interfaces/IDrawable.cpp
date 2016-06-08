#include "IDrawable.h"

using namespace Engine;

int IDrawable::getDisplay() const {
    return tile.display;
}

BackgroundColors IDrawable::getBgColor() const {
    return tile.backgroundColor;
}

ForegroundColors IDrawable::getFgColor() const {
    return tile.foregroundColor;
}

void IDrawable::setDisplay(const int & asciiCode)
{
    tile.display = asciiCode;
}

void IDrawable::setBgColor(const BackgroundColors & bgColor)
{
    tile.backgroundColor = bgColor;
}

void IDrawable::setFgColor(const ForegroundColors & fgColor)
{
    tile.foregroundColor = fgColor;
}
