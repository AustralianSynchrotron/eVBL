Software to save and analyse diffraction pattern images from the Australian Synchrotron Educational Virtual Beam Line (eVBL) area detectors.

Developing
----------

1. Install [Qt5 **including source and MinGW**](http://qt-project.org/downloads).
2. Install [CMake](http://www.cmake.org/cmake/resources/software.html).
3. Add the MinGW and CMake `bin` directories to your `PATH` environment variable. They will be something like
  
  ```bat
  C:\Qt\Qt5.1.1\Tools\mingw48_32;C:\Program Files\CMake 2.8\bin
  ```

4. Set the following environment variables:

  ```
  CMAKE_C_COMPILER=C:\Qt\Qt5.1.1\Tools\mingw48_32\bin\gcc.exe
  CMAKE_CXX_COMPILER=C:\Qt\Qt5.1.1\Tools\mingw48_32\bin\g++.exe
  ```
  
5. Clone the repository:

  ```bash
  git clone --recursive https://github.com/AustralianSynchrotron/eVBL.git
  ```

6. Compile opencv.

  On Windows:

  ```bat
  cd src\opencv
  mkdir build
  cd build
  cmake -G "MinGW Makefiles" -D CMAKE_BUILD_TYPE=DEBUG -D BUILD_opencv_python=OFF -D CMAKE_INSTALL_PREFIX="%CD%\..\install\debug" ..
  mingw32-make install
  ```

  To compile static libraries for release on Windows change the cmake options to:
  ```bat
  cmake -G "MinGW Makefiles" -D CMAKE_BUILD_TYPE=RELEASE -D BUILD_SHARED_LIBS=NO -D BUILD_opencv_python=OFF -D CMAKE_INSTALL_PREFIX="%CD%\..\install\release" ..
  ```
  
  On Linux/Mac OS X:
  
  ```bash
  cd src/opencv
  mkdir -p install/debug build
  cd build
  cmake -D CMAKE_BUILD_TYPE=DEBUG -D BUILD_opencv_python=OFF -D CMAKE_INSTALL_PREFIX="$(pwd)/../install/debug" ..
  make install
  ```

7. Add to your `PATH` environment variable:
  
  ```bash
  /path/to/project/src/opencv/install/debug/bin
  ```

Deploying
---------

To build static Qt:

1. Download the Qt source code and unzip to `C:\Qt\Qt5.1.1-src\`.
2. Install depedencies in `C:\Qt\Qt5.1.1-src\README`:
  * [Perl](http://strawberryperl.com/)
  * [Python 2.7](http://www.python.org/download/)
  * [Ruby](http://rubyinstaller.org/downloads/)
  * [ICU](http://qt-project.org/wiki/Compiling-ICU-with-MinGW)

3. Add to your `PATH`:
  
  ```
  C:\strawberry\perl\bin;C:\Python27;C:\Ruby200\bin;C:\icu\dist\bin
  ```

4. In `C:\Qt\Qt5.1.1-src\qtbase\mkspecs\win32-g++\qmake.conf` add `-static -static-libgcc` to `QMAKE_LFLAGS`.
5. In `C:\Qt\Qt5.1.1-src\qtbase\qmake\Makefile.win32` add `-static -static-libgcc` to `LFLAGS`.
6. In `C:\Qt\Qt5.1.1-src`, run

  ```
  set INCLUDE=C:\icu\dist\include
  set LIB=C:\icu\dist\lib
  configure -static -release -opensource -confirm-license -opengl desktop -nomake tests -nomake examples -prefix C:\Qt\Qt5.1.1\5.1.1\mingw48_32-static
  mingw32-make module-qtmultimedia
  mingw32-make install
  ```

7. [Integrate the static version of Qt to QtCreator](http://qt-project.org/wiki/How_to_build_a_static_Qt_version_for_Windows_with_gcc#0a567b9d89a882ced5936e050ef62a79).
