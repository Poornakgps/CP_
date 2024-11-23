#include <iostream>
// improper behaviour without virtual for destructor for destructor A
class A {
public:
    virtual ~A() { std::cout << "A's destructor called\n"; }
};

class B : public A {
public:
    ~B() { std::cout << "B's destructor called\n"; }
};

int main() {
    A* ptr = new B(); // Create a derived object
    delete ptr;        // Deletes through base class pointer
    return 0;
}
