#include "gtest/gtest.h"
#include "day-of-year.hpp"

struct DayOfYearTestSuite {};

TEST(DayOfYearTestSuite, leapYear)
{
    ASSERT_EQ(dayOfYear(4, 20, 2040), 111);
}

TEST(DayOfYearTestSuite, normalYear)
{
    ASSERT_EQ(dayOfYear(9, 6, 2137), 249);
}

TEST(DayOfYearTestSuite, January1stIsFitstDayOfYear)
{
    ASSERT_EQ(dayOfYear(1, 1, 2020), 1);
}


TEST(DayOfYearTestSuite, LastDayOfYear)
{
    ASSERT_EQ(dayOfYear(12, 31, 2021), 365);
}


TEST(DayOfYearTestSuite, LastDayOfLeapYear)
{
    ASSERT_EQ(dayOfYear(12, 31, 2020), 366);
}

