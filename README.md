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

  ```bash
  cd src/opencv
  ```

  On Windows:

  ```
  cmake -G "MinGW Makefiles"
  ```

  On Linux/Mac OS X:
  
  ```
  cmake CMakeLists.txt
  ``` 
