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
-