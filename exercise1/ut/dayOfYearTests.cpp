#include "gtest/gtest.h"
#include "dayOfYear.hpp"
#include <stdexcept>

// =================== //
// Functionality Tests //
// =================== //

TEST(dayOfYear_Functinality, Normal_Year)
{
    ASSERT_EQ(dayOfYear(9, 6, 2137), 249);
}


TEST(dayOfYear_Functinality, Leap_Year)
{
    ASSERT_EQ(dayOfYear(4, 20, 2040), 111);
}


TEST(dayOfYear_Functinality, Leap_Year_On_Last_Day_Of_February)
{
    ASSERT_EQ(dayOfYear(2, 29, 2040), 60);
}


TEST(dayOfYear_Functinality, Leap_Year_On_1st_Day_Of_March)
{
    ASSERT_EQ(dayOfYear(3, 1, 2040), 61);
}


TEST(dayOfYear_Functinality, January_1st_Is_Fitst_Day_Of_Year)
{
    ASSERT_EQ(dayOfYear(1, 1, 2020), 1);
}


TEST(dayOfYear_Functinality, Last_Day_Of_Year)
{
    ASSERT_EQ(dayOfYear(12, 31, 2021), 365);
}


TEST(dayOfYear_Functinality, Last_Day_Of_Leap_Year)
{
    ASSERT_EQ(dayOfYear(12, 31, 2020), 366);
}

// ================ //
// Validation Tests //
// ================ //

// January
TEST(dayOfYear_Validation, Jan_Day_Minus_One)
{
    EXPECT_THROW(dayOfYear(1, -1, 2000), std::out_of_range);
}

TEST(dayOfYear_Validation, Jan_Day_Zero)
{
    EXPECT_THROW(dayOfYear(1, 0, 2000), std::out_of_range);
}

TEST(dayOfYear_Validation, Jan_Day_One)
{
    EXPECT_NO_THROW(dayOfYear(1, 1, 2000));
}

TEST(dayOfYear_Validation, Jan_Last_Day)
{
    EXPECT_NO_THROW(dayOfYear(1, 31, 2000));
}

TEST(dayOfYear_Validation, Jan_Last_Day_Plus_One)
{
    EXPECT_THROW(dayOfYear(1, 32, 2000), std::out_of_range);
}


//February Normal Year
TEST(dayOfYear_Validation, Feb_Non_Leap_Day_Minus_One)
{
    EXPECT_THROW(dayOfYear(2, -1, 2001), std::out_of_range);
}

TEST(dayOfYear_Validation, Feb_Non_Leap_Day_Zero)
{
    EXPECT_THROW(dayOfYear(2, 0, 2001), std::out_of_range);
}

TEST(dayOfYear_Validation, Feb_Non_Leap_Day_One)
{
    EXPECT_NO_THROW(dayOfYear(2, 1, 2001));
}

TEST(dayOfYear_Validation, Feb_Non_Leap_Last_Day)
{
    EXPECT_NO_THROW(dayOfYear(2, 28, 2001));
}

TEST(dayOfYear_Validation, Feb_Non_Leap_Last_Day_Plus_One)
{
    EXPECT_THROW(dayOfYear(2, 29, 2001), std::out_of_range);
}


//February Leap Year
TEST(dayOfYear_Validation, Feb_Leap_Day_Minus_One)
{
    EXPECT_THROW(dayOfYear(2, -1, 2000), std::out_of_range);
}


TEST(dayOfYear_Validation, Feb_Leap_Day_Zero)
{
    EXPECT_THROW(dayOfYear(2, 0, 2000), std::out_of_range);
}


TEST(dayOfYear_Validation, Feb_Leap_Day_One)
{
    EXPECT_NO_THROW(dayOfYear(2, 1, 2000));
}


TEST(dayOfYear_Validation, Feb_Leap_Last_Day)
{
    EXPECT_NO_THROW(dayOfYear(2, 29, 2000));
}


TEST(dayOfYear_Validation, Feb_Leap_Last_Day_Plus_One)
{
    EXPECT_THROW(dayOfYear(2, 30, 2000), std::out_of_range);
}


// March
TEST(dayOfYear_Validation, Mar_Day_Minus_One)
{
    EXPECT_THROW(dayOfYear(3, -1, 2000), std::out_of_range);
}

TEST(dayOfYear_Validation, Mar_Day_Zero)
{
    EXPECT_THROW(dayOfYear(3, 0, 2000), std::out_of_range);
}

TEST(dayOfYear_Validation, Mar_Day_One)
{
    EXPECT_NO_THROW(dayOfYear(3, 1, 2000));
}

TEST(dayOfYear_Validation, Mar_Last_Day)
{
    EXPECT_NO_THROW(dayOfYear(3, 31, 2000));
}

TEST(dayOfYear_Validation, Mar_Last_Day_Plus_One)
{
    EXPECT_THROW(dayOfYear(3, 32, 2000), std::out_of_range);
}