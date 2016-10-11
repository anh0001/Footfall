#How to Install Openframeworks with QtCreator:

##Requirements:
1. Openframeworks v0.9.3
2. QtCreator v3.6.1 for 64-bit
3. QtCreator v3.5.1 for 32-bit

##Installation:
- Install gcc and g++ version 4.9:
```
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
```
or, with system proxy
```
sudo -E add-apt-repository ppa:ubuntu-toolchain-r/test
```
```
sudo apt-get update
sudo apt-get install gcc-4.9 g++-4.9
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.9 60 --slave /usr/bin/g++ g++ /usr/bin/g++-4.9
```

- Install dependencies
```
cd OF/scripts/linux/ubuntu
```
```
sudo install_dependencies.sh
```
or, with system proxy
```
sudo -E install_dependencies.sh
```

- Compile openframeworks
```
cd OF/scripts/linux
./compileOF.sh
```

- Install QtCreator
```
./qt-creator-xxx.run
```

- Connect QtCreator with Openframeworks
```
cd OF/scripts/qtcreator
./install_template.sh
```

- Error libmpg123 not found
```
sudo apt-get install libmpg123-dev
```
