#Raspberry pi openframeworks cross-compiling

Requiresments:
1. openframeworks arm6 v0.9.3
2. Raspberry pi 3
3. Ubuntu host

##ON THE RPI

cd
curl -O http://192.237.185.151/versions/nightly/of_v20151008_linuxarmv6l_nightly.tar.gz
mkdir openFrameworks
tar vxfz of_v20151008_linuxarmv6l_nightly.tar.gz -C openFrameworks --strip-components 1
cd /home/pi/openFrameworks/scripts/linux/debian
sudo ./install_dependencies.sh

##INSTALL SAMBA in RPI

##MOUNT PI ON UBUNTU

sudo mkdir /media/Data

sudo nano /etc/fstab
//IP-ADDRESS/Data /media/Data cifs credentials=/home/pi/.smbcredentials,iocharset=utf8 0 0

save and exit nano

##CREATE FILE TO STORE SMB USER/PASS
nano /home/pi/.smbcredentials

add RPi samba user/pass (don't add this line)
username=pi
password=raspberry

save and exit nano

##MOUNT PI
sudo mount -a

TEST
ls -al /media/Data

##COPY NECESSARY RPI CONTENTS FOR COMPILER

cd
mkdir RPI_ROOT

cd RPI_ROOT
ln -s /media/Data/etc/ etc
ln -s /media/Data/lib/ lib
ln -s /media/Data/opt/ opt

cp -Rv /media/Data/usr/ usr

#FIX HARDCORDED LINKS TO /lib
#TODO Script this: (old fixQualifiedPaths script doesn't work)

cd usr/lib/arm-linux-gnueabihf
rm libudev.so libanl.so libBrokenLocale.so libcidn.so libcrypt.so libdbus-1.so libdl.so libexpat.so libglib-2.0.so liblzma.so libm.so libnsl.so libnss_compat.so libnss_dns.so libnss_files.so libnss_hesiod.so libnss_nisplus.so libnss_nis.so libpcre.so libpng12.so.0 libresolv.so libthread_db.so libusb-0.1.so.4 libusb-1.0.so libutil.so libz.so

ln -s ../../../lib/arm-linux-gnueabihf/libanl.so.1  libanl.so        
ln -s ../../../lib/arm-linux-gnueabihf/libBrokenLocale.so.1  libBrokenLocale.so      
ln -s ../../../lib/arm-linux-gnueabihf/libcidn.so.1  libcidn.so        
ln -s ../../../lib/arm-linux-gnueabihf/libcrypt.so.1  libcrypt.so       
ln -s ../../../lib/arm-linux-gnueabihf/libdbus-1.so.3.8.13  libdbus-1.so       
ln -s ../../../lib/arm-linux-gnueabihf/libdl.so.2  libdl.so        
ln -s ../../../lib/arm-linux-gnueabihf/libexpat.so.1.6.0  libexpat.so       
ln -s ../../../lib/arm-linux-gnueabihf/libglib-2.0.so.0  libglib-2.0.so       
ln -s ../../../lib/arm-linux-gnueabihf/liblzma.so.5.0.0  liblzma.so        
ln -s ../../../lib/arm-linux-gnueabihf/libm.so.6  libm.so        
ln -s ../../../lib/arm-linux-gnueabihf/libnsl.so.1  libnsl.so        
ln -s ../../../lib/arm-linux-gnueabihf/libnss_compat.so.2  libnss_compat.so      
ln -s ../../../lib/arm-linux-gnueabihf/libnss_dns.so.2  libnss_dns.so       
ln -s ../../../lib/arm-linux-gnueabihf/libnss_files.so.2  libnss_files.so      
ln -s ../../../lib/arm-linux-gnueabihf/libnss_hesiod.so.2  libnss_hesiod.so      
ln -s ../../../lib/arm-linux-gnueabihf/libnss_nisplus.so.2  libnss_nisplus.so      
ln -s ../../../lib/arm-linux-gnueabihf/libnss_nis.so.2  libnss_nis.so       
ln -s ../../../lib/arm-linux-gnueabihf/libpcre.so.3  libpcre.so        
ln -s ../../../lib/arm-linux-gnueabihf/libpng12.so.0  libpng12.so.0       
ln -s ../../../lib/arm-linux-gnueabihf/libresolv.so.2  libresolv.so       
ln -s ../../../lib/arm-linux-gnueabihf/libthread_db.so.1  libthread_db.so      
ln -s ../../../lib/arm-linux-gnueabihf/libusb-0.1.so.4  libusb-0.1.so.4      
ln -s ../../../lib/arm-linux-gnueabihf/libusb-1.0.so.0.1.0  libusb-1.0.so       
ln -s ../../../lib/arm-linux-gnueabihf/libutil.so.1  libutil.so        
ln -s ../../../lib/arm-linux-gnueabihf/libz.so.1.2.8  libz.so  
ln -s ../../../lib/arm-linux-gnueabihf/libudev.so.1.5.0 libudev.so

cd

##CREATE CROSS COMPILER

mkdir crosscompiler
cd crosscompiler
setup necessary variables for example proxy setting
sudo chmod +x build_cross_gcc.sh
sudo ./build_cross_gcc.sh

##Compile OF
./compile_of.sh
setup necessary variables

##compile example
./compile_of_example.sh
setup necessary variables