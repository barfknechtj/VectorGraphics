//
//  SquareStrokeTest.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/11/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <stdio.h>
#include "TestHarness.h"
#include "SquareStroke.hpp"
#include "SquarePen.hpp"
#include "BasicCanvas.hpp"
#include "WindowsBitmapEncoder.hpp"
#include "WindowsBitmapDecoder.hpp"

using namespace BitmapGraphics;

TEST(getColor, SquareStroke)
{
    SquareStroke stroke(5, Color{255, 255, 255});
    
    CHECK_EQUAL(true, (Color{255, 255, 255} == stroke.getColor()));
}

TEST(setColor, SquareStroke)
{
    SquareStroke stroke(5, Color{255, 255, 255});
    stroke.setColor(Color{0, 0, 0});
    
    CHECK_EQUAL(true, (Color{0, 0, 0} == stroke.getColor()));
}

TEST(getSize, SquareStroke)
{
    SquareStroke stroke(5, Color{255, 255, 255});
    
    CHECK_EQUAL(5, stroke.getSize());
}

TEST(setSize, SquareStroke)
{
    SquareStroke stroke(5, Color{255, 255, 255});
    stroke.setSize(0);
    
    CHECK_EQUAL(0, stroke.getSize());
}

TEST(createPen, SquareStroke)
{
    Color pixelToSet{0, 255, 0};
    
    SquareStroke stroke(1, pixelToSet);
    HPen hPen = stroke.createPen();
    
    Color backColor{255, 255, 255};
    HCanvas hCanvas{new BasicCanvas(10, 10, backColor)};
    
    /* drawing green point to first pixel within last row of Bitmap
       which is stored with bottom ScanLine first */
    hPen->drawPoint(hCanvas, VG::Point(0, 0));
    
    HBitmapIterator canvasIterator = hCanvas->createBitmapIterator();
    
    WindowsBitmapEncoder encoderPrototype{};
    HBitmapEncoder encoder{encoderPrototype.clone(canvasIterator)};
    
    // Write out the bitmap
    std::ofstream outputStream{"CreatePenDrawing.bmp", std::ios::binary};
    CHECK(outputStream.is_open());
    
    encoder->encodeToStream(outputStream);
    outputStream.close();
    
    // Read that one back in
    std::ifstream bitmapStream{"CreatePenDrawing.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapDecoder decoderPrototype{};
    HBitmapDecoder decoder{decoderPrototype.clone(bitmapStream)};
    auto bitmapIter = decoder->createIterator();
    
    // Confirm green pixel is first point
    CHECK_EQUAL(true, pixelToSet == bitmapIter->getColor());
}
