#include<iostream>

class Base
{
public:
    virtual void function1() {std::cout<<"function1 Base\n";};
    virtual void function2() {std::cout<<"function2 Base\n";};
};

class D1: public Base
{
public:
    void function1() override {std::cout<<"function1 D1\n";};
};

class D2: public Base
{
public:
    void function2() override {std::cout<<"function2 D2\n";};
};

int main()
{
    D1 d1 {};
    Base* dPtr = &d1;
    (*dPtr).function2();
    dPtr->function1();
    d1.function1();
    return 0;
}