//
//  BrightnessDecorator.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/5/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "BrightnessDecorator.hpp"
#include "Byte.hpp"

using namespace BitmapGraphics;
using namespace Binary;

BrightnessDecorator::BrightnessDecorator(HBitmapIterator& hBitmapIter,
                                         const int& brightnessAdjust)
    : _myIter(hBitmapIter), myBrightener(brightnessAdjust)
{
}

void BrightnessDecorator::nextScanLine()
{
    _myIter->nextScanLine();
}
bool BrightnessDecorator::isEndOfImage()
{
    return _myIter->isEndOfImage();
}

void BrightnessDecorator::nextPixel()
{
    _myIter->nextPixel();
}
bool BrightnessDecorator::isEndOfScanLine()
{
    return _myIter->isEndOfScanLine();
}

Color BrightnessDecorator::getColor() const
{
    AdjustedComponent adjustedRed{_myIter->getColor().getRed() + myBrightener};
    AdjustedComponent adjustedGreen{_myIter->getColor().getGreen() + myBrightener};
    AdjustedComponent adjustedBlue{_myIter->getColor().getBlue() + myBrightener};
    
    return Color{Byte{static_cast<uint8_t>(adjustedRed)},
                 Byte{static_cast<uint8_t>(adjustedGreen)},
                 Byte{static_cast<uint8_t>(adjustedBlue)}};
}
uint BrightnessDecorator::getBitmapWidth() const
{
    return _myIter->getBitmapWidth();
}
uint BrightnessDecorator::getBitmapHeight() const
{
    return _myIter->getBitmapHeight();
}
