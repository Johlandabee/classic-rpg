#pragma once
#include "interfaces/IEntity.h"
#include "Rectangle.h"

namespace Engine
{
    class Camera : public IEntity
    {
    private:
        IEntity* followEntity = nullptr;
        Rectangle rect;

    public:
        explicit Camera(const uint& posX = 0, const uint& posY = 0);
        ~Camera();

        void update(const GameTime* gameTime) override;
        void follow(IEntity* entity);
        void center(const point& position);
        void move(const point& position) override;
        
        void setSize(const uint& width, const uint& height);

        bool contains(const point& position) const;

        point getLocalSpace(const point& worldSpacePosition) const;
    };

}
