#include <iostream>

using namespace std;

int main() {
    int first_num, second_num, sum;

    cout << "Enter two intergers: ";
    cin >> first_num >> second_num;

    sum = first_num + second_num;
    cout << first_num << " + " << second_num << " = " << sum << endl;
    return 0;
}