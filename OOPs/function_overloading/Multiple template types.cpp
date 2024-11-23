#include <iostream>

template <typename T, typename U>
auto max(T x, U y)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max(2, 3.5) << '\n';
    return 0;
}
// Let the compiler deduce what the return type should be from the return statement.
// Also, T and U can resolve to the same type if required.