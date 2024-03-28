#pragma once

#include "ofMain.h"
#include "starParticle.h"

using namespace std;

class starSystem {

    public:

        static ofVec2f DRAG_FORCE; 

        starSystem(int size);
        void seedRandomStars(default_random_engine engine);
        void update();
        void draw();
    
    private:
        vector<starParticle*> stars;
        int size;
};