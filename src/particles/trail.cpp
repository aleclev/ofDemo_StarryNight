#include "trail.h"

Trail::Trail(int size)
{
    this->maxSize = size;

    for (int i = 0; i < size; i++)
        posBuffer[i] = new ofVec2f(200, 200);
}

void Trail::draw()
{
    ofFill();
    int thickness = 1;

    for (int i = (head+1) % maxSize; i != head; i = (i+1) % maxSize) {
        ofSetLineWidth(thickness);
        ofDrawLine(*posBuffer[i], *posBuffer[(i+1)%maxSize]);

        thickness += 1;
    }

    ofSetLineWidth(1);
}

void Trail::recordMovement(ofVec2f *vec)
{    
    head = (head+1) % maxSize;
    *posBuffer[head] = ofVec2f(*vec);
}