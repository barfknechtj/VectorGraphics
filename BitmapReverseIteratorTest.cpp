//
//  BitmapReverseIteratorTest.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/17/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include "WindowsBitmapHeader.hpp"
#include "TestHarness.h"
#include "BitmapReverseIterator.hpp"

using namespace BitmapGraphics;

TEST(endOfScanLine, BitmapRevIterator)
{
    std::ifstream bitmapStream{"test.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapHeader header(bitmapStream);
    Bitmap bitmap(4, 2, bitmapStream);
    HBitmapIterator bitmapRevIter = std::make_shared<BitmapReverseIterator>(bitmap);
    
    CHECK_EQUAL(false, bitmapRevIter->isEndOfScanLine());
    bitmapRevIter->nextPixel();
    bitmapRevIter->nextPixel();
    CHECK_EQUAL(false, bitmapRevIter->isEndOfScanLine());
    bitmapRevIter->nextPixel();
    bitmapRevIter->nextPixel();
    CHECK_EQUAL(true, bitmapRevIter->isEndOfScanLine());
    bitmapRevIter->nextScanLine();
    bitmapRevIter->nextPixel();
    bitmapRevIter->nextPixel();
    CHECK_EQUAL(false, bitmapRevIter->isEndOfScanLine());
    bitmapRevIter->nextPixel();
    bitmapRevIter->nextPixel();
    CHECK_EQUAL(true, bitmapRevIter->isEndOfScanLine());
}

TEST(endOfImage, BitmapRevIterator)
{
    std::ifstream bitmapStream{"test.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapHeader header(bitmapStream);
    Bitmap bitmap(4, 2, bitmapStream);
    HBitmapIterator BitmapRevIter = std::make_shared<BitmapReverseIterator>(bitmap);
    
    CHECK_EQUAL(false, BitmapRevIter->isEndOfImage());
    
    BitmapRevIter->nextScanLine();
    BitmapRevIter->nextScanLine();
    
    CHECK_EQUAL(true, BitmapRevIter->isEndOfImage());
}

TEST(nextPixel, BitmapRevIterator)
{
    std::ifstream bitmapStream{"test.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapHeader header(bitmapStream);
    Bitmap bitmap(4, 2, bitmapStream);
    HBitmapIterator BitmapRevIter = std::make_shared<BitmapReverseIterator>(bitmap);
    
    auto color1 = BitmapRevIter->getColor();
    BitmapRevIter->nextPixel();
    BitmapRevIter->nextPixel();
    BitmapRevIter->nextPixel();
    auto color4 = BitmapRevIter->getColor();
    BitmapRevIter->nextScanLine();
    auto color5 = BitmapRevIter->getColor();
    BitmapRevIter->nextPixel();
    BitmapRevIter->nextPixel();
    BitmapRevIter->nextPixel();
    auto color8 = BitmapRevIter->getColor();
    
    Color refColor1{0x13, 0x12, 0x11};
    Color refColor4{0x1C, 0x1B, 0x1A};
    Color refColor5{0x03, 0x02, 0x01};
    Color refColor8{0x0C, 0x0B, 0x0A};
    
    CHECK_EQUAL(true, color1 == refColor1);
    CHECK_EQUAL(true, color4 == refColor4);
    CHECK_EQUAL(true, color5 == refColor5);
    CHECK_EQUAL(true, color8 == refColor8);
}

TEST(nextScanLine, BitmapRevIterator)
{
    std::ifstream bitmapStream{"test.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapHeader header(bitmapStream);
    Bitmap bitmap(4, 2, bitmapStream);
    HBitmapIterator BitmapRevIter = std::make_shared<BitmapReverseIterator>(bitmap);
    
    BitmapRevIter->nextScanLine();
    
    Color refColor{0x03, 0x02, 0x01};
    
    auto color = BitmapRevIter->getColor();
    CHECK_EQUAL(true, color == refColor);
}
