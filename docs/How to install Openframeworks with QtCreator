#How to Install Openframeworks with QtCreator:

1. Install gcc and g++ version 4.9:
```
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install gcc-4.9 g++-4.9
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.9 60 --slave /usr/bin/g++ g++ /usr/bin/g++-4.9
```

2. Install dependencies
```
cd OF/scripts/linux/ubuntu
sudo install_dependencies.sh
or
sudo -E install_dependencies.sh  # with proxy
```

3. Compile openframeworks
```
cd OF/scripts/linux
./compileOF.sh
```

4. Install QtCreator
```
./qt-creator-opensource-linux-x86_64-3.6.1.run
```

5. Connect QtCreator with Openframeworks
```
cd OF/scripts/qtcreator
./install_template.sh
```

6. Error libmpg123 not found
```
sudo apt-get install libmpg123-dev
```
