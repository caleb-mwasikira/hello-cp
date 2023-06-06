#include <iostream>
#include <iterator>
#include <map>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <utility>

using namespace std;

#define OUTPUT_WIDTH 20
#define MAX_SALARY_LEN 10 // Max length of the users input; salary cannot be more than n
#define MIN_SALARY_VALUE 50000
#define MAX_SALARY_VALUE 200000


void display_tax_bracket(map<string, float> tax_bracket)
{
    map<string, float>::iterator itr;

    cout << "===== Tax Bracket =====\n"
         << endl;
    cout << setw(OUTPUT_WIDTH) << left << "Range" << setw(OUTPUT_WIDTH) << "Value as %" << endl;
    for (itr = tax_bracket.begin(); itr != tax_bracket.end(); ++itr)
    {
        cout << setw(OUTPUT_WIDTH) << left << itr->first << setw(OUTPUT_WIDTH) << itr->second << '\n';
    }
    cout << endl;
}

// Converts the users input; s_gross_salary into a float and then checks if the
// resulting value is within the range MIN_SALARY_VALUE - MAX_SALARY_VALUE
// Returns the converted float value if these conditions are met, -1 otherwise
float validate_s_gross_salary(char s_gross_salary[MAX_SALARY_LEN])
{
    float gross_salary;

    try
    {
        gross_salary = stof(s_gross_salary);
        if (gross_salary < MIN_SALARY_VALUE || gross_salary > MAX_SALARY_VALUE)
        {
            gross_salary = -1;
        }
    }
    catch (const exception &e)
    {
        // String provided was neither an int | float
        gross_salary = -1;
    }

    return gross_salary;
}

// Splits a string using a specified delimiter and returns a vector of the 
// first n floats within the string
vector<float> first_n_floats_from_str(string str, char del = '-', int n = 2)
{
    vector<float> values;

    stringstream ss(str);
    string word;
    while (!ss.eof())
    {
        getline(ss, word, del);

        try
        {
            float amount = stof(word);

            // push_back() function ensures that the first float found in the
            // string also appears first on the vector
            values.push_back(amount); 
        }
        catch(const std::exception& e)
        {
            // word is not of type float; do nothing
        }
        
    }
    vector<float> n_values(values.begin(), values.begin() + n);
    return n_values;
}

// Calculates the tax percentage that is allocatable to a given gross salary
// based on the tax bracket
float calc_tax_percentage(float gross_salary, map<string, float> tax_bracket)
{
    float tax_percentage = 1.0;

    map<string, float>::iterator itr;

    for (itr = tax_bracket.begin(); itr != tax_bracket.end(); ++itr)
    {
        vector<float> tax_bracket_values = first_n_floats_from_str(itr->first);

        if(gross_salary > tax_bracket_values[0] && gross_salary <= tax_bracket_values[1]) {
            tax_percentage = itr->second;
            break;
        }
    }

    return tax_percentage;
}

// A program to compute taxes
int main()
{
    float gross_salary, tax_percentage, tax_deductions, net_salary;
    char s_gross_salary[MAX_SALARY_LEN], max_tax_bracket[100];
    map<string, float> tax_bracket;

    // Defining the maximum tax bracket
    sprintf(max_tax_bracket, "40000-%d", MAX_SALARY_VALUE);

    tax_bracket["0-20000"] = 0.05;
    tax_bracket["20000-40000"] = 0.04;
    tax_bracket[max_tax_bracket] = 0.02;

    display_tax_bracket(tax_bracket);

    do
    {
        cout << "Enter your salary: ";
        cin.getline(s_gross_salary, MAX_SALARY_LEN); 

        gross_salary = validate_s_gross_salary(s_gross_salary);
        if (gross_salary == -1)
        {
            cout << "Please enter a valid number between " << MIN_SALARY_VALUE
                 << " and " << MAX_SALARY_VALUE << endl;
        }

    } while (gross_salary == -1);

    tax_percentage = calc_tax_percentage(gross_salary, tax_bracket);
    tax_deductions = gross_salary * tax_percentage;
    net_salary = gross_salary - tax_deductions;

    cout << "\n===== =====" << endl;
    cout << "Gross salary: " << gross_salary << endl;
    cout << "Tax deductions: " << tax_deductions << endl;
    cout << "Net salary: " << net_salary << endl;

    return 0;
}