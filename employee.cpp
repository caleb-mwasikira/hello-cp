#include <iostream>

using namespace std;

/*
Enums are especially useful when setting constraints on the type 
of data types allowed. By setting the gender to be of type enum
new employees can be instantiated with only the specified 
properties of this enum.
*/
enum Gender { MALE, FEMALE };

class Employee {
 private:
  int employee_id;
  double gross_salary;

 public:
  Gender gender;
};