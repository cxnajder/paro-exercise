#include "day-of-year.hpp"
#include <algorithm>
#include <array>
#include <iostream>
#include <cassert>


constexpr int leapYearException    = 400;
constexpr int nonLeapYearException = 100;

const std::array<int, 12> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void fixMonth(int &, int &);
void fixDay(int &, int &, int &);

void fixDate(int & month, int & dayOfMonth, int & year)
{
    /*
        This function fixes date in case someone inputs invalid date like: 
        -   dayOfYear(12, 32, 2020)
        -   dayOfYear(13, 01, 2020)
        -   dayOfYear(01, 00, 2021)
        -   dayOfYear(01, -1, 2021)
        -   dayOfYear(00, 01, 2021)
        -   dayOfYear(-1, 01, 2021)

    */

    fixMonth(month, year);
    fixDay(month, dayOfMonth, year);
}

void fixMonth(int & month, int & year)
{
    while( (1 > month || month > 12) ) 
    {
        if (month > 12) {
            ++year;
            month -=12;
        }

        if (month < 1) {
            --year;
            month +=12;
        }
    }
}

void fixDay(int & month, int & dayOfMonth, int & year) 
{
    do
    {
        assert (1 <= month && month <= 12); 
        // fixDay can be called only if month between: <1, 12>

        if (dayOfMonth < 1) {
            --month;
            fixMonth(month, year); // in case month was 1

            assert (1 <= month && month <= 12);  //checks if fixMonth did work correctly
            dayOfMonth += monthDays[month-1];
        }

        if (dayOfMonth > monthDays[month-1]) {

            dayOfMonth -= monthDays[month-1];

            ++month;
            fixMonth(month, year); // in case month was 12
        }

    } while (1 > dayOfMonth || dayOfMonth > monthDays[month-1]);
    
}


int dayOfYear(int month, int dayOfMonth, int year) {

    fixDate(month, dayOfMonth, year);    

    assert (1 <= month && month <= 12); 
    assert (1 <= dayOfMonth && dayOfMonth <= monthDays[month-1]);

    for(int i = 0; i < month - 1; i++) {
        dayOfMonth += monthDays.at(i);
    }

    if(month > 2 && year % 4 == 0 &&
       (year % nonLeapYearException != 0 || year % leapYearException == 0)) {
        dayOfMonth++;
    }
    return dayOfMonth;
}
