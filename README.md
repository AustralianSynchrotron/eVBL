Software to save diffraction pattern images from the Australian Synchrotron Educational Virtual Beam Line (eVBL) area detectors.

Developing
----------

To fetch the source code for developing:

1. Clone the repository:

  ```bash
  git clone https://github.com/AustralianSynchrotron/eVBL.git
  ```

2. Download dependencies:

  ```bash
  git submodule init
  git submodule update
  ```

3. Compile opencv:

  On Windows:

  ```bat
  cd src\opencv
  mkdir build
  cd build
  cmake -G "MinGW Makefiles" -D CMAKE_BUILD_TYPE=DEBUG -D BUILD_opencv_python=OFF -D CMAKE_INSTALL_PREFIX="%CD%\..\install\debug" ..
  mingw32-make install
  ```

  On Linux/Mac OS X:
  
  ```bash
  cd src/opencv
  mkdir -p install/debug build
  cd build
  cmake -D CMAKE_BUILD_TYPE=DEBUG -D BUILD_opencv_python=OFF -D CMAKE_INSTALL_PREFIX="$(pwd)/../install/debug" ..
  make install
  ```
