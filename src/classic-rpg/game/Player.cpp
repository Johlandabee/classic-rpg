#include "Player.h"

using namespace Engine;

Player::Player() {
}

Player::~Player() {
}

void Player::injectInput(Input* input) {
    this->input = input;
}

void Player::move(const point& position) {
    
}

void Player::update(const GameTime* gameTime) {

    //Movement
    if(input != nullptr) {
        if(input->isAction(PlayerMoveDown)) {
            position.Y++;
        }

        if(input->isAction(PlayerMoveLeft)) {
            position.X--;
        }

        if(input->isAction(PlayerMoveRight)) {
            position.X++;
        }

        if(input->isAction(PlayerMoveUp)) {
            position.Y--;
        }
    }



}

void Player::draw(const Console* console) {
}
