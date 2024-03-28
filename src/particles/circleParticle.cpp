#include "circleParticle.h"

circleParticle::circleParticle(ofVec2f* pos, ofVec2f* momentum, double mass, ofColor color, double size) 
    : particle(pos, momentum, mass)
{
    this->color = color;
    this->size = size;
}

void circleParticle::setColor(ofColor color)
{
    this->color = color;
}

void circleParticle::setSize(double size)
{
    this->size = size;
}
