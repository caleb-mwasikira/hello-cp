#include <iostream>

using namespace std;

int main() {
    int first_num, second_num, remainder;
    float result;

    cout << "A program to calculate the remainder when two numbers are divided" << endl;
    cout << "Enter your two numbers: ";
    cin >> first_num >> second_num;

    result = first_num / second_num;
    remainder = first_num % second_num;
    cout << first_num << " / " << second_num << " = " << result << " remainder " << remainder << endl;
    return 0;
}