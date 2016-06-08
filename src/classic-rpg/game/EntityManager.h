#pragma once
#include "Console.h"
#include "List.h"
#include "interfaces/IEntity.h"

namespace Engine
{
    class EntityManager
    {
        Common::List<IEntity*> entites;

    public:
        EntityManager();
        ~EntityManager();

        uint getCount() const;
        void add(IEntity* entity);
        void remove(IEntity* entity);

        void update(const GameTime* gameTime);
        void draw(const Console* console);
    };
}

