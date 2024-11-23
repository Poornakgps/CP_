#include <iostream>

// public, private, protected
// struct members are public by default, can be accessed by anyone same goes for functions
// class members are private by default, can only be accessed by other members same goes for functions

class Date
{
// Any members defined here would default to private

public: // here's our public access specifier

    void print() const // public due to above public: specifier
    {
        // members can access other private members
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }

private: // here's our private access specifier

    int m_year { 2020 };  // private due to above private: specifier
    int m_month { 14 }; // private due to above private: specifier
    int m_day { 10 };   // private due to above private: specifier
};

class Person
{
private:
    std::string m_name{};

public:
    void kisses(const Person& p) const
    {
        std::cout << m_name << " kisses " << p.m_name << '\n';
    }

    void setName(std::string name)
    {
        m_name = name;
    }
};

int main()
{
    Date d{};
    d.print();  // okay, main() allowed to access public members

    Person joe;
    joe.setName("Joe");

    Person kate;
    kate.setName("Kate");

    joe.kisses(kate);
    return 0;
}

