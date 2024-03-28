#include "ofApp.h"
#include "starSystem.h"

//--------------------------------------------------------------
void ofApp::setup(){

    std::cout << "setup started" << std::endl;
    starSys = new starSystem(1000);
    default_random_engine eg;
    starSys->seedRandomStars(eg);

    ofVec2f* playerMomentum = new ofVec2f(0, 0);
    ofVec2f* startingPosition = new ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()/2);

    Asteroid* playerAsteroid = new Asteroid(startingPosition, playerMomentum, 1, ofColor(255, 255, 255), 20);
    player = new Player(playerAsteroid, playerMomentum);

    std::cout << "setup finished" << std::endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    starSys->update();
    player->update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackgroundGradient(ofColor(2, 11, 91), ofColor(0, 0, 0));

    starSys->draw();
    player->draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
