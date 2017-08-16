//
//  VerifyEqualityTest.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/15/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <iostream>
#include "TestHarness.h"
#include "VerifyEquality.h"
#include "Word.hpp"
#include "DoubleWord.hpp"

TEST(verifyEquality, Word)
{
    const unsigned char input[]{ 0xAB, 0xCD, 0 };
    std::stringstream ss{reinterpret_cast<const char*>(input)};
    
    Binary::Word actual{ Binary::Word::readLittleEndian(ss) };
    const Binary::Word notReallyExpected{0xABCD};
    
    try
    {
        verifyEquality(notReallyExpected, actual, "notReallyExpected");
        CHECK(false);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        CHECK(true);
    }
}
/*
TEST(verifyEquality, DoubleWord)
{
    const unsigned char input[]{ 0xAB, 0xCD, 0xAB, 0xCD, 0 };
    std::stringstream ss{reinterpret_cast<const char*>(input)};
    
    Binary::Word actual{ Binary::DoubleWord::readLittleEndian(ss) };
    const Binary::DoubleWord notReallyExpected{0xABCDABCD};
    
    try
    {
        verifyEquality(notReallyExpected, actual, "notReallyExpected");
        CHECK(false);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        CHECK(true);
    }
}
*/
