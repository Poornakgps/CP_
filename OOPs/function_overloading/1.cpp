/*

Necessary Conditions for Function Overloading
Different Parameter Types: Functions can have the same name if their parameter types differ.

Example: void print(int x); vs. void print(double x);
Different Number of Parameters: Functions with the same name can differ in the number of parameters.

Example: void display(int x); vs. void display(int x, int y);
Different Order of Parameter Types: Functions with the same name can have different parameter orders if the types are distinct.

Example: void calculate(int x, double y); vs. void calculate(double x, int y);
Important Points on Overloading
Return Type: The return type alone cannot distinguish overloaded functions; it must differ in parameter type, number, or order.

Invalid Example: int func(int x); vs. double func(int x);
Default Arguments: Be cautious with default arguments, as they can cause ambiguities with overloads.

Example: void show(int x, int y = 10); vs. void show(int x); (May cause ambiguity when called with one argument)
Scope and Access Modifiers: Overloaded functions must be in the same scope (e.g., same namespace or class).
*/