#include <iostream>
#include <algorithm>
class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo(int x, int y)
        : m_x { x }, m_y { y } // here's our member initialization list
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    Foo foo{ 6, 7 };
    foo.print();

    return 0;
}
// Output: Foo(6, 7) constructed
//         Foo(6, 7)

// Member initialization order
// Members in a member initializer list are always initialised in the order in which they are defined 
// inside the class (not in the order they are defined in the member initializer list).

// class Foo
// {
// private:
//     int m_x{};
//     int m_y{};

// public:
//     Foo(int x, int y)
//         : m_y{ std::max(x, y) }, m_x{ m_y } // issue on this line
//     {
//     }

//    void print() const
//     {
//         std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
//     }
// };

// int main()
// {
//     Foo foo{ 6, 7 };
//     foo.print();

//     return 0;
// }
// //Output: Foo(-858993460, 7) // reason Since m_x is initialized before m_y, the value of m_y is still uninitialized when you try to assign it to m_x. This results in m_x having an undefined (garbage) value.