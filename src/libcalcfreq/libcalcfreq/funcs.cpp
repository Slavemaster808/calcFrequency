#include <libcalcfreq/funcs.hpp>

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>

namespace cfrq {
void strToLower(std::string& str) {
  std::transform(str.begin(), str.end(), str.begin(), [](unsigned char ch) {
    return std::tolower(ch);
  });
}

void calcfreq(const std::string& input, const std::string& output) {
  std::ifstream inp(input);

  std::string word;
  std::map<std::string, int> result;
  while (inp >> word) {
    strToLower(word);
    result[word]++;
  }

  std::multimap<int, std::string, std::greater<int>> reverseResult;
  for (auto it = result.begin(); it != result.end(); it++) {
    reverseResult.insert({it->second, it->first});
  }

  std::ofstream out(output, std::ios_base::app);
  for (auto it = reverseResult.begin(); it != reverseResult.end(); it++) {
    out << it->second << " " << it->first << '\n';
  }
}
}  // namespace cfrq