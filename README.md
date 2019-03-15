This software package is the reference software for Rec. ITU-T H.265 | ISO/IEC 23008-2 High efficiency video coding (HEVC). The reference software includes both encoder and decoder functionality.

Reference software is useful in aiding users of a video coding standard to establish and test conformance and interoperability, and to educate users and demonstrate the capabilities of the standard. For these purposes, this software is provided as an aid for the study and implementation of Rec. ITU-T H.265 | ISO/IEC 23008-2 High efficiency video coding.

The software has been jointly developed by the ITU-T Video Coding Experts Group (VCEG, Question 6 of ITU-T Study Group 16) and the ISO/IEC Moving Picture Experts Group (MPEG, Working Group 11 of Subcommittee 29 of ISO/IEC Joint Technical Committee 1).

A software manual, which contains usage instructions, can be found in the "doc" subdirectory of this software package.

# How to use
This is a cmake version of project HM16.20 converted with [cmakeconverter](https://github.com/algorys/cmakeconverter). The cmake files can be used for compiliation, code hinting or any other purposes.

## With plain cmake
```
git clone https://github.com/chjz1024/HM_vc2015.git && cd HM_vc2015/build
cmake -DCMAKE_BUILD_TYPE=Debug|Release .
make
```

## With CLion
Open -> path_to_HM_vc2015 -> load build/CMakeLists.txt -> Build

### Loading pytorch in this project
Download libtorch
Add libtorch to system path
Add `find_package(Torch REQUIRED)` and `target_link_libraries(your-project "${TORCH_LIBRARIES}")` to the project you want to use libtorch in build/vc2015/CMakeLists.txt

Details: [https://pytorch.org/tutorials/advanced/cpp_export.html](https://pytorch.org/tutorials/advanced/cpp_export.html)