#pragma once

#include "circleParticle.h"
#include "trail.h"
#include "ofMain.h"
#include "starParticle.h"

class Asteroid : public starParticle
{

    public:
        static constexpr double DECELERATION_DAMPING = 0.1;
        static constexpr double ACCELERATION_DAMPING = 1;

        Asteroid(ofVec2f* pos, ofVec2f* momentum, double mass, ofColor color, double size);
        void recordMovement();
        virtual void draw();

    private:
        ofColor color;
        Trail* trail;
};