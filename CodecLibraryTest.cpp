//
//  BitmapIteratorTest.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/3/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <fstream>
#include <memory>
#include "TestHarness.h"
#include "CodecLibrary.hpp"
//#include "BrightnessDecorator.h"
//#include "ColorInversionDecorator.h"
#include "WindowsBitmapDecoder.hpp"
#include "WindowsBitmapEncoder.hpp"
#include "BitmapIterator.hpp"


using namespace BitmapGraphics;
using HBitmapDecoder = std::shared_ptr<IBitmapDecoder>;
using HBitmapEncoder = std::shared_ptr<IBitmapEncoder>;


namespace
{
    const std::string msBmp{"image/x-ms-bmp"};
    
    std::shared_ptr<CodecLibrary> theCodecLibrary {};

    void setUp()
    {
        theCodecLibrary.reset(new CodecLibrary);
        theCodecLibrary->registerEncoder(HBitmapEncoder(new WindowsBitmapEncoder));
        theCodecLibrary->registerDecoder(HBitmapDecoder(new WindowsBitmapDecoder));
    }

    void tearDown()
    {
        theCodecLibrary.reset();
    }
}

TEST(invalidDecoder, CodecLibrary)
{
    HBitmapDecoder decoder{new WindowsBitmapDecoder};

    try
    {
        decoder->createIterator();
        CHECK(false);
    }
    catch (const std::exception& exc)
    {
        std::cout << exc.what() << std::endl;
        CHECK(true);
    }
}

TEST(invalidEncoder, CodecLibrary)
{
    HBitmapEncoder encoder{new WindowsBitmapEncoder};

    try
    {
        std::ostringstream os{std::ios::binary};
        encoder->encodeToStream(os);
    }
    catch (const std::exception& exc)
    {
        std::cout << exc.what() << std::endl;
        CHECK(true);
    }
}
/*
TEST(createEncoderViaMimeType, CodecLibrary)
{
    setUp();
    
    Bitmap nullBitmap{0, 0};
    HBitmapIterator iterator {nullBitmap.createIterator()};
    HBitmapEncoder encoder {theCodecLibrary->createEncoder(msBmp, iterator)};

    CHECK(dynamic_cast<WindowsBitmapEncoder*>(encoder.get()));

    tearDown();
}

TEST(failedCreateEncoderViaMimeType, CodecLibrary)
{
    setUp();
    
    Bitmap nullBitmap{0, 0};
    HBitmapIterator iterator {nullBitmap.createIterator()};
    
    try
    {
        HBitmapEncoder encoder {theCodecLibrary->createEncoder("image/unsupported-type", iterator)};
        CHECK(false);
    }
    catch (const std::exception& exc)
    {
        std::cout << exc.what() << std::endl;
        CHECK(true);
    }
    
    tearDown();
}

TEST(createDecoderViaMimeType, CodecLibrary)
{
    setUp();

    std::stringstream ss;
    HBitmapDecoder decoder {theCodecLibrary->createDecoder(msBmp, ss)};

    CHECK(dynamic_cast<WindowsBitmapDecoder*>(decoder.get()));

    tearDown();
}

TEST(createFailedDecoderViaMimeType, CodecLibrary)
{
    setUp();
    
    std::stringstream ss;
    
    try
    {
        HBitmapDecoder decoder {theCodecLibrary->createDecoder("image/unsupported-type", ss)};
        CHECK(false);
    }
    catch (const std::exception& exc)
    {
        std::cout << exc.what() << std::endl;
        CHECK(true);
    }

    tearDown();
}

TEST(createDecoderAutoDetermine, CodecLibrary)
{
    setUp();

    std::ifstream inFile{"basic.bmp", std::ios::binary};
    CHECK_EQUAL(0, !inFile);
    HBitmapDecoder decoder {theCodecLibrary->createDecoder(inFile)};

    CHECK(decoder.get());
    CHECK(dynamic_cast<WindowsBitmapDecoder*>(decoder.get()));

    tearDown();
}

TEST(windowsBitmapDecodeEncode, CodecLibrary)
{
    setUp();

    std::ifstream inFile{"basic.bmp", std::ios::binary};
    CHECK_EQUAL(0, !inFile);
    
    HBitmapDecoder decoder {theCodecLibrary->createDecoder(inFile)};
    HBitmapIterator iterator {decoder->createIterator()};
    
    CHECK(iterator.get());
    CHECK_EQUAL(100, iterator->getBitmapHeight());
    CHECK_EQUAL(100, iterator->getBitmapWidth());

    HBitmapEncoder encoder {theCodecLibrary->createEncoder(msBmp, iterator)};

    std::ofstream outFile{"output_basicCopy.bmp", std::ios::binary};
    encoder->encodeToStream(outFile);
    // TODO: file compare input/output

    tearDown();
}

TEST(brightnessDecoratorIterator, CodecLibrary)
{
    setUp();

    std::ifstream inFile{"basic.bmp", std::ios::binary};
    CHECK_EQUAL(0, !inFile);
    
    HBitmapDecoder decoder {theCodecLibrary->createDecoder(inFile)};
    HBitmapIterator iterator {decoder->createIterator()};
    
    CHECK(iterator.get());
    CHECK_EQUAL(100, iterator->getBitmapHeight());
    CHECK_EQUAL(100, iterator->getBitmapWidth());

    HBitmapIterator brightnessIterator{new BrightnessDecorator(iterator, 80)};
    HBitmapEncoder encoder {theCodecLibrary->createEncoder(msBmp, brightnessIterator)};

    std::ofstream outFile{"output_basicBrightnessAdjusted.bmp", std::ios::binary};
    encoder->encodeToStream(outFile);
    // TODO: file compare input/output

    tearDown();
}

TEST(colorInvertDecoratorIterator, CodecLibrary)
{
    setUp();

    std::ifstream inFile{"basic.bmp", std::ios::binary};
    CHECK_EQUAL(0, !inFile);
    
    HBitmapDecoder decoder {theCodecLibrary->createDecoder(inFile)};
    HBitmapIterator iterator {decoder->createIterator()};
    
    CHECK(iterator.get());
    CHECK_EQUAL(100, iterator->getBitmapHeight());
    CHECK_EQUAL(100, iterator->getBitmapWidth());

    HBitmapIterator colorInvertIterator{new ColorInversionDecorator{iterator}};
    HBitmapEncoder encoder {theCodecLibrary->createEncoder(msBmp, colorInvertIterator)};

    std::ofstream outFile{"output_basicColorInvert.bmp", std::ios::binary};
    encoder->encodeToStream(outFile);
    // TODO: file compare input/output

    tearDown();
}

TEST(doubleDecorator, CodecLibrary)
{
    setUp();

    std::ifstream inFile{"basic.bmp", std::ios::binary};
    CHECK_EQUAL(0, !inFile);
    
    HBitmapDecoder decoder {theCodecLibrary->createDecoder(inFile)};
    HBitmapIterator iterator {decoder->createIterator()};
    
    CHECK(iterator.get());
    CHECK_EQUAL(100, iterator->getBitmapHeight());
    CHECK_EQUAL(100, iterator->getBitmapWidth());

    HBitmapIterator colorInvertIterator{new ColorInversionDecorator{iterator}};
    HBitmapIterator darkenColorInvertIterator{new BrightnessDecorator{colorInvertIterator, -50}};

    HBitmapEncoder encoder {theCodecLibrary->createEncoder(msBmp, darkenColorInvertIterator)};
        
    std::ofstream outFile{"output_darkInverted.bmp", std::ios::binary};
    encoder->encodeToStream(outFile);
    // TODO: file compare input/output

    tearDown();
}
*/