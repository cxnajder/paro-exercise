#include "dayOfYear.hpp"
#include <algorithm>
#include <array>
#include <cassert>
#include <stdexcept>
#include <sstream>

const std::array<int, 12> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isDateValid(const int&, const int&, const int&);
bool isLeapYear(const int&);
void validateDate(const int&, const int&, const int&);


int dayOfYear(int month, int dayOfMonth, int year) {

    validateDate(month, dayOfMonth, year); // can throw

    for(int i = 0; i < month - 1; i++) {
        dayOfMonth += monthDays.at(i);
    }

    if(month > 2 && isLeapYear(year)) {
        dayOfMonth++;
    }
    return dayOfMonth;
}


bool isDateValid(const int& month, const int& day, const int& year)
{
    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;
    if(isLeapYear(year) && month==2 && day > 1 + monthDays[month-1])
        return false;
    else if(day > monthDays[month-1])
        return false;
    if (year < 0)
        return false;
    return true;
}

void validateDate(const int& month, const int& day, const int& year)
{
    if(!isDateValid(month, day, year)) {
        std::stringstream ss;
        ss << "The date [month=" << month << ", day=" << day << ", year=" << year << "] is not in valid range";
        throw std::out_of_range(ss.str());
    }
}

bool isLeapYear(const int& year)
{
    constexpr int leapYearException    = 400;
    constexpr int nonLeapYearException = 100;

    return (year % 4 == 0 && (year % nonLeapYearException != 0 || year % leapYearException == 0));
}
