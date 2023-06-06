#include "day-of-year.hpp"
#include <algorithm>
#include <array>


constexpr int FOURHUNDRED = 400;
constexpr int ONEHUNDRED  = 100;

int dayOfYear(int month, int dayOfMonth, int year) {
    const std::array<int, 11> monthDays = {31,28,31,30,31,30,31,31,30,31,30};
    for(int i = 0; i < month - 1; i++) {
        dayOfMonth += monthDays.at(i);
    }

    if(month > 2 && year % 4 == 0 && (year % ONEHUNDRED != 0 || year % FOURHUNDRED == 0)) {
        dayOfMonth++;
    }
    return dayOfMonth;
}

