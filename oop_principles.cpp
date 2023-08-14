#include <math.h>
#include <cmath>
#include <iostream>

using namespace std;

class Shape {
 protected:
  string name;
  float area;
  float perimeter;

  void calcArea() {}

  void calcPerimeter() {}

 public:
  // Constructor:
  // primary constructor that initializes the name atrribute of our Shape class
  Shape(string _name) : name(_name) {}

  void displayDetails() {
    cout << "Shape: " << name << endl;
    cout << "Area: " << area << endl;
    cout << "Perimeter: " << perimeter << endl;
  }
};

/*
Inheritance:
Triangle class inheriting:
i.    protected properties; name, area, perimeter,
ii.   protected methods - calcArea, calcPerimeter
iii.  and public method displayDetails
of the Shape class.
*/
class Triangle : public Shape {
 private:
  float base;
  float height;
  float hypotenuse;

  /*
  Polymorphism: achieved through function overriding
  */
  void calcArea() { area = 0.5 * base * height; }

  // Overriden function
  void calcPerimeter() {
    hypotenuse =
        float(sqrt((pow(base, 2) + pow(height, 2))));  // sqrt(a^2 + b^2)
    perimeter = base + height + hypotenuse;
  }

 public:
  Triangle(float _base, float _height) : Shape("triangle") {
    base = _base;
    height = _height;

    calcArea();
    calcPerimeter();
  }

  // friend function declaration
  friend void equilateralTriangle(Triangle triangle);
};

/*
friend function definition:
Calculating the area, perimeter of an equilateral triangle which is twice
the size of a right-angled triangle
*/
void equilateralTriangle(Triangle triangle) {
  float area = 2 * triangle.area;
  float perimeter = (2 * triangle.base) + (2 * triangle.hypotenuse);

  cout << "\nShape: equilateral triangle" << endl;
  cout << "Area: " << area << endl;
  cout << "Perimeter: " << perimeter << endl;
}

int main() {
  Shape abs_shape = Shape("abstract shape");

  /*
  Inheritance:
  The right_angled_triangle object inherits the displayDetails() method
  from its parent - the Shape class - despite this method
  not being implicitly declared in its class body.
  */
  Triangle right_angled_triangle = Triangle(3, 4);
  right_angled_triangle.displayDetails();

  equilateralTriangle(right_angled_triangle);
  return 0;
}