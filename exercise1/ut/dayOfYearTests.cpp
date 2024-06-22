#include "gtest/gtest.h"
#include "dayOfYear.hpp"

struct DayOfYear {};

TEST(DayOfYear, Normal_Year)
{
    ASSERT_EQ(dayOfYear(9, 6, 2137), 249);
}


TEST(DayOfYear, Leap_Year)
{
    ASSERT_EQ(dayOfYear(4, 20, 2040), 111);
}


TEST(DayOfYear, Leap_Year_On_Last_Day_Of_February)
{
    ASSERT_EQ(dayOfYear(29, 2, 2040), 60);
}


TEST(DayOfYear, January_1st_Is_Fitst_Day_Of_Year)
{
    ASSERT_EQ(dayOfYear(1, 1, 2020), 1);
}


TEST(DayOfYear, Last_Day_Of_Year)
{
    ASSERT_EQ(dayOfYear(12, 31, 2021), 365);
}


TEST(DayOfYear, Last_Day_Of_Leap_Year)
{
    ASSERT_EQ(dayOfYear(12, 31, 2020), 366);
}

