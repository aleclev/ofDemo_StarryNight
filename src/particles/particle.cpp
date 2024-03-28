#include "particle.h"
#include "ofMain.h"

using namespace std;

particle::particle(ofVec2f* pos, ofVec2f* momentum, double mass)
{
    this->pos = pos;
    this->momentum = momentum;
    this->mass = mass;
    accelerationForces = vector<ofVec2f*>();
}

void particle::addAccelerationForce(ofVec2f *force)
{
    accelerationForces.push_back(force);
}

void particle::removeAccelerationForce(ofVec2f * toRemove)
{
    vector<ofVec2f*>::iterator it = accelerationForces.begin();

    while (it != accelerationForces.end()) {
        if (*it == toRemove) {
            it = accelerationForces.erase(it);
            return;
        }

        it++;
    }
}

void particle::addLinearMovement(ofVec2f *force)
{
    linearMovementForces.push_back(force);
}

void particle::removeLinearMovement(ofVec2f * toRemove)
{

    vector<ofVec2f*>::iterator it = linearMovementForces.begin();

    while (it != linearMovementForces.end()) {
        if (*it == toRemove) {
            it = linearMovementForces.erase(it);
            return;
        }

        it++;
    }
}

void particle::updateMomentum()
{
    for (auto force: accelerationForces) {
        *momentum = (*momentum + *force/mass);
    }
}

void particle::updatePosition()
{
    *pos = *pos + *momentum;

    for (auto force: linearMovementForces) {
        *pos = *pos + *force;
    }
}

void particle::screenWrap()
{
    if (pos->x > ofGetScreenWidth()) {
        pos->x = 0;
    } 
    else if (pos->x < 0) {
        pos->x = ofGetScreenWidth() - 1;
    }

    if (pos->y > ofGetScreenHeight()) {
        pos->y = 0;
    } 
    else if (pos->y < 0) {
        pos->y = ofGetScreenHeight() - 1;
    }
}

void particle::draw() 
{

}

ofVec2f* particle::getPosition()
{
    return pos;
}
