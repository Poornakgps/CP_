// #include <iostream>

// class Fraction
// {
// private:
//     int m_numerator{ 0 };
//     int m_denominator{ 1 };

// public:
//     // Default constructor
//     Fraction(int numerator=0, int denominator=1)
//         : m_numerator{numerator}, m_denominator{denominator}
//     {
//     }
//    void print()
//     {
//         std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
//     }
// };

// int main()
// {
//     Fraction f { 5, 3 };  // Calls Fraction(int, int) constructor
//     Fraction fCopy { f }; // What constructor is used here? Copy Constructor

//     f.print();
//     fCopy.print();

//     return 0;
// }

// /***
// Output:

// Fraction(5, 3)
// Fraction(5, 3)

// */

// #include <iostream>

// class Fraction
// {
// private:
//     int m_numerator{ 0 };
//     int m_denominator{ 1 };

// public:
//     // Default constructor
//     Fraction(int numerator=0, int denominator=1)
//         : m_numerator{numerator}, m_denominator{denominator}
//     {
//     }

//     // Copy constructor
//     Fraction(const Fraction& fraction)
//         // Initialize our members using the corresponding member of the parameter
//         : m_numerator{ fraction.m_numerator }
//         , m_denominator{ fraction.m_denominator }
//     {
//         std::cout << "Copy constructor called\n"; // just to prove it works
//     }

//     void print() const
//     {
//         std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
//     }
// };

// int main()
// {
//     Fraction f { 5, 3 };  // Calls Fraction(int, int) constructor
//     Fraction fCopy { f }; // Calls Fraction(const Fraction&) copy constructor

//     f.print();
//     fCopy.print();

//     return 0;
// }

// /***

// Output:

// Copy constructor called
// Fraction(5, 3)
// Fraction(5, 3)

// ***/
#include <iostream>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{ numerator }, m_denominator{ denominator }
    {
        std::cout << "normal constructor called\n ";
    }

    // Copy constructor
    Fraction(const Fraction& fraction)
        : m_numerator{ fraction.m_numerator }
        , m_denominator{ fraction.m_denominator }
    {
        std::cout << "Copy constructor called\n";
    }

    void print() const
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

void printFraction(Fraction f) // f is pass by value
{
    f.print();
}

Fraction generateFraction(int n, int d)
{
    Fraction f{ n, d };
    // std::cout<<"HEY\n";
    return f;
}

int main()
{
    Fraction f{ 5, 3 };

    printFraction(f); // f is copied into the function parameter using copy constructor

    Fraction f2{ generateFraction(1, 2) }; // Fraction is returned using copy constructor
    // std::cout<<"HEY\n";
    printFraction(f2); // f is copied into the function parameter using copy constructor

    return 0;
}

/***

Output - 

Copy constructor called
Fraction(5, 3)
Copy constructor called
Copy constructor called
Fraction(1, 2)

Note: If you compile and execute the above example, you may find that only two calls to the copy constructor occur. This is a compiler optimization known as copy elision. We discuss copy elision further.
Copy elision is a compiler optimization technique that allows the compiler to remove unnecessary copying of objects.
***/