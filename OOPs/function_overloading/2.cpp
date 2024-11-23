#include <iostream>
#include <string>

class Example {
private:
    int m_value; // A member variable to track the state

public:
    // Constructor to initialize m_value
    Example() : m_value(0) {}

    // Overload based on `const` qualifier
    // This function is called when the object is constant
    void show() const {
        std::cout << "const show\n";
        // Action after printing: Print m_value for const object
        std::cout << "Performing action in const show: m_value = " << m_value << "\n";
    }    // For const objects

    // This function is called when the object is non-const
    void show() {
        std::cout << "non-const show\n";
        // Action after printing: Modify m_value for non-const object
        m_value += 10; // Modifying m_value
        std::cout << "Performing action in non-const show: m_value = " << m_value << "\n";
    }      // For non-const objects

    // Overload based on `volatile` qualifier
    // This function is called for const objects
    void display() const {
        std::cout << "const display\n";
        // Action after printing: Print m_value for const object
        std::cout << "Performing action in const display: m_value = " << m_value << "\n";
    }

    // This function is called for volatile objects
    void display() volatile {
        std::cout << "volatile display\n";
        // Action after printing: Modify m_value for volatile object
        m_value -= 5; // Subtract 5 from m_value for volatile object
        std::cout << "Performing action in volatile display: m_value = " << m_value << "\n";
    }   // For volatile objects

    // Overload based on `&` and `&&` qualifiers (lvalue and rvalue references)
    // This function is called for lvalues
    void check() & {
        std::cout << "Lvalue check\n";
        // Action after printing: Modify m_value for lvalue reference
        m_value *= 2; // Multiply m_value by 2 for lvalue
        std::cout << "Performing action in Lvalue check: m_value = " << m_value << "\n";
    }    // For lvalues

    // This function is called for rvalues
    void check() && {
        std::cout << "Rvalue check\n";
        // Action after printing: Modify m_value for rvalue reference
        m_value /= 2; // Divide m_value by 2 for rvalue
        std::cout << "Performing action in Rvalue check: m_value = " << m_value << "\n";
    }   // For rvalues

    // Overload based on `noexcept` specifier
    // This function is called for noexcept function
    void calculate() noexcept {
        std::cout << "noexcept calculate\n";
        // Action after printing: Modify m_value for noexcept function
        m_value += 20; // Add 20 to m_value for noexcept function
        std::cout << "Performing action in noexcept calculate: m_value = " << m_value << "\n";
    }

    // This function is called for const functions (non-noexcept)
    void calculate() const {
        std::cout << "normal calculate\n";
        // Action after printing: Print m_value without modifying it
        std::cout << "Performing action in normal calculate: m_value = " << m_value << "\n";
    }

    // Overload based on function parameter types
    // This function is called for integers
    void process(int x) {
        std::cout << "Processing integer: " << x << "\n";
        // Action after printing: Modify m_value by adding integer value
        m_value += x; // Add x to m_value
        std::cout << "Performing action in process(int): m_value = " << m_value << "\n";
    }

    // This function is called for doubles
    void process(double x) {
        std::cout << "Processing double: " << x << "\n";
        // Action after printing: Modify m_value by casting double to integer and adding it
        m_value += static_cast<int>(x); // Cast double to int and add to m_value
        std::cout << "Performing action in process(double): m_value = " << m_value << "\n";
    }

    // Overload based on multiple parameters (int and double)
    // This function is called for integer and double type parameters
    void process(int x, double y) {
        std::cout << "Processing multiple parameters: int = " << x << ", double = " << y << "\n";
        // Action after printing: Modify m_value by adding both parameters (casting double to int)
        m_value += x + static_cast<int>(y); // Add integer part of double to m_value
        std::cout << "Performing action in process(int, double): m_value = " << m_value << "\n";
    }

    // Overload based on multiple parameters (double and int)
    // This function is called for double and int type parameters (reverse order)
    void process(double x, int y) {
        std::cout << "Processing multiple parameters (reversed order): double = " << x << ", int = " << y << "\n";
        // Action after printing: Modify m_value by adding both parameters (casting double to int)
        m_value += static_cast<int>(x) + y; // Add y to m_value after casting x to int
        std::cout << "Performing action in process(double, int): m_value = " << m_value << "\n";
    }

    // Destructor
    virtual ~Example() = default; // Virtual destructor for proper cleanup in case of inheritance
};

int main() {
    Example obj;                    // Normal object (non-const)
    const Example constObj;         // Const object
    volatile Example volatileObj;   // Volatile object

    // Overloads based on const and non-const
    obj.show();       // Calls non-const show()
    constObj.show();  // Calls const show()

    // Overloads based on volatile
    constObj.display();          // Calls const display()
    volatileObj.display();       // Calls volatile display()

    // Overloads based on lvalue and rvalue qualifiers
    obj.check();               // Calls lvalue check()
    Example().check();         // Calls rvalue check()

    // Overloads based on noexcept
    obj.calculate();           // Calls noexcept calculate()
    constObj.calculate();      // Calls normal const calculate()

    // Overloads based on function parameter types
    obj.process(10);        // Calls process(int)
    obj.process(5.5);       // Calls process(double)

    // Overloads based on multiple parameters
    obj.process(10, 5.5);    // Calls process(int, double)
    obj.process(5.5, 10);    // Calls process(double, int)

    return 0;
}

/*

Here is the code with detailed comments that explain the definitions of the functions and what happens in each part of the code:

cpp
Copy code
#include <iostream>
#include <string>

class Example {
private:
    int m_value; // A member variable to track the state

public:
    // Constructor to initialize m_value
    Example() : m_value(0) {}

    // Overload based on `const` qualifier
    // This function is called when the object is constant
    void show() const {
        std::cout << "const show\n";
        // Action after printing: Print m_value for const object
        std::cout << "Performing action in const show: m_value = " << m_value << "\n";
    }    // For const objects

    // This function is called when the object is non-const
    void show() {
        std::cout << "non-const show\n";
        // Action after printing: Modify m_value for non-const object
        m_value += 10; // Modifying m_value
        std::cout << "Performing action in non-const show: m_value = " << m_value << "\n";
    }      // For non-const objects

    // Overload based on `volatile` qualifier
    // This function is called for const objects
    void display() const {
        std::cout << "const display\n";
        // Action after printing: Print m_value for const object
        std::cout << "Performing action in const display: m_value = " << m_value << "\n";
    }

    // This function is called for volatile objects
    void display() volatile {
        std::cout << "volatile display\n";
        // Action after printing: Modify m_value for volatile object
        m_value -= 5; // Subtract 5 from m_value for volatile object
        std::cout << "Performing action in volatile display: m_value = " << m_value << "\n";
    }   // For volatile objects

    // Overload based on `&` and `&&` qualifiers (lvalue and rvalue references)
    // This function is called for lvalues
    void check() & {
        std::cout << "Lvalue check\n";
        // Action after printing: Modify m_value for lvalue reference
        m_value *= 2; // Multiply m_value by 2 for lvalue
        std::cout << "Performing action in Lvalue check: m_value = " << m_value << "\n";
    }    // For lvalues

    // This function is called for rvalues
    void check() && {
        std::cout << "Rvalue check\n";
        // Action after printing: Modify m_value for rvalue reference
        m_value /= 2; // Divide m_value by 2 for rvalue
        std::cout << "Performing action in Rvalue check: m_value = " << m_value << "\n";
    }   // For rvalues

    // Overload based on `noexcept` specifier
    // This function is called for noexcept function
    void calculate() noexcept {
        std::cout << "noexcept calculate\n";
        // Action after printing: Modify m_value for noexcept function
        m_value += 20; // Add 20 to m_value for noexcept function
        std::cout << "Performing action in noexcept calculate: m_value = " << m_value << "\n";
    }

    // This function is called for const functions (non-noexcept)
    void calculate() const {
        std::cout << "normal calculate\n";
        // Action after printing: Print m_value without modifying it
        std::cout << "Performing action in normal calculate: m_value = " << m_value << "\n";
    }

    // Overload based on function parameter types
    // This function is called for integers
    void process(int x) {
        std::cout << "Processing integer: " << x << "\n";
        // Action after printing: Modify m_value by adding integer value
        m_value += x; // Add x to m_value
        std::cout << "Performing action in process(int): m_value = " << m_value << "\n";
    }

    // This function is called for doubles
    void process(double x) {
        std::cout << "Processing double: " << x << "\n";
        // Action after printing: Modify m_value by casting double to integer and adding it
        m_value += static_cast<int>(x); // Cast double to int and add to m_value
        std::cout << "Performing action in process(double): m_value = " << m_value << "\n";
    }

    // Destructor
    virtual ~Example() = default; // Virtual destructor for proper cleanup in case of inheritance
};

int main() {
    Example obj;                    // Normal object (non-const)
    const Example constObj;         // Const object
    volatile Example volatileObj;   // Volatile object

    // Overloads based on const and non-const
    obj.show();       // Calls non-const show()
    constObj.show();  // Calls const show()

    // Overloads based on volatile
    constObj.display();          // Calls const display()
    volatileObj.display();       // Calls volatile display()

    // Overloads based on lvalue and rvalue qualifiers
    obj.check();               // Calls lvalue check()
    Example().check();         // Calls rvalue check()

    // Overloads based on noexcept
    obj.calculate();           // Calls noexcept calculate()
    constObj.calculate();      // Calls normal const calculate()

    // Overloads based on function parameter types
    obj.process(10);        // Calls process(int)
    obj.process(5.5);       // Calls process(double)

    return 0;
}
Explanation in Comments:
show() (const vs non-const):

For const objects: It prints the message and then performs an action, displaying the current value of m_value.
For non-const objects: It modifies the m_value by adding 10 and then prints the updated value of m_value.
display() (const vs volatile):

For const objects: Prints a message and then performs an action (printing the current value of m_value).
For volatile objects: Subtracts 5 from m_value and prints the updated value of m_value.
check() (lvalue vs rvalue):

For lvalues: It multiplies the m_value by 2 and then prints the updated value of m_value.
For rvalues: It divides m_value by 2 and then prints the updated value of m_value.
calculate() (noexcept vs normal):

For noexcept functions: It adds 20 to m_value and prints the updated value.
For normal functions: Prints the current value of m_value without modifying it.
process() (int vs double):

For integers: Adds the integer parameter to m_value and prints the updated value.
For doubles: Casts the double parameter to an integer and adds it to m_value, then prints the updated value.

*/