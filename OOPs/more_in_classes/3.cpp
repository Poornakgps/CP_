// classes and headers
#include <iostream>
#include "3Date.h"

Date::Date(int day, int month, int year)
        :m_day{day}, m_month{month}, m_year{year}
{

}

void Date::print() 
{ 
    std::cout<<this->getDay()<<"/"<<this->getMonth()<<"/"<<this->getYear()<<"\n";
}

int main()
{
    Date d{ 6, 6, 2007 }; // if u add const u must add const for all getters and print also
    d.print();
    return 0;
}