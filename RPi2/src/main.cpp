#include <ros/ros.h>
#include "ofMain.h"
#include "ofApp.h"
//========================================================================
int main( int argc, char **argv ){

    ros::init(argc, argv, "people_counter");
	ofSetLogLevel(OF_LOG_VERBOSE);
    //ofSetupOpenGL(320,240, OF_WINDOW);			// <-------- setup the GL context
    ofSetupOpenGL(980,660, OF_WINDOW);			// <-------- setup the GL context
	ofRunApp( new ofApp());
}
