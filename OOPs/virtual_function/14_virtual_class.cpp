#include <iostream>

// Base class A
class A {
public:
    // Constructor of class A
    A() { 
        std::cout << "Class A constructor\n"; 
    }

    // A method in class A
    void greet() { 
        std::cout << "Hello from A\n"; 
    }
};

// Class B inherits virtually from A
class B : virtual public A {
public:
    // Constructor of class B
    B() { 
        std::cout << "Class B constructor\n"; 
    }
};

// Class C also inherits virtually from A
class C : virtual public A {
public:
    // Constructor of class C
    C() { 
        std::cout << "Class C constructor\n"; 
    }
};

// Class D inherits from both B and C
// The virtual inheritance ensures only one instance of A is used
class D : public B, public C {
public:
    // Constructor of class D
    D() { 
        std::cout << "Class D constructor\n"; 
    }
};

int main() {
    // Creating an object of class D
    D obj;  // The constructor chain begins here
    obj.greet();  // Calls the greet() function from class A (only one instance of A exists)
    return 0;
}

/*
Virtual Inheritance:

In this example, both B and C inherit from A virtually using the virtual keyword (class B : virtual public A and class C : virtual public A).
This ensures that when D inherits from B and C, only one instance of A is shared between B and C, avoiding the diamond problem.
*/