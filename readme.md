# 字节序检测器 zijieo 

Commandline tool for checking endianness.

## Install from source

```sh
cd src/ && mkdir build; cd build
conan install ../..
cmake -DCMAKE_BUILD_TYPE=MinSizeRel .. && make # customize build type as you wish
cp bin/zijieo /usr/local/bin/ # or anywhere in your PATH
```

## Install with conan

```sh
conan install zijieo/1.0.3@jzien/dev --build zijieo
```


## Usage

See `zijieo -h`.