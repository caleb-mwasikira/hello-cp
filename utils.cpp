#include "utils.h"

bool yes_no_input(std::string prompt) {
  std::string choice;

  while (true) {
    std::cout << prompt;

    if (std::cin >> choice) {
      if (!std::cin.eof() && std::cin.peek() != '\n') {
        // input extraction was successfull but buffer
        // still contains extraneous input.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Invalid entry. Please try again.\n\n";
        continue;
      }

      // Convert input to lowercase
      for (int i = 0; i < choice.length(); i++) {
        choice[i] = std::tolower(choice[i]);
      }

      std::string choices[4] = {"yes", "no", "y", "n"};
      std::string *index =
          std::find(std::begin(choices), std::end(choices), choice);

      // When the element is not found, std::find returns the end of the range
      if (index == std::end(choices)) {
        std::cout << "Invalid input. Please enter either a Y(es)/n(o) "
                     "\n\n";
        continue;
      }

      return choice == "y" || choice == "yes";
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid entry. Please try again.\n\n";
  }
}