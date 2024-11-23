#ifndef DATE_H
#define DATE_H

class Date{
    private:
        int m_day{};
        int m_month{};
        int m_year{};
    public:
        Date(int day, int month, int year); // declaring constructor

        void print() ; // print function declaration

        int getYear(){return this->m_year;}
        int getMonth(){return this->m_month;}
        int getDay(){return this->m_day;}

};

#endif