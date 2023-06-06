#include <iostream>

using namespace std;

// Asks for user input, accepting only integer values
int int_input(string message) {
    int number;

    while(true) {
        cout << message;
        cin >> number;

        // cin.fail() checks to see if the value in the cin stream is
        // the correct type, if not it returns true, false otherwise.
        if(!cin.fail())
            break;

        cin.clear();
        cin.ignore();
        cout << "Please enter a valid number" << endl;
    }

    return number;
}


int main() {
    int number = int_input("Enter a valid number: ");

    cout << "You entered the integer: " << number << endl;
    return 0;
}