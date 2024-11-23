// Member function version
#include <iostream>

namespace Foo
{
    void printHi() { std::cout << "Hi!\n"; }
};

struct Date
{
    int year {};
  int month {};
    int day {};

    void print() // defines a member function named print
    {
        std::cout << year << '/' << month << '/' << day<<"\n";
    }
};

int main()
{
    Date today { 2020, 10, 14 }; // aggregate initialise our struct

    today.day = 16; // member variables accessed using member selection operator (.)
    today.print();  // member functions also accessed using member selection operator (.)

    Foo::printHi(); // no object needed
    return 0;
}

//Output: 2020/10/16