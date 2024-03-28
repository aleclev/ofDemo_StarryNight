#include "starSystem.h"

using namespace std;

ofVec2f starSystem::DRAG_FORCE(0.1, 0);

starSystem::starSystem(int size)
{
    this->size = size;
}

void starSystem::seedRandomStars(default_random_engine engine)
{
    uniform_int_distribution<> xDistribution(0, ofGetScreenWidth());
    uniform_int_distribution<> yDistribution(0, ofGetScreenHeight());
    double size = 2;
    double mass = 1;
    ofVec2f* momentum = new ofVec2f(0, 0);
    ofColor color(255, 255, 255);


    for (int i = 0; i < this->size; i++) {
        int x = xDistribution(engine);
        int y = yDistribution(engine);

        ofVec2f* pos = new ofVec2f(x, y);

        starParticle* star = new starParticle(pos, momentum, mass, color, size);
        star->addLinearMovement(&DRAG_FORCE);

        stars.push_back(star);
    }
}

void starSystem::update()
{
    for (auto star: stars) {
        star->updateMomentum();
        star->updatePosition();
        star->screenWrap();
    }
}

void starSystem::draw()
{
    for (auto star: stars) {
        star->draw();
    }
}
