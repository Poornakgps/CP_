#include <iostream>
#include <string>

struct Cat
{
    std::string name{ "cat" };
    int numLegs{ 4 };
};

struct Dog
{
    std::string name{ "dog" };
    int numLegs{ 4 };
};

struct Chicken
{
    std::string name{ "chicken" };
    int numLegs{ 2 };
};

int main()
{
    Cat animal;
    std::cout << "a " << animal.name << " has " << animal.numLegs << " legs\n";

    return 0;
}