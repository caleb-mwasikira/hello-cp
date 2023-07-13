#include <cstdio>    // sprintf
#include <iomanip>   // output formatting with setw
#include <iostream>  // cout, cin, getline
#include <iterator>  // map iterators with map<>::iterator
#include <map>       // map type
#include <tuple>     // tuple type
#include <limits.h>  // INT_MAX

using namespace std;

#define MIN_SALARY 15000
#define MAX_SALARY INT_MAX

/*
Displays a tax bracket
*/
void display_tax_bracket(map<tuple<int, int>, float> tax_bracket) {
  const int output_width = 20;

  cout << "\n===== Tax Bracket =====" << endl;
  cout << setw(output_width) << left << "Range" << setw(output_width) << "Tax %"
       << endl;

  map<tuple<int, int>, float>::iterator itr;

  for (itr = tax_bracket.begin(); itr != tax_bracket.end(); ++itr) {
    tuple<int, int> tax_bracket_range = itr->first;
    float tax_percentage = itr->second;
    char str_tax_bracket_range[100];

    sprintf(str_tax_bracket_range, "%d-%d", get<0>(tax_bracket_range),
            get<1>(tax_bracket_range));

    cout << setw(output_width) << left << str_tax_bracket_range
         << setw(output_width) << tax_percentage << '\n';
  }

  cout << endl;
}

/*
Checks if a character is a numerical value
*/
bool is_integer(char _char) {
  // All integers lie between the ASCII values 48 - 57
  const int min_ascii_val = 48;
  const int max_ascii_val = 57;
  int ascii_val = _char;  // Convert char to its corresponding ASCII value

  return ascii_val >= min_ascii_val && ascii_val <= max_ascii_val;
}

/*
Validates that the salary input string is a number
greater than or equal to MIN_SALARY and less than or equal
to MAX_SALARY.

@returns A tuple<result, message>
where result == float-value if validation is successful and -1 if validation
failed and message is the success/error message
*/
tuple<float, string> validate_salary_input(string salary_input) {
  char message[100];
  const char* cstr_salary_input = salary_input.data();

  for (size_t i = 0; i < salary_input.size(); i++) {
    if (!is_integer(salary_input[i])) {
      sprintf(message, "%s is not a valid number", cstr_salary_input);
      return make_tuple(-1, message);
    }
  }

  try {
    // stof converts strings to floats. Throws an exception if string
    // cannot be converted to its corresponding float type
    float result = stof(salary_input);
    if (result < MIN_SALARY || result > MAX_SALARY) {
      sprintf(message, "Please enter a basic salary between %d and %d",
              MIN_SALARY, MAX_SALARY);
      return make_tuple(-1, message);
    }

    return make_tuple(result, "");
  } catch (const exception& e) {
    sprintf(message, "stof failed to convert %s into a floating point number",
            cstr_salary_input);
    return make_tuple(-1, message);
  }
}

/*
Calculates the tax percentage that is allocatable to the 
passed in basic salary based on the tax bracket it falls into
*/
float calc_tax_percentage(float basic_salary,
                          map<tuple<int, int>, float> tax_bracket) {
  float tax_percentage = 1.0;

  map<tuple<int, int>, float>::iterator itr;

  for (itr = tax_bracket.begin(); itr != tax_bracket.end(); ++itr) {
    tuple<int, int> tax_bracket_range = itr->first;
    if (basic_salary >= get<0>(tax_bracket_range) &&
        basic_salary <= get<1>(tax_bracket_range)) {
      tax_percentage = itr->second;
      break;
    }
  }

  return tax_percentage;
}

int main() {
  float basic_salary, tax_percentage, tax_deductions, net_salary;
  string salary_input;

  map<tuple<int, int>, float> tax_bracket;
  tax_bracket[make_tuple(MIN_SALARY, 20000)] = 0.1;
  tax_bracket[make_tuple(20000, 50000)] = 0.15;
  tax_bracket[make_tuple(50000, MAX_SALARY)] = 0.3;

  display_tax_bracket(tax_bracket);

  do {
    cout << "Enter your basic salary: ";
    getline(cin, salary_input);

    tuple<float, string> validation_result =
        validate_salary_input(salary_input);
    basic_salary = get<0>(validation_result);
    string message = get<1>(validation_result);

    if (basic_salary == -1) {
      cout << message << endl << endl;
    }

  } while (basic_salary == -1);

  tax_percentage = calc_tax_percentage(basic_salary, tax_bracket);
  tax_deductions = basic_salary * tax_percentage;
  net_salary = basic_salary - tax_deductions;

  cout << "\n===== Output =====" << endl;
  cout << "Basic salary: " << basic_salary << " Ksh" << endl;
  cout << "Tax %: " << tax_percentage << endl;
  cout << "Tax deductions: -" << tax_deductions << " Ksh" << endl;
  cout << "Net salary: " << net_salary << " Ksh" << endl;

  return 0;
}