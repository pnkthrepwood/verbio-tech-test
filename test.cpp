#include <gtest/gtest.h>
#include <string>
#include "numformat.h"

TEST (FormatNumbersTest, BasicTests) 
{
    EXPECT_EQ(formatNumbersOfText(string("one hundred and one")), "101");
    EXPECT_EQ(formatNumbersOfText(string("I have one hundred apples")), "I have 100 apples");
}

TEST (FormatNumbersTest, NumberTests) 
{
    EXPECT_EQ(formatNumbersOfText(string("number one")), "number 1");
    EXPECT_EQ(formatNumbersOfText(string("number two")), "number 2");
    EXPECT_EQ(formatNumbersOfText(string("three numbers")), "3 numbers");
    EXPECT_EQ(formatNumbersOfText(string("number eleven")), "number 11");
    EXPECT_EQ(formatNumbersOfText(string("number twenty is after number nineteen")), "number 20 is after number 19");
    EXPECT_EQ(formatNumbersOfText(string("twenty-three is number one")), "23 is number 1");
    EXPECT_EQ(formatNumbersOfText(string("I got a nintendo sixty-four for christmas")), "I got a nintendo 64 for christmas");
    EXPECT_EQ(formatNumbersOfText(string("my grandpa is ninety-nine years old")), "my grandpa is 99 years old");
    EXPECT_EQ(formatNumbersOfText(string("four eight fifteen sixteen twenty-three forty-two")), "4 8 15 16 23 42");
    EXPECT_EQ(formatNumbersOfText(string("my friend captured nine arcanine but I only got one ninetales")), "my friend captured 9 arcanine but I only got 1 ninetales");
    EXPECT_EQ(formatNumbersOfText(string("I wish I had one billion dollars")), "I wish I had 1000000000 dollars");
}

TEST (FormatNumbersTest, HundredsTests) 
{
    EXPECT_EQ(formatNumbersOfText(string("one hundred")), "100");
    EXPECT_EQ(formatNumbersOfText(string("one hundred and one")), "101");
    EXPECT_EQ(formatNumbersOfText(string("one hundred one")), "100 1");
    EXPECT_EQ(formatNumbersOfText(string("one hundred and twelve")), "112");
    EXPECT_EQ(formatNumbersOfText(string("one hundred and twenty-three")), "123");
    EXPECT_EQ(formatNumbersOfText(string("one hundred is a great number")), "100 is a great number");
    EXPECT_EQ(formatNumbersOfText(string("I live in fifth street number two hundred and twenty-two")), "I live in fifth street number 222");
    EXPECT_EQ(formatNumbersOfText(string("my cousin is afraid of the number six hundred and sixty-six")), "my cousin is afraid of the number 666");
    EXPECT_EQ(formatNumbersOfText(string("call to nine hundred and eleven and say stroke")), "call to 911 and say stroke");
}

TEST (FormatNumbersTest, ThousandsTests) 
{
    EXPECT_EQ(formatNumbersOfText(string("one thousand")), "1000");
    EXPECT_EQ(formatNumbersOfText(string("one thousand one")), "1001");
    EXPECT_EQ(formatNumbersOfText(string("one thousand one thousand")), "1001 thousand");
    EXPECT_EQ(formatNumbersOfText(string("one thousand and one thousand")), "1000 and 1000");
    EXPECT_EQ(formatNumbersOfText(string("one thousand three hundred and thirty-seven")), "1337");
    EXPECT_EQ(formatNumbersOfText(string("one thousand and thirty-seven")), "1000 and 37");
    EXPECT_EQ(formatNumbersOfText(string("nine hundred thousand nine hundred and ninety-nine")), "900999");
    EXPECT_EQ(formatNumbersOfText(string("nine hundred thousand nine hundred ninety-nine")), "900900 99");
    EXPECT_EQ(formatNumbersOfText(string("nine hundred thousand one nine hundred ninety-nine")), "900001 900 99");
    EXPECT_EQ(formatNumbersOfText(string("nine hundred thousand one nine hundred and ninety-nine")), "900001 999");
    EXPECT_EQ(formatNumbersOfText(string("nine hundred and ninety-nine thousand nine hundred and ninety-nine")), "999999");
    EXPECT_EQ(formatNumbersOfText(string("thirty-five thousand")), "35000");

}

TEST (FormatNumbersTest, MillionsTest) 
{
    EXPECT_EQ(formatNumbersOfText(string("one million")), "1000000");
    EXPECT_EQ(formatNumbersOfText(string("one million one")), "1000001");
    EXPECT_EQ(formatNumbersOfText(string("one million and one")), "1000000 and 1");
    EXPECT_EQ(formatNumbersOfText(string("one million one thousand")), "1001000");
    EXPECT_EQ(formatNumbersOfText(string("one million one thousand one hundred")), "1001100");
    EXPECT_EQ(formatNumbersOfText(string("one million eleven thousand one hundred")), "1011100");
    EXPECT_EQ(formatNumbersOfText(string("ten million eleven thousand one hundred")), "10011100");
    EXPECT_EQ(formatNumbersOfText(string("one hundred million eleven thousand one hundred")), "100011100");
    EXPECT_EQ(formatNumbersOfText(string("one hundred million eleven thousand one hundred and ten")), "100011110");
    EXPECT_EQ(formatNumbersOfText(string("one hundred million eleven thousand one hundred and eleven")), "100011111");
    EXPECT_EQ(formatNumbersOfText(string("one hundred and ten million eleven thousand one hundred and eleven")), "110011111");
    EXPECT_EQ(formatNumbersOfText(string("one hundred and eleven million eleven thousand one hundred and eleven")), "111011111");
    EXPECT_EQ(formatNumbersOfText(string("one hundred and eleven million one hundred and eleven thousand one hundred and eleven")), "111111111");
    
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}