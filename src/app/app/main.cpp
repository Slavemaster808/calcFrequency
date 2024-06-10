#include <libcalcfreq/funcs.hpp>

#include <cxxopts.hpp>

#include <iostream>
#include <vector>
int main(int argc, char** argv) {
  cxxopts::Options options("./app", "Calculate frequency of words in a file.");
  options.add_options()(
      "f, file", "", cxxopts::value<std::vector<std::string>>())(
      "h, help", "Usage:\n--file [filename] --file [filename]\n");

  auto result = options.parse(argc, argv);

  if (result.arguments().empty()) {
    std::cout << options.help();
  }
  if (result.count("help") > 0U) {
    std::cout << options.help();
  }

  if (result.count("file") > 1) {
    std::vector<std::string> files =
        result["file"].as<std::vector<std::string>>();
    // std::cout << "File1: " << files[0] << " File2:" << files[1] << '\n';
    cfrq::calcfreq(files[0], files[1]);
  } else {
    std::cout << options.help();
  }
}