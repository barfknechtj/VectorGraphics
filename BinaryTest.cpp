//
//  BinaryTest.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/11/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <stdio.h>
#include <sstream>
#include "TestHarness.h"
#include "DoubleWord.hpp"
#include "Byte.hpp"
#include "Word.hpp"


TEST(readByte, Byte)
{
    std::stringstream ss{"abc"};
    
    auto b = Binary::Byte::read(ss);
    CHECK_EQUAL('a', b);
    
    b = Binary::Byte::read(ss);
    CHECK_EQUAL('b', b);
    
    b = Binary::Byte::read(ss);
    CHECK_EQUAL('c', b);
}

TEST(constructByte, Byte)
{
    Binary::Byte b('x');
    
    std::stringstream ss;
    b.write(ss);
    
    CHECK_EQUAL("x", ss.str());
}

TEST(writeByte, Byte)
{
    Binary::Byte b{'x'};
    
    std::stringstream ss;
    b.write(ss);
    
    CHECK_EQUAL("x", ss.str());
}

TEST(assign, Byte)
{
    unsigned char c1{'a'};
    Binary::Byte byte1;
    byte1 = c1;
    CHECK_EQUAL('a', byte1);

    Binary::Byte byte2{'b'};
    CHECK_EQUAL('b', byte2);

    unsigned char c3{};
    c3 = byte2;
    CHECK_EQUAL('b', c3);
    
    unsigned char c4{byte1};
    CHECK_EQUAL('a', c4);
    
    Binary::Byte byte3{c4};
    CHECK_EQUAL('a', byte3);

    Binary::Byte byte4{byte3};
    CHECK_EQUAL('a', byte4);
    
    Binary::Byte byte5{};
    byte5 = byte4;
    CHECK_EQUAL('a', byte5);
}

TEST(readWordLittleEndian, Binary)
{
    unsigned char carray[]{ 0xb1, 0xb2, 0 };
    std::stringstream ss{reinterpret_cast<char*>(carray)};
    
    const Binary::Word expected{0xb2b1};
    Binary::Word actual = Binary::Word::readLittleEndian(ss);
    
    CHECK_EQUAL(expected, actual);
}

TEST(readWordBigEndian, Binary)
{
    unsigned char carray[]{ 0xb1, 0xb2, 0 };
    std::stringstream ss{reinterpret_cast<char*>(carray)};
    
    const Binary::Word expected{0xb1b2};
    Binary::Word actual = Binary::Word::readBigEndian(ss);
    
    CHECK_EQUAL(expected, actual);
}

TEST(writeWordLittleEndian, Binary)
{
    unsigned char carray[]{ 0xb1, 0xb2, 0 };
    std::stringstream ss{reinterpret_cast<char*>(carray)};
    
    const Binary::Word expected{0xb1b2};
    Binary::Word actual = Binary::Word::readLittleEndian(ss);
    
    std::stringstream ssOutput;
    actual.writeLittleEndian(ssOutput);
    
    CHECK_EQUAL("\261\262", ssOutput.str());
}

TEST(writeWordBigEndian, Binary)
{
    unsigned char carray[]{ 0xb1, 0xb2, 0 };
    std::stringstream ss{reinterpret_cast<char*>(carray)};
    
    const Binary::Word expected{0xb1b2};
    Binary::Word actual = Binary::Word::readLittleEndian(ss);
    
    std::stringstream ssOutput;
    actual.writeBigEndian(ssOutput);
    
    CHECK_EQUAL("\262\261", ssOutput.str());
}

TEST(readDoubleWordLittleEndian, Binary)
{
    unsigned char carray[]{ 0xb1, 0xb2, 0xb3, 0xb4, 0 };
    std::stringstream ss{reinterpret_cast<char*>(carray)};
    
    const Binary::DoubleWord expected(0xb4b3b2b1);
    Binary::DoubleWord actual = Binary::DoubleWord::readLittleEndian(ss);
    
    CHECK_EQUAL(expected, actual);
}

TEST(readDoubleWordBigEndian, Binary)
{
    unsigned char carray[]{ 0xb1, 0xb2, 0xb3, 0xb4, 0 };
    std::stringstream ss{reinterpret_cast<char*>(carray)};
    
    const Binary::DoubleWord expected{0xb1b2b3b4};
    Binary::DoubleWord actual = Binary::DoubleWord::readBigEndian(ss);
    
    CHECK_EQUAL(expected, actual);
}

TEST(writeDoubleWordLittleEndian, Binary)
{
    unsigned char carray[]{ 0xb1, 0xb2, 0xb3, 0xb4, 0 };
    std::stringstream ss{reinterpret_cast<char*>(carray)};
    
    auto actual = Binary::DoubleWord::readLittleEndian(ss);
    
    std::stringstream ssOutput;
    actual.writeLittleEndian(ssOutput);
    
    CHECK_EQUAL("\261\262\263\264", ssOutput.str());
}

TEST(writeDoubleWordBigEndian, Binary)
{
    unsigned char carray[]{ 0xb1, 0xb2, 0xb3, 0xb4, 0 };
    std::stringstream ss{reinterpret_cast<char*>(carray)};
    
    auto actual = Binary::DoubleWord::readLittleEndian(ss);
    
    std::stringstream ssOutput;
    actual.writeBigEndian(ssOutput);
    
    CHECK_EQUAL("\264\263\262\261", ssOutput.str());
}
