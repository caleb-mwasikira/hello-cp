#include <iostream>

using namespace std;

class Base {
 public:
  virtual void print() { cout << "Hello from base class" << endl; }
};

class Derived : public Base {
 public:
  void print() override { cout << "Hello from derived class" << endl; }
};

int main() {
  Base baseClass = Base();
  Derived derivedClass = Derived();

  baseClass.print();
  derivedClass.print();

  // Testing our override function
  Derived derivedClass2;
  Base *baseClass2 = &derivedClass2;
  baseClass2->print();
  return 0;
}