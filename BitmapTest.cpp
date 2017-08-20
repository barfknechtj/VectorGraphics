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

