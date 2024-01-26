#include <algorithm>
#include <iostream>
#include <limits>

/*
Asks the user for input type T. Accepts only type T values >= min limit and <=
max limit
*/
template <typename T>
T input(std::string prompt, T min = std::numeric_limits<T>::lowest(),
        T max = std::numeric_limits<T>::max()) {
  T n;

  while (true) {
    std::cout << prompt;

    if (std::cin >> n) {
      if (!std::cin.eof() && std::cin.peek() != '\n') {
        // input extraction was successfull but buffer
        // still contains extraneous input.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Invalid entry. Please try again.\n\n";
        continue;
      }

      if (n < min || n > max) {
        std::cout << "Input not within range of " << min << " -> " << max
                  << ". Please try again\n\n";
        continue;
      }

      return n;
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid entry. Please try again.\n\n";
  }
}

/*
Asks the user a yes or no question
*/
bool yes_no_input(std::string prompt);
