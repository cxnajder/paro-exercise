#include "dayOfYear.hpp"
#include <algorithm>
#include <array>
#include <cassert>
#include <stdexcept>
#include <format>

const std::array<int, 12> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isDateValid(const int&, const int&, const int&);
bool dateUtils::isLeapYear(const int&);
void validateDate(const int&, const int&, const int&);
void validateDateVerbous(const int&, const int&, const int&);


int dateUtils::dayOfYear(int month, int dayOfMonth, int year) {

    validateDate(month, dayOfMonth, year); // can throw

    for(int i = 0; i < month - 1; i++) {
        dayOfMonth += monthDays.at(i);
    }

    if(month > 2 && dateUtils::isLeapYear(year)) {
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

    if (month==2)
    {
        if(dateUtils::isLeapYear(year) && day > 1 + monthDays[month-1]) 
            return false;

        if(!dateUtils::isLeapYear(year) && day > monthDays[month-1])
            return false;
    }
    
    else if(day > monthDays[month-1])
        return false;

    if (year < 0)
        return false;
        
    return true;
}

void validateDate(const int& month, const int& day, const int& year)
{
    if(!isDataValid(month, day, year))
        throw std::out_of_range(std::format("The date [month={}, day={}, year={}] is not in valid range", month, day, year));
}

void validateDateVerbous(const int& month, const int& day, const int& year)
{
    std::stringstream ss;
    ss << "Invalid date: ";
    if (month < 1 || month > 12)
    {
        ss << "Month not in range 1-12:"<<month<< ";";
        throw std::out_of_range(ss.str());
    }

    if (day < 1)
    {
        ss << "Day value less then 0: "<<day<<";";
        throw std::out_of_range(ss.str());
    }
    if (month==2)
    {
        if(dateUtils::isLeapYear(year) && day > 1 + monthDays[month-1]) 
        {
            ss << "Day out of range " << 1 + monthDays[month-1] <<": "<<day<<";";
            throw std::out_of_range(ss.str());
        }

        if(!dateUtils::isLeapYear(year) && day > monthDays[month-1])
        {
            ss << "Day out of range "<< monthDays[month-1] <<": "<<day<<";";
            throw std::out_of_range(ss.str());
        }
    }
    else if(day > monthDays[month-1])
    {
        ss << "Day out of range "<< monthDays[month-1] <<": "<<day<<";";
        throw std::out_of_range(ss.str());
    }
    if (year < 0)
    {
        ss << "Year value less then 0: "<<year<<";";
        throw std::out_of_range(ss.str());
    }
}

bool dateUtils::isLeapYear(const int& year)
{
    constexpr int leapYearException    = 400;
    constexpr int nonLeapYearException = 100;

    return (year % 4 == 0 && (year % nonLeapYearException != 0 || year % leapYearException == 0));
}
