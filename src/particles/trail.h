#pragma once

#include "ofMain.h"

class Trail 
{
    public:
        Trail(int size);
        void draw();
        void recordMovement(ofVec2f* vec);

    private:
        ofVec2f* posBuffer[100];
        int head = 0;
        int maxSize;
};