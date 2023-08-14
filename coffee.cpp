#include <iostream>

using namespace std;


int main() {
  char coffee_grade;
  string message;

  bool valid_input = false;
  do {
    cout << "Please enter your coffee grade: ";
    cin >> coffee_grade;

    switch (coffee_grade) {
      case 'A':
        cout << "Export quality" << endl;
        valid_input = true;
        break;
      case 'B':
        cout << "Local market" << endl;
        valid_input = true;
        break;
      case 'C':
        cout << "Good for blending" << endl;
        valid_input = true;
        break;

      default:
        cout << coffee_grade << " is not a valid coffee grade" << endl;
        valid_input = false;
        break;
    }

  } while (!valid_input);

  return 0;
}