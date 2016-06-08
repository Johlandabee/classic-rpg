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

        virtual void update(const GameTime* gameTime) = 0;
    }; 
}


