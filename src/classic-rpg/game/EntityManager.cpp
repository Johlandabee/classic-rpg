#include "EntityManager.h"
#include "interfaces/IDrawable.h"

using namespace Engine;

EntityManager::EntityManager()
{
}


EntityManager::~EntityManager()
{
}

uint Engine::EntityManager::getCount() const {
    return entites.count();
}

void EntityManager::add(IEntity* entity) {
    if (entity == nullptr)
        throw logic_error("null entity passed");
    
    entites.add(entity);
}

void EntityManager::remove(IEntity* entity) {
    if (entity == nullptr)
        throw logic_error("null entity passed");

    entites.remove(entity);
}

void EntityManager::update(const GameTime* gameTime) {
    for (auto i = 0; i < entites.count(); i++) {
        entites[i]->update(gameTime);
    }
}

void EntityManager::draw(const Console* console) {
    for (auto i = 0; i < entites.count(); i++) {
        auto entity = entites[i];
        auto drawable = dynamic_cast<IDrawable*>(entity);

        if(drawable != nullptr && console->getCamera()->contains(entity->getPosition())) {
            drawable->draw(console);
        }
    }
}
