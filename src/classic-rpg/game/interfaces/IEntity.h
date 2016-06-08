#pragma once
#include "../GameTime.h"
#include "../Types.h"

namespace Engine {
   class IEntity {
   protected:
       // World-space position
       point position;


    public:
        IEntity() = default;
        virtual ~IEntity() = default;
        virtual point getPosition() {
            return position;
        }; 

        // move to world-space coordinate
        virtual void move(const point& position) = 0;
        virtual void update(const GameTime* gameTime) = 0;
    }; 
}


