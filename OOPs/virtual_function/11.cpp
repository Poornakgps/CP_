#include <iostream>
#include <string>

class Animal // This Animal is an abstract base class
{
protected:
    std::string m_name {};

public:
    Animal(std::string name)
        : m_name(name)
    {
    }

    const std::string& getName() const { return m_name; }
    virtual std::string speak() const = 0; // note that speak is a pure virtual function
    virtual ~Animal() = default;
};

std::string Animal::speak() const
{
    return "buzz"; // some default implementation
}

class Dragonfly: public Animal
{

public:
    Dragonfly(std::string name)
        : Animal{name}
    {
    }

    std::string speak() const override// this class is no longer abstract because we defined this function
    {
        return Animal::speak(); // use Animal's default implementation
    }
};

int main()
{
    Dragonfly dfly{"Sally"};
    std::cout << dfly.getName() << " says " << dfly.speak() << '\n';
    return 0;
}
//Output: Sally says buzz
// Note: A destructor can be made pure virtual.