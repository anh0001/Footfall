#include "ofMain.h"
#include "ofApp.h"
//========================================================================
int main( ){

	ofSetLogLevel(OF_LOG_VERBOSE);
    //ofSetupOpenGL(320,240, OF_WINDOW);			// <-------- setup the GL context
    ofSetupOpenGL(670,510, OF_WINDOW);			// For desktop
	ofRunApp( new ofApp());
}
