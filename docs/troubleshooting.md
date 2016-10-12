#Troubleshooting

Here are a couple of common issues and how to solve them.



-
###ofxCvPiCam
If you run into compiler errors with the [ofxCVPiCam](https://github.com/orgicus/ofxCvPiCam/) library on RPi2. Its because the MMAL Libraries have changed slightly. 

You can resolve these issues by following [this guide] (https://github.com/orgicus/ofxCvPiCam/issues/3). Or for the short version just rename the libs folder in the ofxCvPiCam folder.

```
cd ~/openFrameworks/addons/ofxCvPiCam/
mv libs old-libs
```

-
###openFrameworks
During installing if you encountered boost copy file error that means there is conflicting boost library between system and openFrameworks.
```
Description	Resource	Path	Location	Type
undefined reference to `boost::filesystem::detail::copy_file(boost::filesystem::path const&, boost::filesystem::path const&, boost::filesystem::detail::copy_option, boost::system::error_code*)'	RPi2		line 502, external location: /usr/local/include/boost/filesystem/operations.hpp	C/C++ Problem
```

To solve this we need to remove the default outdated boost library in system.

```
sudo apt-get purge libboost1.54-dev
sudo apt-get autoremove
```
For linux 32-bit, It is recommended to use gcc version >= 4.9.

Error when playing video file.
```
[ error ] ofPixels: format doesn't support channels
```
Install gstreamer to solve this.

-
###ofxCv
Encountered this error during linking, though we have an opencv installed in the system.
```
undefined reference to cv::string(***)
```
We found that in Eclipse there is a conflicting opencv library between system and openframework.
Edit the config.make of the current project, then adds
```
PROJECT_CFLAGS = -I$(PROJECT_ROOT)/addons/ofxOpenCv/libs/opencv/include/opencv
```
This will force the compiler to always look for the openFrameworks's opencv header files.
Surprisingly, once this fix is compiled and then removed after, the error is fixed.


-
###Eclipse plugin for openFrameworks
There is an error in the plugin script when we add an addons.
To solve this, open Help-Installation details and find openFrameworks then performs update.

###QtCreator
Qtcreator version 3.6.1 for 64-bit and 3.5.1 for 32-bit are used for compatilbility with openFrameworks v0.9.3.

Error libmpg123
```
libmpg123 not found
```
Install:
```
sudo apt-get install libmpg123-dev
```

Found an error of
```
error: unrecognized command line option ‘-std=gnu++14’
```
Install newer gcc and g++ compilers, in this case 4.9 for openframeworks compatibility.
```
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install gcc-4.9 g++-4.9
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.9 60 --slave /usr/bin/g++ g++ /usr/bin/g++-4.9
```
check gcc version
```
sudo update-alternatives --config gcc
```
Then compile again openframeworks