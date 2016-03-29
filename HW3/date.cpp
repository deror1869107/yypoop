#include <iostream>
#include "date.h"

unsigned short int Date::getDate_data() const
{
    return Date_data;
}

unsigned short int Date::getDay() const
{
    return Date_data % 32;
}

unsigned short int Date::getMon() const 
{
    return (Date_data >> 5) % 16;
}

unsigned short int Date::getYr() const
{
    return (Date_data >> 9) + 2000;
}

void Date::setDate(const short int& yr, const short int& mon, const short int& day)
{
    Date_data = ((yr - 2000) << 9) + (mon << 5) + day;
}

void Date::showDate()
{
    std::cout << getYr() << ' ' << getMon() << ' ' << getDay() << std::endl;
}

