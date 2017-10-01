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
    
    if(!isEndOfImage())
    {
        _colorIter = _scanLineIter->begin();
    }
}

void BitmapIterator::nextScanLine()
{
    ++_scanLineIter;
    if(!isEndOfImage())
    {
        _colorIter = _scanLineIter->begin();
    }
}

bool BitmapIterator::isEndOfImage()
{
    return _scanLineIter == myBitmap.end();
}

void BitmapIterator::nextPixel()
{
    ++_colorIter;
}

bool BitmapIterator::isEndOfScanLine()
{
    return _colorIter == _scanLineIter->end();
}

void BitmapIterator::begin()
{
    _scanLineIter = myBitmap.begin();
    _colorIter = _scanLineIter->begin();
}

void BitmapIterator::end()
{
    _scanLineIter = (--myBitmap.end());
    _colorIter = _scanLineIter->end();
}
