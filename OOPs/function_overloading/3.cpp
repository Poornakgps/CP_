
// The argument matching sequence
// 1. Compiler tries to find an exact match.
// First, the compiler will see if there is an overloaded function where the type of the arguments in the function call exactly matches the type of the parameters in the overloaded functions.
// Second, the compiler will apply a number of trivial conversions (specific conversion rules that will modify types (without modifying the value) for purposes of finding a match, example, a non-const type can be trivially converted to a const type) to the arguments in the function call.
void print(const int)
{
}

void print(double)
{
}

int main()
{
    int x { 0 };
    print(x); // x trivially converted to const int

    return 0;
}
// Converting a non-reference type to a reference type (or vice-versa) is also a trivial conversion.
// Matches made via the trivial conversions are considered exact matches.

void print(int)
{
}

void print(double)
{
}

int main()
{
    print('a'); // promoted to match print(int)
    print(true); // promoted to match print(int)
    print(4.5f); // promoted to match print(double)

    return 0;
}
// 2. If no exact match is found, the compiler tries to find a match by applying numeric promotion to the argument(s)
// Certain narrow integral and floating point types can be automatically promoted to wider types, such as int or double.
// If, after numeric promotion, a match is found, the function call is resolved.

// 3. If no match is found via numeric promotion, the compiler tries to find a match by applying numeric conversions

#include <string> // for std::string

void print(double)
{
}

void print(std::string)
{
}

int main()
{
    print('a'); // 'a' converted to match print(double)

    return 0;
}
// Because there is no print(char) (exact match), and no print(int) (promotion match), the 'a' is numerically converted to a double.


// 4. If no match is found via numeric conversion, the compiler tries to find a match through any user-defined conversions.
// We haven't covered operator overloading yet, so don't worry if this doesn't make sense
class X // this defines a new type called X
{
public:
    operator int() { return 0; } // Here's a user-defined conversion from X to int
};

void print(int)
{
}

void print(double)
{
}

int main()
{
    X x; // Here, we're creating an object of type X (named x)
    print(x); // x is converted to type int using the user-defined conversion from X to int

    return 0;
}

// 5. If no match is found via user-defined conversion, the compiler will look for a matching function that uses ellipsis.
// 6. If no matches have been found by this point, the compiler gives up and will issue a compile error.

// Ambiguous matches
// Occurs when the compiler finds two or more functions that can be made to match in the same step. When this occurs, the compiler will stop matching and issue a compile error.
void print(int)
{
}

void print(double)
{
}
void print(unsigned int)
{
}

void print(float)
{
}


int main()
{
    print(5L); // 5L is type long error
    print(0); // int can be numerically converted to unsigned int or to float
    print(3.14159); // double can be numerically converted to unsigned int or to float
    return 0;
}

