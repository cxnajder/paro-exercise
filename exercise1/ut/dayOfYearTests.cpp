#include "gtest/gtest.h"
#include "dayOfYear.hpp"
#include <stdexcept>

// =================== //
// Functionality Tests //
// =================== //

TEST(dayOfYear_Functinality, Normal_Year)
{
    ASSERT_EQ(dayOfYear(4, 20, 2137), 110);
}


TEST(dayOfYear_Functinality, Leap_Year)
{
    ASSERT_EQ(dayOfYear(4, 20, 2040), 111);
}


TEST(dayOfYear_Functinality, January_1st_Is_Fitst_Day_Of_Year)
{
    ASSERT_EQ(dayOfYear(1, 1, 2020), 1);
}


TEST(dayOfYear_Functinality, Leap_Year_On_Last_Day_Of_February)
{
    ASSERT_EQ(dayOfYear(2, 29, 2040), 60);
}


TEST(dayOfYear_Functinality, Leap_Year_On_1st_Day_Of_March)
{
    ASSERT_EQ(dayOfYear(3, 1, 2040), 61);
}


TEST(dayOfYear_Functinality, Last_Day_Of_Year)
{
    ASSERT_EQ(dayOfYear(12, 31, 2021), 365);
}


TEST(dayOfYear_Functinality, Last_Day_Of_Leap_Year)
{
    ASSERT_EQ(dayOfYear(12, 31, 2020), 366);
}


TEST(dayOfYear_Validation, Date_10_10_0)
{
    ASSERT_EQ(dayOfYear(10, 10, 0), 284);
}


TEST(dayOfYear_Validation, Date_10_10_1)
{
    ASSERT_EQ(dayOfYear(10, 10, 1), 283);
}


TEST(dayOfYear_Validation, Date_10_10_999999999)
{
    ASSERT_EQ(dayOfYear(10, 10, 999999999), 283); // There is no upper limit for year value ¯\_(ツ)_/¯
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


// April
TEST(dayOfYear_Validation, Apr_Day_Minus_One)
{
    EXPECT_THROW(dayOfYear(4, -1, 2000), std::out_of_range);
}


TEST(dayOfYear_Validation, Apr_Day_Zero)
{
    EXPECT_THROW(dayOfYear(4, 0, 2000), std::out_of_range);
}


TEST(dayOfYear_Validation, Apr_Day_One)
{
    EXPECT_NO_THROW(dayOfYear(4, 1, 2000));
}


TEST(dayOfYear_Validation, Apr_Last_Day)
{
    EXPECT_NO_THROW(dayOfYear(4, 30, 2000));
}


TEST(dayOfYear_Validation, Apr_Last_Day_Plus_One)
{
    EXPECT_THROW(dayOfYear(4, 31, 2000), std::out_of_range);
}


// ...

// December
TEST(dayOfYear_Validation, Dec_Day_Minus_One)
{
    EXPECT_THROW(dayOfYear(12, -1, 2000), std::out_of_range);
}


TEST(dayOfYear_Validation, Dec_Day_Zero)
{
    EXPECT_THROW(dayOfYear(12, 0, 2000), std::out_of_range);
}


TEST(dayOfYear_Validation, Dec_Day_One)
{
    EXPECT_NO_THROW(dayOfYear(12, 1, 2000));
}


TEST(dayOfYear_Validation, Dec_Last_Day)
{
    EXPECT_NO_THROW(dayOfYear(12, 31, 2000));
}


TEST(dayOfYear_Validation, Dec_Last_Day_Plus_One)
{
    EXPECT_THROW(dayOfYear(12, 32, 2000), std::out_of_range);
}


// Month value Validation
TEST(dayOfYear_Validation, Month_Value_Minus_One)
{
    EXPECT_THROW(dayOfYear(-1, 10, 2000), std::out_of_range);
}


TEST(dayOfYear_Validation, Month_Value_Zero)
{
    EXPECT_THROW(dayOfYear(0, 10, 2000), std::out_of_range);
}


TEST(dayOfYear_Validation, Month_Value_One)
{
    EXPECT_NO_THROW(dayOfYear(1, 10, 2000));
}


TEST(dayOfYear_Validation, Month_Value_Twelve)
{
    EXPECT_NO_THROW(dayOfYear(12, 10, 2000));
}


TEST(dayOfYear_Validation, Month_Value_Thirteen)
{
    EXPECT_THROW(dayOfYear(13, 10, 2000), std::out_of_range);
}


// Year value Validation
TEST(dayOfYear_Validation, Year_Value_Minus_One)
{
    EXPECT_THROW(dayOfYear(10, 10, -1), std::out_of_range);
}


TEST(dayOfYear_Validation, Year_Value_Zero)
{
    EXPECT_NO_THROW(dayOfYear(10, 10, 0));
}


TEST(dayOfYear_Validation, Year_Value_One)
{
    EXPECT_NO_THROW(dayOfYear(10, 10, 1));
}


TEST(dayOfYear_Validation, Year_Value_3000)
{
    EXPECT_NO_THROW(dayOfYear(10, 10, 3000));
}


TEST(dayOfYear_Validation, Year_Value_999999999)
{
    EXPECT_NO_THROW(dayOfYear(10, 10, 999999999));
}