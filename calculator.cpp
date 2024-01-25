#include "utils.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
  float num1, num2, result = 0.0;
  char op;
  bool valid_input = false;

  num1 = input<float>("Enter the first number: ");
  num2 = input<float>("Enter the second number: ");

  do {
    std::cout << "Enter mathematical operator (+, -, *, /, %): ";

    if (std::cin >> op) {
      if (!std::cin.eof() && std::cin.peek() != '\n') {
        // input extraction was successfull but buffer
        // still contains extraneous input.
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

        std::cout << "Invalid mathematical operator. Please try again\n\n";
        continue;
      }

      switch (op) {
      case '+':
        result = num1 + num2;
        valid_input = true;
        break;
      case '-':
        result = num1 - num2;
        valid_input = true;
        break;
      case '*':
        result = num1 * num2;
        valid_input = true;
        break;
      case '/':
        result = num1 / num2;
        valid_input = true;
        break;
      case '%':
        result = (int)num1 % (int)num2;
        valid_input = true;
        break;
      default:
        std::cout << "Invalid mathematical operator. Please try again\n\n";
        valid_input = false;
        break;
      }
    }

  } while (!valid_input);

  std::cout << num1 << op << num2 << "=" << result << endl;
  return 0;
}