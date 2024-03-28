#include "starParticle.h"

starParticle::starParticle(ofVec2f* pos, ofVec2f* momentum, double mass, ofColor color, double size) 
    : circleParticle(pos, momentum, mass, color, size)
{

}

void starParticle::draw() 
{
    ofFill();
    ofSetColor(this->color);
    ofDrawCircle(*this->pos, this->size/2);

    ofNoFill();
    int maxAuraRadius = size*2;
    for (int i = size/2; i <= maxAuraRadius; i++) {
        ofSetColor(color, (maxAuraRadius-i)*(255/maxAuraRadius));
        ofDrawCircle(*this->pos, i);
    }
}