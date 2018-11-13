#include <docopt.h>
#include <iostream>
#include <simplendian.hpp>

static const char USAGE[] =
    R"(Check endianness of your architecture.

    Usage:
      zijieo (text|bool|int)
      zijieo (-h | --help)
      zijieo --version

    Options:
      -h --help     Show this screen.
      --version     Show version.
    
    Subcommands:
      text    show the result in text format, either "big" or "little"
      bool    show the result in boolean format, either "true" or "false", true means big-endian
      int    show the result in integer format, either "1" or "0", 1 means big-endian.
)";

int main(int argc, char** argv) {
    std::map<std::string, docopt::value> args =
        docopt::docopt(USAGE, {argv + 1, argv + argc}, true, "zijieo 1.0.5");
    std::string result = "";
    bool is_big = sipmlendian::is_big();
    if (args["text"].asBool()) {
        result = is_big ? "big" : "little";
    } else if (args["bool"].asBool()) {
        result = is_big ? "true" : "false";
    } else {
        result = is_big ? "1" : "0";
    }
    std::cout << result << "\n";
    return 0;
}