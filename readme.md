# 字节序检测器 zijieo 

Commandline tool for checking endianness.

## Build

```
cd src/ && mkdir build; cd build
conan install ../..
cmake -DCMAKE_BUILD_TYPE=MinSizeRel .. && make # customize build type as you wish
```

## Install

Just copy `build/bin/check_endian` anywhere in the PATH.


## Usage

See `check_endian -h`.