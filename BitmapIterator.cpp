//
//  BitmapIterator.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/31/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "BitmapIterator.hpp"

using namespace BitmapGraphics;

BitmapIterator::BitmapIterator(Bitmap& bitmap)
    : myBitmap(bitmap)
{
        _scanLineIter = myBitmap.begin();
        _colorIter = _scanLineIter->begin();
}

void BitmapIterator::nextScanLine()
{
    ++_scanLineIter;
    _colorIter = _scanLineIter->begin();    
}

bool BitmapIterator::isEndOfImage()
{
    return _scanLineIter == myBitmap.end();
}

void BitmapIterator::nextPixel()
{
    ++_colorIter;
}

bool BitmapGraphics::BitmapIterator::isEndOfScanLine()
{
    return _colorIter == _scanLineIter->end();
}
