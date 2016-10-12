#add lines
export GST_VERSION=1.0
export RPI_ROOT=/home/user/codes/RPI_ROOT/rootfs
export RPI_TOOLS=/home/user/codes/RPI_ROOT/crosscompiler/bin
export TOOLCHAIN_ROOT=/home/user/codes/RPI_ROOT/crosscompiler/bin
export PLATFORM_OS=Linux
export PLATFORM_ARCH=armv6l
export PKG_CONFIG_PATH=$RPI_ROOT/usr/lib/arm-linux-gnueabihf/pkgconfig:$RPI_ROOT/usr/share/pkgconfig:$RPI_ROOT/usr/lib/pkgconfig

make
