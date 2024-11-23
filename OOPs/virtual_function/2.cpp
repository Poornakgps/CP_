#include <iostream>
#include <string>

class A
{
public:
    virtual std::string getName() const { return "A"; }
};

class B: public A
{
public:
    std::string getName() const { return "B"; }
};

class C: public B
{
public:
    virtual std::string getName() const { return "C"; }
};

class D: public C
{
public:
    virtual std::string getName() const { return "D"; }
};
/*
Insights:

First, we instantiate a C class object.
rBase is an A reference, which we set to reference the A portion of the C object.
We call rBase.getName(). rBase.getName() evaluates to A::getName().
A::getName() is virtual, so the compiler will call the most-derived match between A and C.
In this case, that is C::getName().
It will not call D::getName(), because our original object was a C, not a D, so only functions between A and C are considered.

Note: If a function is marked as virtual, all matching overrides in derived classes are also implicitly considered virtual, even if they are not explicitly marked as such.
*/
int main()
{
    C c {};
    A& rBase{ c };
    std::cout << "rBase is a " << rBase.getName() << '\n';
    std::cout << c.getName(); // will always call C::getName

    A a { c }; // copies the A portion of c into a (don't do this)
    std::cout << a.getName(); // will always call A::getName
    return 0;
}

// Output - rBase is a C