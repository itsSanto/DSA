#include <iostream>
#include <vector>

std::vector<int> pushZerosToEnd(std::vector<int> numbers) {
  int c = 0;
  for (int i = 0; i < numbers.size(); ++i) {
    if (numbers[i] != 0) {
      numbers[c++] = numbers[i];
    }
  }

  while (c < numbers.size()) {
    numbers[c++] = 0;
  }

  return numbers;
}

int main() {

  auto numbers = pushZerosToEnd({1, 2, 0, 0, 7, 0, 8, 9, 0, 10});

  for (const auto &n : numbers) {
    std::cout << n << "\t";
  }
  return 0;
}