#include <iostream>

// default consructor
class Foo
{
private:
    int m_x { };
    int m_y { };

public:
    Foo(int x=0, int y=0) // has default arguments
        : m_x { x }
        , m_y { y }
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
    }
};
int main()
{
    Foo foo1{};     // calls Foo(int, int) constructor using default arguments
    Foo foo2{6, 7}; // calls Foo(int, int) constructor

    return 0;
}
//Output: Foo(0, 0) constructed
//        Foo(6, 7) constructed

// overloaded constructor(more than one constructor)
#include <iostream>

class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo() // default constructor
    {
        std::cout << "Foo constructed\n";
    }

    Foo(int x, int y) // non-default constructor
        : m_x { x }, m_y { y }
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
    }
};

int main()
{
    Foo foo1{};     // Calls Foo() constructor
    Foo foo2{6, 7}; // Calls Foo(int, int) constructor

    return 0;
}

// ambiguos case
class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo() // default constructor
    {
        std::cout << "Foo constructed\n";
    }

    Foo(int x=1, int y=2) // default constructor
        : m_x { x }, m_y { y }
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
    }
};

int main()
{
    Foo foo{}; // compile error: ambiguous constructor function call

    return 0;
}

//
#include <iostream>
struct Foo
{
    int x{};
    int y{};

public:
    Foo()
    {
        x = 5;
    }

    Foo(int value): y { value }
    {
        // intent: call Foo() function
        // actual: value initialises nameless temporary Foo (which is then discarded)
        Foo(); // note: this is the equivalent of writing Foo{}
    }
};

int main()
{
    Foo f{ 9 };
    std::cout << f.x << ' ' << f.y; // prints 0 9
}
// 
#include <iostream>

struct Foo
{
    int x{};
    int y{};

public:
    Foo()
    {
        x = 5;
    }

    Foo(int value)
        : Foo() // delegate to the default constructor
    {
        y = value;
    }
};

int main()
{
    Foo f{ 9 };
    std::cout << f.x << ' ' << f.y; // prints 5 9
}

// 
#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    std::string m_name{};
    int m_id{ 0 };

public:
    Employee(std::string_view name)
        : m_name{ name }
    {
        std::cout << "Employee " << m_name << " created\n";
    }

    Employee(std::string_view name, int id)
        : m_name{ name }, m_id{ id }
    {
        // Employee(name); // compile error
        std::cout << "Employee " << m_name << " id: "<<m_id<<" created"<<"\n";
    }
};

int main()
{
    Employee e1{ "James" };
    Employee e2{ "Dave", 42 };
}

// 
#include <iostream>
#include <string>

class Employee
{
private:
    std::string m_name{};
    int m_id{ 0 };

public:
    Employee(std::string name)
        : Employee{ name, 0 } // delegate initialization to Employee(std::string_view, int) constructor
    {
        std::cout<<name<<" "<<"C1\n";
    }

    Employee(std::string name, int id)
        : m_name{ name }, m_id{ id } // actually initialises the members
    {
        std::cout << "Employee " << m_name << " created\n";
    }

};

int main()
{
    Employee e1{ "James" };
    Employee e2{ "Dave", 42 };
}

/*
Points
A constructor that delegates to another constructor is not allowed to do any member initialization itself.
So your constructors can delegate or initialise, but not both.
It’s possible for one constructor to delegate to another constructor, which delegates back to the first constructor.
This forms an infinite loop, and will cause your program to run out of stack space and crash. You can avoid this by ensuring all of your constructors resolve to a non-delegating constructor.
Default arguments can be used to reduce the number of constructors.
*/