#include "Camera.h"

using namespace Engine;


Camera::Camera(const uint& posX, const uint& posY)
{
    position.X = posX;
    position.Y = posY;

    rect.position = position;
}


Camera::~Camera()
{
    if(followEntity != nullptr) {
        delete followEntity;
        followEntity = nullptr;
    }
}

void Camera::update(const GameTime* gameTime) {
    // Update rectangle position
    rect.position = position;

    // Follow entity if actually set
    if(followEntity != nullptr) {
        this->position.X = followEntity->getPosition().X;
        this->position.Y = followEntity->getPosition().Y;
    }
}

void Engine::Camera::follow(IEntity* entity)
{
    this->followEntity = entity;
}

void Camera::center(const point& position) {
    this->position.X = .5*position.X;
    this->position.Y = .5*position.Y;
}

void Camera::move(const point& position) {
    this->position = position;
}

void Camera::setSize(const uint& width, const uint& height) {
    rect.height = height;
    rect.width = width;
}

bool Engine::Camera::contains(const point & position) const {
    return this->rect.contains(position);
}

point Camera::getLocalSpace(const point& worldSpacePosition) const {
    point localSpacePosition;

    auto posX = worldSpacePosition.X - this->position.X;
    auto posY = worldSpacePosition.Y - this->position.Y;

    localSpacePosition.X = posX;
    localSpacePosition.Y = posY;

    return localSpacePosition;
}
