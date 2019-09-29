#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    // All examples share data files from example-data, so setting data path to this folder
    // This is only relevant for the example apps
    ofSetFrameRate(60);
    //ofSetDataPathRoot(ofFile(__BASE_FILE__).getEnclosingDirectory()+"../../model/");
    
    // Setup grabber
    grabber.setup(640,480);
    
    // Setup tracker
    tracker.setup();
    //string a = "host";
    host = "localhost";
    port = 8338;
    osc.setup(host, port);
}

void ofApp::clearBundle() {
    bundle.clear();
}
//
////template <>
void ofApp::addMessage(string s, ofVec3f data) {
    ofxOscMessage msg;
    msg.setAddress(s);
    msg.addFloatArg(data.x);
    msg.addFloatArg(data.y);
    msg.addFloatArg(data.z);
    bundle.addMessage(msg);
}
////
////template <>
void ofApp::addMessage(string s, ofVec2f data) {
    ofxOscMessage msg;
    msg.setAddress(s);
    msg.addFloatArg(data.x);
    msg.addFloatArg(data.y);
    bundle.addMessage(msg);
}
////
////template <>
void ofApp::addMessage(string s, float data) {
    ofxOscMessage msg;
    msg.setAddress(s);
    msg.addFloatArg(data);
    bundle.addMessage(msg);
}
////
////template <>
void ofApp::addMessage(string s, int data) {
    ofxOscMessage msg;
    msg.setAddress(s);
    msg.addIntArg(data);
    bundle.addMessage(msg);
}


void ofApp::sendBundle() {
    osc.sendBundle(bundle);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    
    // Update tracker when there are new frames
    if(grabber.isFrameNew()){
        tracker.update(grabber);
        clearBundle();
        
        if (tracker.size() > 0) {
            addMessage("/found", 1);
//                ofVec2f position = tracker.getPosition();
//                addMessage("/pose/position", position);
//                scale = tracker.getScale();
//                addMessage("/pose/scale", scale);
//                ofVec3f orientation = tracker.getOrientation();
//                addMessage("/pose/orientation", orientation);

//                addMessage("/gesture/mouth/width", tracker.getGesture(ofxFaceTracker::MOUTH_WIDTH));
//                addMessage("/gesture/mouth/height", tracker.getGesture(ofxFaceTracker::MOUTH_HEIGHT));
//                addMessage("/gesture/eyebrow/left", tracker.getGesture(ofxFaceTracker::LEFT_EYEBROW_HEIGHT));
//                addMessage("/gesture/eyebrow/right", tracker.getGesture(ofxFaceTracker::RIGHT_EYEBROW_HEIGHT));
//                addMessage("/gesture/eye/left", tracker.getGesture(ofxFaceTracker::LEFT_EYE_OPENNESS));
//                addMessage("/gesture/eye/right", tracker.getGesture(ofxFaceTracker::RIGHT_EYE_OPENNESS));
//                addMessage("/gesture/jaw", tracker.getGesture(ofxFaceTracker::JAW_OPENNESS));
//                addMessage("/gesture/nostrils", tracker.getGesture(ofxFaceTracker::NOSTRIL_FLARE));
//            } else {
                addMessage("/found", 0);
            }

            sendBundle();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Draw camera image
    grabber.draw(0, 0);
    
    // Draw tracker landmarks
    tracker.drawDebug();
    
    
    
    // Draw estimated 3d pose
    tracker.drawDebugPose();
    
    // Draw text UI
    ofDrawBitmapStringHighlight("Framerate : " + ofToString(ofGetFrameRate()), 10, 20);
    ofDrawBitmapStringHighlight("Tracker thread framerate : "+ofToString(tracker.getThreadFps()), 10, 40);
    ofNoFill();
    ofDrawCircle(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 180);
    
#ifndef __OPTIMIZE__
    ofSetColor(ofColor::red);
    ofDrawBitmapString("Warning! Run this app in release mode to get proper performance!",10,60);
    ofSetColor(ofColor::white);
#endif
}
