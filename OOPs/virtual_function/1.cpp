/*
Definition
A virtual function is a special type of member function that, when called, resolves to the most-derived version of the function for the actual type of the object being referenced or pointed to.

Rules:

A derived function is considered a match if it has the same signature (name, parameter types, and whether it is const) and return type as the base version of the function. Such functions are called overrides.
To make a function virtual, place the “virtual” keyword before the function declaration.
*/

#include<iostream>
#include<string>

class Base{
    public:
        virtual std::string getName() const {return "Base";}

};

class Derived: public Base
{
    public:
        virtual std::string getName() const {return "Derived";}

};

int main(){
    Derived derived{};

    std::cout<<"derived first "<<derived.getName()<<"\n";
    Base& rBase{ derived };
    std::cout << "rBase is a " << rBase.getName() << '\n'; // if u remove virtual we get Base else Derived
    return 0;
}