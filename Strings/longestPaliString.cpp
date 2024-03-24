#include <iostream>
#include <string>

std::string longestPaliSubString(std::string &str) {

  auto n = str.length();
  std::string result;
  int maxLen = 0;
  int low, high;
  for (auto i = 0; i < n; i++) {
    low = i;
    high = i;

    while (low >= 0 && high < n && str[low] == str[high]) {
      if (maxLen < (high - low + 1)) {
        maxLen = high - low + 1;
        result = str.substr(low, maxLen);
      }
      --low;
      ++high;
    }

    low = i;
    high = i + 1;
    while (low >= 0 && high < n && str[low] == str[high]) {
      if (maxLen < (high - low + 1)) {
        maxLen = high - low + 1;
        result = str.substr(low, maxLen);
      }
      --low;
      ++high;
    }
  }

  return result;
}

int main() {
  std::string s{"adfsgdforgeeksskeegkrofsdf"};
  std::cout << longestPaliSubString(s);
  return 0;
}