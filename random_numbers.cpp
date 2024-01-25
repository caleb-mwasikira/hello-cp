#include "utils.h"
#include <iostream>
#include <time.h>

int main() {
  int min, max;
  int n = input<int>("How many random numbers do you want? ", 0, 100);

  do {
    min = input<int>("What is the lowest limit? ");
    max = input<int>("What is your highest limit? ");

    if (max < min) {
      std::cout << "Highest limit " << max
                << " cannot be lower than lowest limit " << min
                << "\n\n";
    }
  } while (max < min);

  time_t current_time = time(NULL);
  srand((unsigned)current_time);

  std::cout << std::endl;
  std::cout << "Generating random numbers between " << min << " -> "
            << max << "..." << std::endl;

  int range = (max - min) + 1;
  for (int i = 0; i < n; i++) {
    int random = min + (rand() % range);
    std::cout << random;
    if (i != n - 1) {
      std::cout << ", ";
    }
  }
  std::cout << std::endl;

  return 0;
}