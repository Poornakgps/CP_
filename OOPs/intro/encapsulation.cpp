#include <iostream>
#include <string>
#include <string_view>
using namespace std;

class Employee // members are private by default
{
    string m_name{};
    char m_firstInitial{};

public:
    void setName(string_view name) // string_view is read only and light weight
    {
        m_name = name;
        m_firstInitial = name.front(); // use std::string::front() to get first letter of name
    }

    void print() const
    {
        cout << "Employee " << m_name << " has first initial " << m_firstInitial << '\n';
    }
};

int main()
{
    Employee e{};
    e.setName("John");
    e.print();

    e.setName("Mark");
    e.print();

    return 0;
}

//Output: John has first initial J
//        Mark has first initial M