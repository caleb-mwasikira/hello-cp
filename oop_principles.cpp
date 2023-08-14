#include <math.h>
#include <iostream>

using namespace std;

class Shape {
 public:
  virtual float calcArea() { return 0.0; }
  virtual float calcPerimeter() { return 0.0; }
};

/*
Inheritance: Triangle class inheriting from Shape class
*/
class Triangle : public Shape {
 private:
  float base;
  float height;
  float hypotenuse;

 public:
  Triangle(float _base, float _height) : base(_base), height(_height) {}

  /*
    Polymorphism: achieved through function overriding
  */
  float calcArea() override { return 0.5 * base * height; }

  float calcPerimeter() override {
    hypotenuse =
        float(sqrt((pow(base, 2) + pow(height, 2))));  // sqrt(a^2 + b^2)
    return base + height + hypotenuse;
  }
};

void displayDetails(Shape* shape, string name) {
  cout << "Shape: " << name << endl;
  cout << "Area: " << shape->calcArea() << endl;
  cout << "Perimeter: " << shape->calcPerimeter() << endl;
}

int main() {
  Shape* right_angled_triangle = new Triangle(3, 4);
  displayDetails(right_angled_triangle, "Right-Angled Triangle");
  cout << endl;
  return 0;
}