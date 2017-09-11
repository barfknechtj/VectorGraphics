//
//  Bitmap.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "Bitmap.hpp"
#include "BitmapIterator.hpp"

#include <sstream>

using BitmapGraphics::Bitmap;
typedef std::list<BitmapGraphics::Color> ScanLine;
typedef std::list<ScanLine> ScanLineCollection;
typedef ScanLineCollection::iterator ScanLineIterator;

using namespace BitmapGraphics;

Bitmap::Bitmap(const int& width, const int& height, std::istream& sourceStream)
    : myWidth(width), myHeight(height), myScanLineCollection()
{
    /* 0x0 is inserted into bitmap to make them 4-byte
       aligned. Discard pads when reading  */
    
    auto numOfPads = calcNumOfPads();
    char trashOfPads[numOfPads];
    
    for (auto row = 0; row < height; ++row)
    {
        ScanLine scanLine;
        
        for (auto column = 0; column < width; ++column)
        {
            scanLine.push_back(Color::read(sourceStream));
        }
        
        myScanLineCollection.push_back(std::move(scanLine));
        
        // remove any padding bytes
        sourceStream.read(trashOfPads, numOfPads);
    }
}

Bitmap::Bitmap(const int& width, const int& height, const Color& backgroundColor)
    : myWidth(width), myHeight(height), myScanLineCollection()
{    
    for (auto row = 0; row < height; ++row)
    {
        ScanLine scanLine;
        
        for (auto column = 0; column < width; ++column)
        {
            scanLine.push_back(backgroundColor);
        }
        
        myScanLineCollection.push_back(std::move(scanLine));
    }
}

int Bitmap::calcNumOfPads() const
{
    /* 0x0 is inserted into bitmaps to make them 4-byte
       aligned. Caluclate number of pads used to construct
       bitmap  */
    
    int colorComponents = 3;
    int byteAlignment = 4;
    int numOfPads = 0;
    
    if (auto remainder = myWidth * colorComponents % byteAlignment)
    {
        numOfPads = byteAlignment - remainder;
    }
    
    return numOfPads;
}

HBitmapIterator Bitmap::createIterator()
{
    return std::make_shared<BitmapIterator>(*this);
}

void Bitmap::write(std::ostream& destinationStream) const
{
    /* 0x0 is inserted into bitmaps to make them 4-byte
       aligned. Add correct number (0 - 3) of pads when
       writing */
    
    int numOfPads = calcNumOfPads();
    char pads[] = {0x0, 0x0, 0x0};
    
    for (auto scanLine : myScanLineCollection)
    {
        for (auto color : scanLine)
        {
            color.write(destinationStream);
        }
        
        // add any padding bytes
        destinationStream.write(pads, numOfPads);
    }
}
