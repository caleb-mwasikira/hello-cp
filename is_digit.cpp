#include <iostream>
#include <cctype>

using namespace std;

int main() {
    int number;

    cout << "Please enter a valid integer: ";
    cin >> number;

    cout << isdigit(number) << endl;

    if(!isdigit(number)) {
        cout << "The user input was not a valid integer" << endl;
    }

    cin.ignore();
}