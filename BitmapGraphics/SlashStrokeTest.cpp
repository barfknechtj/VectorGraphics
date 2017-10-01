//
//  SlashStrokeTest.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <stdio.h>
#include "TestHarness.h"
#include "SlashStroke.hpp"
#include "SlashPen.hpp"
#include "BasicCanvas.hpp"
#include "WindowsBitmapEncoder.hpp"
#include "WindowsBitmapDecoder.hpp"

using namespace BitmapGraphics;

TEST(copy, SlashStroke)
{
    SlashStroke stroke1(5, Color{255, 255, 255});
    SlashStroke stroke2(stroke1);
    
    CHECK_EQUAL(true, (Color{255, 255, 255} == stroke1.getColor()));
    CHECK_EQUAL(true, (Color{255, 255, 255} == stroke2.getColor()));
}

TEST(assignment, SlashStroke)
{
    SlashStroke stroke1(5, Color{255, 255, 255});
    SlashStroke stroke2 = stroke1;
    
    CHECK_EQUAL(true, (Color{255, 255, 255} == stroke1.getColor()));
    CHECK_EQUAL(true, (Color{255, 255, 255} == stroke2.getColor()));
}

TEST(copyMove, SlashStroke)
{
    SlashStroke stroke(SlashStroke(5, Color{255, 255, 255}));
    
    CHECK_EQUAL(true, (Color{255, 255, 255} == stroke.getColor()));
}

TEST(assignmentMove, SlashStroke)
{
    SlashStroke stroke = SlashStroke(5, Color{255, 255, 255});;
    
    CHECK_EQUAL(true, (Color{255, 255, 255} == stroke.getColor()));
}

TEST(getColor, SlashStroke)
{
    SlashStroke stroke(5, Color{255, 255, 255});
    
    CHECK_EQUAL(true, (Color{255, 255, 255} == stroke.getColor()));
}

TEST(setColor, SlashStroke)
{
    SlashStroke stroke(5, Color{255, 255, 255});
    stroke.setColor(Color{0, 0, 0});
    
    CHECK_EQUAL(true, (Color{0, 0, 0} == stroke.getColor()));
}

TEST(getSize, SlashStroke)
{
    SlashStroke stroke(5, Color{255, 255, 255});
    
    CHECK_EQUAL(5, stroke.getSize());
}

TEST(setSize, SlashStroke)
{
    SlashStroke stroke(5, Color{255, 255, 255});
    stroke.setSize(0);
    
    CHECK_EQUAL(0, stroke.getSize());
}

TEST(createPen, SlashStroke)
{
    Color pixelToSet{0, 255, 0};
    
    SlashStroke stroke(1, pixelToSet);
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
    std::ofstream outputStream{"CreateSlashPenDrawing.bmp", std::ios::binary};
    CHECK(outputStream.is_open());
    
    encoder->encodeToStream(outputStream);
    outputStream.close();
    
    // Read that one back in
    std::ifstream bitmapStream{"CreateSlashPenDrawing.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapDecoder decoderPrototype{};
    HBitmapDecoder decoder{decoderPrototype.clone(bitmapStream)};
    auto bitmapIter = decoder->createIterator();
    
    // Confirm green pixel is first point
    CHECK_EQUAL(true, pixelToSet == bitmapIter->getColor());
}
