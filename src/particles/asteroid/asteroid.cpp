#include "asteroid.h"
#include "circleParticle.h"
#include "starParticle.h"

Asteroid::Asteroid(ofVec2f* pos, ofVec2f* momentum, double mass, ofColor color, double size) : starParticle(pos, momentum, mass, color, size)
{
    trail = new Trail(40);
}

void Asteroid::recordMovement()
{
    this->trail->recordMovement(pos);
}

void Asteroid::draw()
{
    ofFill();
    ofSetColor(color);
    ofDrawCircle(*pos, size/2);
    trail->draw();
}
