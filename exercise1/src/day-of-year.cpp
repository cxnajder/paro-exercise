#include "day-of-year.hpp"
#include <algorithm>
#include <array>


constexpr int leapYearException    = 400;
constexpr int nonLeapYearException = 100;

int dayOfYear(int month, int dayOfMonth, int year) {
    const std::array<int, 11> monthDays = {31, 28, 31, 30, 31, 30,
                                           31, 31, 30, 31, 30};
    for(int i = 0; i < month - 1; i++) {
        dayOfMonth += monthDays.at(i);
    }

    if(month > 2 && year % 4 == 0 &&
       (year % nonLeapYearException != 0 || year % leapYearException == 0)) {
        dayOfMonth++;
    }
    return dayOfMonth;
}