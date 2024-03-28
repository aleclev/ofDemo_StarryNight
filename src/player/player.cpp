#include "player.h"

Player::Player(Asteroid * asteroid, ofVec2f * momentum)
{
    this->asteroid = asteroid;
    this->playerMomentum = momentum;
    
}

void Player::update()
{
    updateMomentum();
    updatePosition();
}

// TODO: encapsulation breach. Player manipulates momentum vector directly.
void Player::updateMomentum()
{
    ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());

    ofVec2f playerPos = *(this->asteroid->getPosition());

    *playerMomentum = (mousePos - playerPos) * Asteroid::DECELERATION_DAMPING;

    *playerMomentum = *playerMomentum * Asteroid::ACCELERATION_DAMPING;

}

void Player::updatePosition()
{
    asteroid->recordMovement();
    asteroid->updatePosition();
}

void Player::draw()
{
    this->asteroid->draw();
}
