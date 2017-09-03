//
//  BitmapEncodeDecodeTests.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/25/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include "TestHarness.h"
#include "Bitmap.hpp"
#include "WindowsBitmapDecoder.hpp"
#include "WindowsBitmapEncoder.hpp"
#include "BitmapIterator.hpp"

using namespace BitmapGraphics;
using HBitmapDecoder = std::shared_ptr<IBitmapDecoder>;
using HBitmapEncoder = std::shared_ptr<IBitmapEncoder>;
using HBitmapIterator = std::shared_ptr<IBitmapIterator>;


TEST(createDecoder, WindowsBitmapDecoder)
{
    std::ifstream bitmapStream{"basic.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapDecoder decoderPrototype{};
    HBitmapDecoder decoder{decoderPrototype.clone(bitmapStream)};
    CHECK_EQUAL("image/x-ms-bmp", decoder->getMimeType());
}

TEST(BitmapSizeTest, BitmapIterator)
{
    std::ifstream bitmapStream{"basic.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapDecoder decoderPrototype{};
    HBitmapDecoder decoder {decoderPrototype.clone(bitmapStream)};
    HBitmapIterator bitmapIter {decoder->createIterator()};
    
    CHECK_EQUAL(100, bitmapIter->getBitmapWidth());
    CHECK_EQUAL(100, bitmapIter->getBitmapHeight());
}

TEST(BitmapScanLinesShortTest, BitmapIterator)
{
    std::ifstream bitmapStream{"test.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapDecoder decoderPrototype{};
    HBitmapDecoder decoder {decoderPrototype.clone(bitmapStream)};
    HBitmapIterator bitmapIter {decoder->createIterator()};
    
    int numberOfScanLines{0};
    while (!bitmapIter->isEndOfImage())
    {
        int numberOfPixelsInScanLine{0};
        while (!bitmapIter->isEndOfScanLine())
        {
            ++numberOfPixelsInScanLine;
            bitmapIter->nextPixel();
        }
        CHECK_EQUAL(4, numberOfPixelsInScanLine);
        ++numberOfScanLines;
        
        bitmapIter->nextScanLine();
    }
    CHECK_EQUAL(2, numberOfScanLines);
}

TEST(BitmapScanLinesTest, BitmapIterator)
{
    std::ifstream bitmapStream{"basic.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapDecoder decoderPrototype{};
    HBitmapDecoder decoder {decoderPrototype.clone(bitmapStream)};
    HBitmapIterator bitmapIter {decoder->createIterator()};
    
    int numberOfScanLines{0};
    while (! bitmapIter->isEndOfImage())
    {
        int numberOfPixelsInScanLine{0};
        while (! bitmapIter->isEndOfScanLine())
        {
            ++numberOfPixelsInScanLine;
            bitmapIter->nextPixel();
        }
        CHECK_EQUAL(100, numberOfPixelsInScanLine);
        ++numberOfScanLines;
        
        bitmapIter->nextScanLine();
    }
    CHECK_EQUAL(100, numberOfScanLines);
}
/*
TEST(BitmapEncodeDecode, Bitmap)
{
    // Read in the bitmap
    std::ifstream bitmapStream{"basic.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());

    WindowsBitmapDecoder decoderPrototype{};
    HBitmapDecoder decoder {decoderPrototype.clone(bitmapStream)};
    HBitmapIterator bitmapIter {decoder->createIterator()};

    // Write out the bitmap to a different file with its write() method
    std::ofstream outputStream{"EncodedOutput.bmp", std::ios::binary};
    CHECK(outputStream.is_open());
    
    WindowsBitmapEncoder encoderPrototype{};
    HBitmapEncoder encoder {encoderPrototype.clone(bitmapIter)};
    
    encoder->encodeToStream(outputStream);
    outputStream.close();

    // Read that one back in and check sizes
    std::ifstream bitmapStream2{"EncodedOutput.bmp", std::ios::binary};
    CHECK(bitmapStream2.is_open());

    HBitmapDecoder decoder2 {decoderPrototype.clone(bitmapStream2)};
    bitmapIter = decoder2->createIterator();
    
    int numberOfScanLines{0};
    while (! bitmapIter->isEndOfImage())
    {
        int numberOfPixelsInScanLine{0};
        while (! bitmapIter->isEndOfScanLine())
        {
            ++numberOfPixelsInScanLine;
            bitmapIter->nextPixel();
        }
        CHECK_EQUAL(100, numberOfPixelsInScanLine);
        ++numberOfScanLines;
        
        bitmapIter->nextScanLine();
    }
    CHECK_EQUAL(100, numberOfScanLines);
}
*/

//// --- Repeat the tests with a bitmap that requires pad bytes (101x101)
TEST(BitmapSizeTest_101, BitmapIterator)
{
    std::ifstream bitmapStream{"basic_101.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapDecoder decoderPrototype{};
    HBitmapDecoder decoder {decoderPrototype.clone(bitmapStream)};
    HBitmapIterator bitmapIter {decoder->createIterator()};
    
    CHECK_EQUAL(101, bitmapIter->getBitmapWidth());
    CHECK_EQUAL(101, bitmapIter->getBitmapHeight());
}

TEST(BitmapScanLinesTest_101, BitmapIterator)
{
    std::ifstream bitmapStream{"basic_101.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapDecoder decoderPrototype{};
    HBitmapDecoder decoder {decoderPrototype.clone(bitmapStream)};
    HBitmapIterator bitmapIter {decoder->createIterator()};
    
    int numberOfScanLines {0};
    while (! bitmapIter->isEndOfImage())
    {
        int numberOfPixelsInScanLine {0};
        while (! bitmapIter->isEndOfScanLine())
        {
            ++numberOfPixelsInScanLine;
            bitmapIter->nextPixel();
        }
        CHECK_EQUAL(101, numberOfPixelsInScanLine);
        ++numberOfScanLines;
        
        bitmapIter->nextScanLine();
    }
    CHECK_EQUAL(101, numberOfScanLines);
}
/*
TEST(BitmapReadWrite_101, Bitmap)
{
    // Read in the bitmap
    
    std::ifstream bitmapStream{"basic_101.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapDecoder decoderPrototype{};
    HBitmapDecoder decoder {decoderPrototype.clone(bitmapStream)};
    HBitmapIterator bitmapIter {decoder->createIterator()};
    
    // Write out the bitmap to a different file with its write() method
    
    std::ofstream outputStream{"EncodeOutput_101.bmp", std::ios::binary};
    CHECK(outputStream.is_open());
    
    WindowsBitmapEncoder encoderPrototype{};
    HBitmapEncoder encoder {encoderPrototype.clone(bitmapIter)};
    
    encoder->encodeToStream(outputStream);
    outputStream.close();
    
    // Read that one back in and check sizes
    std::ifstream bitmapStream2{"EncodedOutput_101.bmp", std::ios::binary};
    CHECK(bitmapStream2.is_open());
    
    HBitmapDecoder decoder2 {decoderPrototype.clone(bitmapStream2)};
    bitmapIter = decoder2->createIterator();
    
    int numberOfScanLines {0};
    while (! bitmapIter->isEndOfImage())
    {
        int numberOfPixelsInScanLine {0};
        while (! bitmapIter->isEndOfScanLine())
        {
            ++numberOfPixelsInScanLine;
            bitmapIter->nextPixel();
        }
        CHECK_EQUAL(101, numberOfPixelsInScanLine);
        ++numberOfScanLines;
        
        bitmapIter->nextScanLine();
    }
    CHECK_EQUAL(101, numberOfScanLines);
}
*/
