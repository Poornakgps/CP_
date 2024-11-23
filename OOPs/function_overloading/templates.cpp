/*
Templates
A template describes what a function or class looks like.
We can use one or more placeholder types.
Once a template is defined, the compiler can use the template to generate as many overloaded functions (or classes) as needed, each using different actual types!
Function Templates
A function template is a function-like definition that is used to generate one or more overloaded functions, each with a different set of actual types.
When we create our function template, we use placeholder types (also called type template parameters, or informally template types) for any parameter types, return types, or types used in the function body that we want to be specified later.
3 different kinds of template parameters:
Type template parameters (where the template parameter represents a type).
Non-type template parameters (where the template parameter represents a constexpr value).
Template template parameters (where the template parameter represents a template).
The scope of a template parameter declaration is limited to the function template (or class template) that follows. Therefore, each function template (or class) needs its own template parameter declaration.
*/

#include <iostream>
using namespace std;

// Renaming the custom max function to avoid conflicts with std::max
template <typename T>
T myMax(T x, T y) {
    std::cout<<x<<" "<<y<<"     ";
    return (x < y) ? y : x;
}

// Overloaded max function for int specifically
int myMax(int x, int y) {
    return (x < y) ? y : x;
}

template <typename T>
T addOne(T x) // function template forward declaration
{
    return x+1;
};
// Use function template specialization to tell the compiler that addOne(const char*) should emit a compilation error
template <>
const char* addOne(const char* x) = delete;

int main() {
    int int1 = 5, int2 = 10;
    double double1 = 5.5, double2 = 10.1;

    // Using the custom myMax function
    cout << "Max of " << int1 << " and " << int2 << " is " << myMax<int>(int1, int2) << endl;
    cout << "Max of " << double1 << " and " << double2 << " is " << myMax<double>(double1, double2) << endl;

    // Using the custom myMax function for char
    cout << "Max of " << 'a' << " and " << 'b' << " is " << myMax<char>('a', 'b') << endl;
    cout << "Max of " << "3.5" << " and " << '9' << " is " << myMax<double>(3.5, 9) << endl; // avoiding <double> lead to compiler error

    // Using the custom myMax function for C-strings
    cout << "Max of " << "zaab" << " and " << "bavd" << " is " << myMax<const char*>("zaab", "bavd") << endl;

    std::cout << addOne(1) << '\n';
    std::cout << addOne(2.3) << '\n';
    std::cout << addOne('a') << '\n';
    // std::cout << addOne("chandu") << '\n'; // results error because of const char* addOne(const char* x) = delete
    return 0;
}

