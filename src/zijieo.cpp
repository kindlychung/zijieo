#include <docopt.h>
#include <iostream>
#include <simplendian.hpp>

static const char USAGE[] =
    R"(Check endianness of your architecture.

    Usage:
      check_endian (text|bool|int)
      check_endian (-h | --help)
      check_endian --version

    Options:
      -h --help     Show this screen.
      --version     Show version.
    
    Subcommands:
      text    show the result in text format, either "big" or "little"
      bool    show the result in boolean format, either "true" or "false", true means big-endian
      int    show the result in integer format, either "1" or "0", 1 means big-endian.
)";

int main(int argc, char** argv) {
    std::map<std::string, docopt::value> args = docopt::docopt(
        USAGE, {argv + 1, argv + argc}, true, "check_endian 1.0.0");
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