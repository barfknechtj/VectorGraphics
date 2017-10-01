//
//  BitmapTest.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include "TestHarness.h"
#include "Color.hpp"
#include "Bitmap.hpp"
#include "WindowsBitmapHeader.hpp"

using namespace BitmapGraphics;

TEST(BitmapSizeTest, Bitmap)
{
    std::ifstream bitmapStream{"basic.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapHeader bitmapHeader{bitmapStream};
    Bitmap bitmap{(int)bitmapHeader.getBitmapWidth(),
                  (int)bitmapHeader.getBitmapHeight(), bitmapStream};
    
    CHECK_EQUAL(100, bitmap.getWidth());
    CHECK_EQUAL(100, bitmap.getHeight());
}

TEST(CalcNumOfPads100, Bitmap)
{
    std::ifstream bitmapStream;
    
    Bitmap bitmap100{100, 100, bitmapStream};
    Bitmap bitmap101{101, 101, bitmapStream};
    Bitmap bitmap102{102, 102, bitmapStream};
    Bitmap bitmap103{103, 103, bitmapStream};
    Bitmap bitmap104{104, 104, bitmapStream};
    
    CHECK_EQUAL(0, bitmap100.calcNumOfPads());
    CHECK_EQUAL(1, bitmap101.calcNumOfPads());
    CHECK_EQUAL(2, bitmap102.calcNumOfPads());
    CHECK_EQUAL(3, bitmap103.calcNumOfPads());
    CHECK_EQUAL(0, bitmap104.calcNumOfPads());
}

TEST(BitmapScanLinesTest, Bitmap)
{
    std::ifstream bitmapStream{"basic.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapHeader bitmapHeader{bitmapStream};
    Bitmap bitmap{(int)bitmapHeader.getBitmapWidth(),
                  (int)bitmapHeader.getBitmapHeight(), bitmapStream};
    
    int numberOfScanLines{0};
    for (auto& scanLine : bitmap)
    {
        CHECK_EQUAL(100, scanLine.size());
        ++numberOfScanLines;
    }
    
    CHECK_EQUAL(100, numberOfScanLines);
}

TEST(BitmapReadWrite, Bitmap)
{
    std::ifstream bitmapStream{"basic.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapHeader bitmapHeader{bitmapStream};
    
    Bitmap bitmap{(int)bitmapHeader.getBitmapWidth(),
                  (int)bitmapHeader.getBitmapHeight(), bitmapStream};
    
    // Write out the bitmap to a different file with its write() method
    std::ofstream outputStream{"output.bmp", std::ios::binary};
    CHECK(outputStream.is_open());
    
    bitmapHeader.write(outputStream);
    bitmap.write(outputStream);
    outputStream.close();
    
    // Read that one back in and check sizes
    std::ifstream bitmapStream2{"output.bmp", std::ios::binary};
    CHECK(bitmapStream2.is_open());
    
    WindowsBitmapHeader bitmapHeader2{bitmapStream2};
    Bitmap bitmap2{(int)bitmapHeader2.getBitmapWidth(),
                   (int)bitmapHeader2.getBitmapHeight(), bitmapStream2};
    
    int numberOfScanLines{0};
    for (auto& scanLine : bitmap2)
    {
        CHECK_EQUAL(100, scanLine.size());
        ++numberOfScanLines;
    }
    
    CHECK_EQUAL(100, numberOfScanLines);
}

// --- Repeat the tests with a bitmap that requires pad bytes (101x101)
TEST(BitmapSizeTest_101, Bitmap)
{
    std::ifstream bitmapStream{"basic_101.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());

    WindowsBitmapHeader bitmapHeader{bitmapStream};
    Bitmap bitmap{(int)bitmapHeader.getBitmapWidth(),
               (int)bitmapHeader.getBitmapHeight(), bitmapStream};

    CHECK_EQUAL(101, bitmap.getWidth());
    CHECK_EQUAL(101, bitmap.getHeight());
}

TEST(BitmapScanLinesTest_101, Bitmap)
{
    std::ifstream bitmapStream{"basic_101.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());

    WindowsBitmapHeader bitmapHeader{bitmapStream};
    Bitmap bitmap{(int)bitmapHeader.getBitmapWidth(),
               (int)bitmapHeader.getBitmapHeight(), bitmapStream};

    int numberOfScanLines{0};
    for (auto scanLine : bitmap)
    {
        CHECK_EQUAL(101, scanLine.size());
        ++numberOfScanLines;
    }
    
    CHECK_EQUAL(101, numberOfScanLines);
}

TEST(BitmapReadWrite_101, Bitmap)
{
    // Read in the bitmap
    std::ifstream bitmapStream{"basic_101.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());

    WindowsBitmapHeader bitmapHeader{bitmapStream};
    Bitmap bitmap{(int)bitmapHeader.getBitmapWidth(),
               (int)bitmapHeader.getBitmapHeight(), bitmapStream};

    // Write out the bitmap to a different file with its write() method
    std::ofstream outputStream{"output_101.bmp", std::ios::binary};
    CHECK(outputStream.is_open());

    bitmapHeader.write(outputStream);
    bitmap.write(outputStream);
    outputStream.close();

    // Read that one back in and check sizes
    std::ifstream bitmapStream2{"output_101.bmp", std::ios::binary};
    CHECK(bitmapStream2.is_open());

    WindowsBitmapHeader bitmapHeader2{bitmapStream2};
    Bitmap bitmap2{(int)bitmapHeader2.getBitmapWidth(),
                (int)bitmapHeader2.getBitmapHeight(), bitmapStream2};

    int numberOfScanLines{0};
    for (auto& scanLine : bitmap2)
    {
        CHECK_EQUAL(101, scanLine.size());
        ++numberOfScanLines;
    }
    
    CHECK_EQUAL(101, numberOfScanLines);
}

