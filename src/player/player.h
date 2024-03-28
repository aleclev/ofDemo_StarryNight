#pragma once

#include "asteroid.h"
#include "ofMain.h"

class Player 
{
    public:
        Player(Asteroid*, ofVec2f*);
        void update();
        void draw();


    private:
        void updateMomentum();
        void updatePosition();
        Asteroid* asteroid;
        ofVec2f* playerMomentum;
};