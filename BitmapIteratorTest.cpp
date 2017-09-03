//
//  BitmapIteratorTest.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/2/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include "WindowsBitmapHeader.hpp"
#include "TestHarness.h"
#include "BitmapIterator.hpp"

using namespace BitmapGraphics;
using HBitmapIterator = std::shared_ptr<IBitmapIterator>;

TEST(endOfScanLine, BitmapIterator)
{
    std::ifstream bitmapStream{"test.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapHeader header(bitmapStream);
    Bitmap bitmap(4, 2, bitmapStream);
    HBitmapIterator bitmapIter = std::make_shared<BitmapIterator>(bitmap);
    
    CHECK_EQUAL(false, bitmapIter->isEndOfScanLine());
    bitmapIter->nextPixel();
    bitmapIter->nextPixel();
    CHECK_EQUAL(false, bitmapIter->isEndOfScanLine());
    bitmapIter->nextPixel();
    bitmapIter->nextPixel();
    CHECK_EQUAL(true, bitmapIter->isEndOfScanLine());
    bitmapIter->nextScanLine();
    bitmapIter->nextPixel();
    bitmapIter->nextPixel();
    CHECK_EQUAL(false, bitmapIter->isEndOfScanLine());
    bitmapIter->nextPixel();
    bitmapIter->nextPixel();
    CHECK_EQUAL(true, bitmapIter->isEndOfScanLine());
}

TEST(endOfImage, BitmapIterator)
{
    std::ifstream bitmapStream{"test.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapHeader header(bitmapStream);
    Bitmap bitmap(4, 2, bitmapStream);
    HBitmapIterator bitmapIter = std::make_shared<BitmapIterator>(bitmap);
    
    CHECK_EQUAL(false, bitmapIter->isEndOfImage());
    
    bitmapIter->nextScanLine();
    bitmapIter->nextScanLine();
    
    CHECK_EQUAL(true, bitmapIter->isEndOfImage());
}

TEST(nextPixel, BitmapIterator)
{
    std::ifstream bitmapStream{"test.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapHeader header(bitmapStream);
    Bitmap bitmap(4, 2, bitmapStream);
    HBitmapIterator bitmapIter = std::make_shared<BitmapIterator>(bitmap);
    
    auto color1 = bitmapIter->getColor();
    bitmapIter->nextPixel();
    bitmapIter->nextPixel();
    bitmapIter->nextPixel();
    auto color4 = bitmapIter->getColor();
    bitmapIter->nextScanLine();
    auto color5 = bitmapIter->getColor();
    bitmapIter->nextPixel();
    bitmapIter->nextPixel();
    bitmapIter->nextPixel();
    auto color8 = bitmapIter->getColor();
    
    Color refColor1{0x03, 0x02, 0x01};
    Color refColor4{0x0C, 0x0B, 0x0A};
    Color refColor5{0x13, 0x12, 0x11};
    Color refColor8{0x1C, 0x1B, 0x1A};
    
    CHECK_EQUAL(true, color1 == refColor1);
    CHECK_EQUAL(true, color4 == refColor4);
    CHECK_EQUAL(true, color5 == refColor5);
    CHECK_EQUAL(true, color8 == refColor8);
}

TEST(nextScanLine, BitmapIterator)
{
    std::ifstream bitmapStream{"test.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapHeader header(bitmapStream);
    Bitmap bitmap(4, 2, bitmapStream);
    HBitmapIterator bitmapIter = std::make_shared<BitmapIterator>(bitmap);
    
    bitmapIter->nextScanLine();
    
    Color refColor{0x13, 0x12, 0x11};

    auto color = bitmapIter->getColor();
    CHECK_EQUAL(true, color == refColor);
}
