#include <iostream>

using namespace std;

int main() {
  int num1, num2, num3, total;
  float average;

  cout << "Enter three intergers: ";
  cin >> num1 >> num2 >> num3;

  total = num1 + num2 + num3;
  average = total / 3;

  cout << "Sum: " << total << endl;
  cout << "Average: " << average << endl;
  return 0;
}