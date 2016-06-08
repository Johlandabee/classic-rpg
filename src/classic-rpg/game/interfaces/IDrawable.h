#pragma once
#include "IEntity.h"
#include "../Camera.h"
#include "../Console.h"
#include "../Tile.h"

namespace Engine
{

    class IDrawable : public IEntity {
    protected:
        Tile tile;

    public:
        IDrawable() = default;

        int getDisplay() const;
        BackgroundColors getBgColor() const;
        ForegroundColors getFgColor() const;

        void setDisplay(const int& asciiCode);
        void setBgColor(const BackgroundColors& bgColor);
        void setFgColor(const ForegroundColors& fgColor);
        bool isCameraScope(const Camera* camera) const;

        virtual ~IDrawable() = default;
        virtual void draw(const Console* console) = 0;
    };
}
