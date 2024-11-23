#include <iostream>
#include <string>
// pure virutal function makes a class abstract which cant be instantiate if we try we get error
class Base
{
public:
    std::string sayHi() const { return "Hi"; } // a normal non-virtual function
    virtual std::string getName() const { return "Base"; } // a virtual function
    virtual int getValue() const = 0; // a pure virtual function
    virtual int doSomething() = 0; // now this is a pure virtual function
};

// Derived class implementing all pure virtual functions
class Derived : public Base
{
public:
    std::string getName() const override { return "Derived"; }
    int getValue() const override { return 42; }
    int doSomething() override { return 1; }
};

int main()
{
    // Base base {}; // We can't instantiate an abstract base class, throws compile error
    // base.getValue(); // what would this do?
    Derived derived; // Now we can instantiate Derived
    std::cout << derived.Base::getName() << " " << derived.getName() << " says " << derived.sayHi() << " and has value " << derived.getValue() << '\n';
    return 0;
}
