#include <iostream>
#include <string>

class A
{
public:
    virtual std::string getName() const { return "A"; }
};

class B : public A
{
public:
    std::string getName() const final { return "B"; } // Prevents further overrides
};

class C : public B
{
    // Attempting to override getName() here would cause a compiler error
    // std::string getName() const { return "C"; } // Prevents further overrides
};

int main()
{
    C c {};
    A& rBase{ c };
    std::cout << "rBase is a " << rBase.getName() << '\n';

    return 0;
}
