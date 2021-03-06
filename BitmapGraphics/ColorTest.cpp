//
//  ColorTest.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/15/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include "TestHarness.h"
#include "Color.hpp"


using namespace BitmapGraphics;

TEST(createColor, Color)
{
    Color color{0xAA, 0xBB, 0xCC};
    
    CHECK_EQUAL(0xAA, color.getRed());
    CHECK_EQUAL(0xBB, color.getGreen());
    CHECK_EQUAL(0xCC, color.getBlue());
}

TEST(createColorWithZeroes, Color)
{
    Color color{0xAA, 0xBB};
    
    CHECK_EQUAL(0xAA, color.getRed());
    CHECK_EQUAL(0xBB, color.getGreen());
    CHECK_EQUAL(0x00, color.getBlue());
}

TEST(createColorWithString, Color)
{
    std::string hexColor = "AABBCC";
    
    Color color(hexColor);

    CHECK_EQUAL(0xCC, color.getBlue());
    CHECK_EQUAL(0xBB, color.getGreen());
    CHECK_EQUAL(0xAA, color.getRed());
}

TEST(createColorWithInvalidString, Color)
{
    std::string hexColor = "AABBC";
    try
    {
        Color color(hexColor);
        CHECK(false);
    }
    catch (const std::exception& exc)
    {
        std::cout << exc.what() << std::endl;
        CHECK(true);
    }
}

TEST(readColor, Color)
{
    unsigned char colorData[]{ 0x23, 0x24, 0x25, 0 };
    std::istringstream colorStream{reinterpret_cast<char*>(colorData)};
    
    Color color{Color::read(colorStream)};
    
    CHECK_EQUAL(0x23, color.getBlue());
    CHECK_EQUAL(0x24, color.getGreen());
    CHECK_EQUAL(0x25, color.getRed());
}

TEST(readScanLines, Color)
{
    unsigned char colorData[]{
        0xAA, 0xBB, 0xCC, 0x23, 0x24, 0x25,
        0x11, 0x22, 0x33, 0xDD, 0xEE, 0xFF,
        0
    };
    std::istringstream colorStream{reinterpret_cast<char*>(colorData)};
    
    typedef std::vector<Color> ScanLine;
    typedef std::vector<ScanLine> ScanLineContainer;
    
    const int Width{2};
    const int Height{2};
    
    ScanLineContainer scanLines;
    
    for (auto row = 0; row < Height; ++row)
    {
        ScanLine scanLine;
        
        for (auto column = 0; column < Width; ++column)
        {
            scanLine.push_back(Color::read(colorStream));
        }
        
        scanLines.push_back(scanLine);
    }
    
    const Color expected{ 0x33, 0x22, 0x11 };
    Color actual{ scanLines[1][0] };
    
    CHECK_EQUAL(true, expected == actual);
}

TEST(write, Color)
{
    unsigned char colorData[]{0xAA, 0xBB, 0xCC};
    std::istringstream colorInStream{reinterpret_cast<char*>(colorData)};
    std::ostringstream colorOutStream;
    
    auto color{Color::read(colorInStream)};
    
    color.write(colorOutStream);
    
    CHECK_EQUAL("\252\273\314", colorOutStream.str());
}
