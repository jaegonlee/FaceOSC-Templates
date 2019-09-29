// ofxFaceTrack2 example: SIMPLE EXAMPLE
//
// This example shows minimal usage of the ofxFaceTracker2 addon,
// doing simple landmark detection and pose estimation
//

#pragma once

#include "ofMain.h"
#include "ofxFaceTracker2.h"
#include "ofxOsc.h"
#include "FaceOSC.h"

class ofApp : public ofBaseApp{
public:

    void clearBundle();
    //template <class T>
    void addMessage(string s, ofVec3f p);
    void addMessage(string s, ofVec2f p);
    void addMessage(string s, int i);
    void addMessage(string s, float f);
    void sendBundle();

    void setup();
    void update();
    void draw();
    
    string host;
    int port;
    ofxOscSender osc;
    ofxOscBundle bundle;
    
    
    ofxFaceTracker2 tracker;
    ofVideoGrabber grabber;
};
