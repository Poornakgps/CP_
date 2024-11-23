#include <iostream>

class Something
{
private:
    mutable int x;
public:
    void print()
    {
        std::cout << "non-const\n";
    }

    void print() const
    {
        x = 10; // allowed because of mutable
        std::cout << "const\n";
    }
};

int main()
{
    Something s1{};
    s1.print(); // calls print()

    const Something s2{};
    s2.print(); // calls print() const

    return 0;
}

/*
Output:
non-const
const
*/