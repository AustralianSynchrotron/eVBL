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
  git clone --recursive https://github.com/AustralianSynchrotron/eVBL.git
  ```

4. Compile opencv.

  On Windows:

  ```bat
  cd src\opencv
  mkdir build
  cd build
  cmake -G "MinGW Makefiles" -D CMAKE_BUILD_TYPE=DEBUG -D BUILD_opencv_python=OFF -D CMAKE_INSTALL_PREFIX="%CD%\..\install\debug" ..
  mingw32-make install
  ```

  To compile static version for release on windows change the cmake options to:
  ```bat
  cmake -G "MinGW Makefiles" -D CMAKE_BUILD_TYPE=RELEASE -DBUILD_SHARED_LIBS=NO -D BUILD_opencv_python=OFF -D WITH_QT=ON -fPIC CMAKE_INSTALL_PREFIX="%CD%\..\install\release" ..
  ```
  
  On Linux/Mac OS X:
  
  ```bash
  cd src/opencv
  mkdir -p install/debug build
  cd build
  cmake -D CMAKE_BUILD_TYPE=DEBUG -D BUILD_opencv_python=OFF -D CMAKE_INSTALL_PREFIX="$(pwd)/../install/debug" ..
  make install
  ```

5. Add to your `PATH` environment variable:
  
  ```bash
  /path/to/project/src/opencv/install/debug/bin
  ```

Deploying
---------

To build static Qt:

1. Download the Qt source code and unzip to `C:\Qt\qt-static\`.
2. Follow the instructions in `C:\Qt\qt-static\README` to install depedencies (Perl, Python, [ICU](http://qt-project.org/wiki/Compiling-ICU-with-MinGW)).
3. Edit `C:\Qt\qt-static\qtbase\mkspecs\win32-g++` [as instructed here](http://www.qtcentre.org/wiki/index.php?title=Building_static_Qt_on_Windows_with_MinGW).
4. Add to `C:\Qt\qt-static\qtbase\qmake\Makefile.win32`

  ```
  LFLAGS = -static-libgcc
  ```
5. Add to `C:\Qt\qt-static\qtmultimedia\src\src.pro`
  
  ``` 
  CONFIG += static
  ```

6. In `C:\Qt\qt-static`, run

  ```
  configure -static -release -opensource -confirm-license -nomake tests -nomake examples
  ```

7. Run `mingw32-make`.
8. [Integrate the static version of Qt to QtCreator](http://qt-project.org/wiki/How_to_build_a_static_Qt_version_for_Windows_with_gcc#0a567b9d89a882ced5936e050ef62a79).
