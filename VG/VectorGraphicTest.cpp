#include "Parse.h"
#include "VectorGraphic.h"
#include "Utilities.h"
#include "TestHarness.h"
#include "BasicCanvas.hpp"
#include "WindowsBitmapEncoder.hpp"
#include "WindowsBitmapDecoder.hpp"

using namespace BitmapGraphics;

TEST(ctor, VectorGraphic)
{
    VG::VectorGraphic vg;
    CHECK_EQUAL(0, vg.getPointCount());
    CHECK_EQUAL(true, vg.isClosed());
    CHECK_EQUAL(false, vg.isOpen());
}

TEST(insertPoint, VectorGraphic)
{
    VG::VectorGraphic vg;
    vg.addPoint(VG::Point{1, 1});
    CHECK_EQUAL(1, vg.getPointCount());
    
    vg.addPoint(VG::Point{2, 2});
    CHECK_EQUAL(2, vg.getPointCount());
}

TEST(removePoint, VectorGraphic)
{
    VG::VectorGraphic vg;
    vg.addPoint(VG::Point{1, 1});
    vg.addPoint(VG::Point{2, 2});
    vg.removePoint(VG::Point{1, 1});
    
    CHECK_EQUAL(1, vg.getPointCount());
    CHECK_EQUAL(VG::Point(2, 2), vg.getPoint(0));
}

TEST(erasePoint, VectorGraphic)
{
    VG::VectorGraphic vg;
    vg.addPoint(VG::Point{1, 1});
    vg.addPoint(VG::Point{2, 2});
    vg.addPoint(VG::Point{3, 3});
    vg.erasePoint(1);
    
    CHECK_EQUAL(2, vg.getPointCount());
    CHECK_EQUAL(VG::Point(1, 1), vg.getPoint(0));
    CHECK_EQUAL(VG::Point(3, 3), vg.getPoint(1));
}

TEST(erasePointOutOfRange, VectorGraphic)
{
    VG::VectorGraphic vg;
    vg.addPoint(VG::Point{1, 1});
    vg.addPoint(VG::Point{2, 2});
    vg.addPoint(VG::Point{3, 3});
    
    try
    {
        vg.erasePoint(5);
    }
    catch (std::out_of_range&)
    {
        CHECK_EQUAL(3, vg.getPointCount());
        return;
    }
    CHECK(false); // should have caught exception
}

TEST(equality, VectorGraphic)
{
    VG::VectorGraphic vg1;
    vg1.addPoint(VG::Point{1, 1});
    vg1.addPoint(VG::Point{2, 2});
    vg1.addPoint(VG::Point{3, 3});
    
    VG::VectorGraphic vg2;
    vg2.addPoint(VG::Point{1, 1});
    vg2.addPoint(VG::Point{2, 2});
    vg2.addPoint(VG::Point{3, 3});
    
    CHECK(vg1 == vg2);
}

TEST(inequality, VectorGraphic)
{
    VG::VectorGraphic vg1;
    vg1.addPoint(VG::Point{1, 1});
    vg1.addPoint(VG::Point{1, 2});
    vg1.addPoint(VG::Point{1, 3});
    
    VG::VectorGraphic vg2;
    vg2.addPoint(VG::Point{2, 1});
    vg2.addPoint(VG::Point{2, 2});
    vg2.addPoint(VG::Point{2, 3});
    
    CHECK(vg1 != vg2);
    
    VG::VectorGraphic vg3;
    vg3.addPoint(VG::Point{1, 1});
    vg3.addPoint(VG::Point{1, 2});
    vg3.addPoint(VG::Point{1, 3});
    vg3.openShape();
    
    CHECK(vg3 != vg1);
}

TEST(closeShape, VectorGraphic)
{
    VG::VectorGraphic vg;
    vg.closeShape();
    CHECK_EQUAL(true, vg.isClosed());
    CHECK_EQUAL(false, vg.isOpen());
}

TEST(openShape, VectorGraphic)
{
    VG::VectorGraphic vg;
    vg.openShape();
    CHECK_EQUAL(false, vg.isClosed());
    CHECK_EQUAL(true, vg.isOpen());
}

TEST(widthHeight, VectorGraphic)
{
    VG::VectorGraphic vectorGraphic;
    vectorGraphic.addPoint(VG::Point{0, 2});
    vectorGraphic.addPoint(VG::Point{4, 3});
    vectorGraphic.addPoint(VG::Point{5, 8});
    vectorGraphic.addPoint(VG::Point{2, 1});
    CHECK_EQUAL(5, vectorGraphic.getWidth());
    CHECK_EQUAL(7, vectorGraphic.getHeight());
    
    vectorGraphic.erasePoint(2);
    CHECK_EQUAL(4, vectorGraphic.getWidth());
    CHECK_EQUAL(2, vectorGraphic.getHeight());
}

TEST(drawSquareRows, VectorGraphic)
{
    Color lineColor{0, 0, 0};
    HStroke hStroke{new SquareStroke(2, lineColor)};
    
    VG::VectorGraphic vectorGraphic(hStroke);
    vectorGraphic.addPoint(VG::Point{0, 0});
    vectorGraphic.addPoint(VG::Point{5, 0});
    
    Color backgroundColor{255, 255, 255};
    HCanvas hCanvas{new BasicCanvas(5, 5, backgroundColor)};
    
    vectorGraphic.draw(hCanvas, VG::Point(0, 0));
    
    HBitmapIterator canvasIterator = hCanvas->createBitmapIterator();
    
    WindowsBitmapEncoder encoderPrototype{};
    HBitmapEncoder encoder {encoderPrototype.clone(canvasIterator)};
    
    // Write out the bitmap to a different file with its write() method
    std::ofstream outputStream{"VectorGraphicSquareRows.bmp", std::ios::binary};
    CHECK(outputStream.is_open());
    
    encoder->encodeToStream(outputStream);
    outputStream.close();
    
    // read back in
    std::ifstream bitmapStream{"VectorGraphicSquareRows.bmp", std::ios::binary};
    CHECK(bitmapStream.is_open());
    
    WindowsBitmapDecoder decoderPrototype{};
    HBitmapDecoder decoder{decoderPrototype.clone(bitmapStream)};
    HBitmapIterator bitmapIterator = decoder->createIterator();
    
    /* Verify VectorGraphic5x5.bmp is 5x5 white image with a two rows of black */
    int scanLineIndex = 0;
    while(scanLineIndex != 2)
    {
        while (!bitmapIterator->isEndOfScanLine())
        {
            // first two rows should be black
            CHECK_EQUAL(true, lineColor == bitmapIterator->getColor());
            bitmapIterator->nextPixel();
        }
        
        bitmapIterator->nextScanLine();
        ++scanLineIndex;
    }
    
    while (!bitmapIterator->isEndOfImage())
    {
        while (!bitmapIterator->isEndOfScanLine())
        {
            // all other pixels should be background color (white)
            CHECK_EQUAL(true, backgroundColor == bitmapIterator->getColor());
            bitmapIterator->nextPixel();
        }
        
        bitmapIterator->nextScanLine();
    }
}
