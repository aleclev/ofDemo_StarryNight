#pragma once

#include "particle.h"

class circleParticle : public particle {

    public:
        circleParticle(ofVec2f* pos, ofVec2f* momentum, double mass, ofColor color, double size);
        void setColor(ofColor color);
        void setSize(double size);

    protected:
        ofColor color;
        double size;
};