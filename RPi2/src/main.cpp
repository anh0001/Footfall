#include "ofMain.h"
#include "ofApp.h"
//========================================================================
int main( ){

	ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetupOpenGL(320,240, OF_WINDOW);			// <-------- setup the GL context
    //ofSetupOpenGL(980,660, OF_WINDOW);			// For desktop
	ofRunApp( new ofApp());
}
