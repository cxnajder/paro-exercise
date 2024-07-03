#include "gtest/gtest.h"
#include "scrabbleScore.h"

TEST(cxnajderCode_scrabbleScore, cabbage)
{
    ASSERT_EQ(cxnajdersCode::countScrabbleScore("cabbage"), 14);
}

TEST(cxnajderCode_scrabbleScore, CABBAGE)
{
    ASSERT_EQ(cxnajdersCode::countScrabbleScore("CABBAGE"), 14);
}