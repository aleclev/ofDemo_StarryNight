#pragma once

#include "ofMain.h"

using namespace std;

class particle {
    public:

        particle(ofVec2f*, ofVec2f*, double);
        void addAccelerationForce(ofVec2f*);
        void removeAccelerationForce(ofVec2f*);

        void addLinearMovement(ofVec2f*);
        void removeLinearMovement(ofVec2f*);

        void updateMomentum();
        void updatePosition();

        void screenWrap();

        virtual void draw();

        ofVec2f* getPosition();

    protected:
        ofVec2f* pos;
        ofVec2f* momentum;
        vector<ofVec2f*> accelerationForces;
        vector<ofVec2f*> linearMovementForces;
        double mass;
};