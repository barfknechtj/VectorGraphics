//
//  Bitmap.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "Bitmap.hpp"
#include "Color.hpp"

using BitmapGraphics::Bitmap;
typedef std::list<BitmapGraphics::Color> ScanLine;
typedef std::list<ScanLine> ScanLineCollection;
typedef ScanLineCollection::iterator ScanLineIterator;

Bitmap::Bitmap (const int& width, const int& height, std::istream& sourceStream)
    : myWidth(width), myHeight(height), myScanLineCollection()
{
    for (auto row = 0; row < height; ++row)
    {
        ScanLine scanLine;
        
        for (auto column = 0; column < width; ++column)
        {
            scanLine.push_back(Color::read(sourceStream));
        }
        
        myScanLineCollection.push_back(std::move(scanLine));
    }
}

ScanLineIterator Bitmap::begin()
{
    return myScanLineCollection.begin();
}

ScanLineIterator Bitmap::end()
{
    return myScanLineCollection.end();
}

void Bitmap::write(std::ostream& destinationStream) const
{
    for (auto scanLine : myScanLineCollection)
    {
        for (auto color : scanLine)
        {
            color.write(destinationStream);
        }
    }
}
