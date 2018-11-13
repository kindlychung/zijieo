from conans import ConanFile, CMake
from pathlib import Path
import os

homedir = Path.home()
conan_dir = os.path.join(homedir, ".conan")
conan_bin_dir = os.path.join(conan_dir, "bin")
if not os.path.exists(conan_bin_dir):
    os.mkdir(conan_bin_dir)


class ZijieoConan(ConanFile):
    name = "zijieo"
    version = "1.0.3"
    license = "MIT"
    author = "kaiyin kindlychung@gmail.com"
    url = "https://github.com/kindlychung/zijieo"
    description = "Commandline tool for checking endianness"
    topics = ("endianness", "cpp")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = "shared=False"
    requires = "simplendian/1.0.0@jzien/dev", "docopt/0.6.2@conan/stable"
    generators = "cmake", "gcc"
    exports_sources = "src/*"

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="src")
        cmake.build()

    def imports(self):
        self.copy("*.h", dst="include")
        self.copy("*.hpp", dst="include")
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy("*.a", dst="bin", src="lib")
        self.copy("*.so", dst="bin", src="lib")

    def package(self):
        self.copy("*", dst="bin", src="bin")

    def deploy(self):
        self.copy("*", src="bin", dst=conan_bin_dir)
