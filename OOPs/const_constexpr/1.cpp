#include <iostream>

int getNumber()
{
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y;

    return y;
}

int main()
{
    // Non-const variables:
    int a { 5 };                 // 5 is a constant expression
    double b { 1.2 + 3.4 };      // 1.2 + 3.4 is a constant expression

    // Const integral variables with a constant expression initializer
    // are compile-time constants:
    const int c { 5 };           // 5 is a constant expression
    const int d { c };           // c is a constant expression
    const long e { c + 2 };      // c + 2 is a constant expression

    // Other const variables are runtime constants:
    const int f { a };           // a is not a constant expression
    const int g { a + 1 };       // a + 1 is not a constant expression
    const long h { a + c };      // a + c is not a constant expression
    const int i { getNumber() }; // getNumber() is not a constant expression

    const double j { b };        // b is not a constant expression
    const double k { 1.2 };      // 1.2 is a constant expression

    const int x { 3 + 4 }; // constant expression 3 + 4 must be evaluated at compile-time
    int y { 3 + 4 };       // constant expression 3 + 4 may be evaluated at compile-time or runtime
    return 0;
}