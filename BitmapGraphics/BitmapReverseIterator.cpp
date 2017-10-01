//
//  BitmapReverseIterator.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "BitmapReverseIterator.hpp"

using namespace BitmapGraphics;

BitmapReverseIterator::BitmapReverseIterator(Bitmap& bitmap)
: myBitmap(bitmap)
{
    _scanLineIter = myBitmap.rbegin();
    
    if(!isEndOfImage())
    {
        _colorIter = _scanLineIter->begin();
    }
}

void BitmapReverseIterator::nextScanLine()
{
    ++_scanLineIter;
    if(!isEndOfImage())
    {
        _colorIter = _scanLineIter->begin();
    }
}

bool BitmapReverseIterator::isEndOfImage()
{
    return _scanLineIter == myBitmap.rend();
}

void BitmapReverseIterator::nextPixel()
{
    ++_colorIter;
}

bool BitmapReverseIterator::isEndOfScanLine()
{
    return _colorIter == _scanLineIter->end();
}

void BitmapReverseIterator::begin()
{
    _scanLineIter = myBitmap.rbegin();
    _colorIter = _scanLineIter->begin();
}

void BitmapReverseIterator::end()
{
    _scanLineIter = (--myBitmap.rend());
    _colorIter = _scanLineIter->end();
}
