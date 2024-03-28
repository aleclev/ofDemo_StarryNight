#pragma once

#include "circleParticle.h"

class starParticle : public circleParticle {

    public:
        starParticle(ofVec2f* pos, ofVec2f* momentum, double mass, ofColor color, double size);
        virtual void draw();
};