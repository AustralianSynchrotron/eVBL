Software to save and analyse diffraction pattern images from the Australian Synchrotron Educational Virtual Beam Line (eVBL) area detectors.

Developing
----------

1. Install [Qt5](http://qt-project.org/downloads) and [CMake](http://www.cmake.org/cmake/resources/software.html) if you don't have them already.
2. If on Windows, add the CMake and MinGW bin directories to your `PATH` environment variable. They will be something like
  
  ```bat
  C:\Program Files\CMake 2.8\bin
  C:\Qt\Qt5.0.2\Tools\MinGW\bin
  ```
  
3. Clone the repository:

  ```bash
  git clone https://github.com/AustralianSynchrotron/eVBL.git
  ```

4. Download dependencies:

  ```bash
  git submodule init
  git submodule update
  ```

5. Compile opencv.

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

6. Add to your `PATH` environment variable:
  
  ```bash
  /path/to/project/src/opencv/install/debug/bin
  ```
