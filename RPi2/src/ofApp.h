// * Name: ofApp.h9*
// * Project: Footfall
// * Author: David Haylock
// * Creation Date: 20-11-2014
// * Copyright: (c) 2015 by Watershed Arts Trust Ltd.

#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include <stdio.h>
#include "ofxHttpUtils.h"
#include "Blob.h"
//#include "ofxCvPiCam.h"
#include "ofxXmlSettings.h"

#include "ros/ros.h"
#include "image_transport/image_transport.h"
#include "cv_bridge/cv_bridge.h"
#include "sensor_msgs/image_encodings.h"

using namespace ofxCv;
using namespace cv;

//#define USE_CAMERA
#define USE_ROS_CAMERA

//--------------------------------------------------------------
class myLine {
public:
    int width;
    void draw(int x, int y)
    {
        ofLine(x,y,x-width/2,y);
        ofLine(x,y,x+width/2,y);
    }
};

//--------------------------------------------------------------
class RosCamera
{
    ros::NodeHandle nh_;
    image_transport::ImageTransport it_;
    image_transport::Subscriber image_sub_;

    public:
    cv_bridge::CvImagePtr cv_ptr;

    RosCamera() : it_(nh_)
    {
        cv_ptr = NULL;
        image_sub_ = it_.subscribe("/usb_cam/image_raw", 1, &RosCamera::imageCopy, this);
    }

    void imageCopy(const sensor_msgs::ImageConstPtr& msg)
    {
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }

};

//--------------------------------------------------------------
class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void exit();
    void keyPressed(int key);
    
    void setupHttp();
    void setupCV();
    void drawConfig();
    void makeMask();
    void newResponse(ofxHttpResponse & response);
    void imageCopy(const sensor_msgs::ImageConstPtr& msg);

#ifdef USE_ROS_CAMERA
    RosCamera ros_cam;
#elif USE_CAMERA
    ofxCvPiCam cam;
#else
    ofVideoPlayer videoPlayer;
#endif

    ofxCv::ContourFinder contourFinder;
    ofxCv::RectTrackerFollower<Blob> tracker;
    cv::BackgroundSubtractorMOG2* pMOG2;
    cv::Mat frame,resizeF,fgMaskMOG2,output;
    cv::Mat mask,maskOutput;
    cv::Mat lightenMat;
    ofxHttpUtils httpUtils;
    string responseStr;
    string requestStr;
    
    bool counterLatches[30];
    int count;
    int countIn;
    int countOut;
    bool countInLatch;
    bool countOutLatch;
    
    void loadConfig();
    ofxXmlSettings XML;
    int _contourThreshold;
    int _threshold;
    int _blur;
    int _minArea;
    int _maxArea;
    int _persistance;
    int _maxDistance;
    int _minBlobSize;
    int _midBlobSize;
    int _maxBlobSize;
    int _lineYPos;
    int _lineWidth;
    int _cameraWidth;
    int _cameraHeight;
    int _history;
    int _MOGThreshold;
    int _lightenAmount;
    int _contrast;
    int _brightness;
    vector <cv::Point> _maskPoints;
    
    string _locationID;
    string _secretKey;
    string _uploadurl;
    string _uploadFileURL;
    std::deque<myLine> lines;
    std::deque<string> actions;
    ofPoint startLine;
    ofPoint endLine;
};
