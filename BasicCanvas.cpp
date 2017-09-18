//
//  BasicCanvas.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/7/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "BasicCanvas.hpp"
#include <fstream>

using namespace BitmapGraphics;

BasicCanvas::BasicCanvas(const int& width, const int& height,
                         const Color& backgroundColor)
    : hCanvas(new Bitmap{width, height, backgroundColor})
{
    hCanvasIter = hCanvas->createIterator();;
}

void BasicCanvas::setPixelColor (VG::Point const& location,
                                 Color const& color)
{
    // block if another thread is setting/getting pixel data
    myMutex.lock();
    
    if(location.getY() >= hCanvas->getHeight() ||
       location.getX() >= hCanvas->getWidth())
    {
        throw std::runtime_error("Indexed pixel is out of bounds");
    }
    
    hCanvasIter->begin();
    
    for(int canvasRow = 0; canvasRow != location.getY(); ++canvasRow)
    {
        hCanvasIter->nextScanLine();
    }
    
    for(int pixelIndex = 0; pixelIndex != location.getX(); ++pixelIndex)
    {
        hCanvasIter->nextPixel();
    }
    
    hCanvasIter->setColor(color);
    
    myMutex.unlock();
}

Color BasicCanvas::getPixelColor(VG::Point const& location)
{
    // block if another thread is setting/getting pixel data
    myMutex.lock();
    
    if(location.getY() >= hCanvas->getHeight() ||
       location.getX() >= hCanvas->getWidth())
    {
        throw std::runtime_error("Indexed pixel is out of bounds");
    }
    
    hCanvasIter->begin();
    
    for(int canvasRow = 0; canvasRow != location.getY(); ++canvasRow)
    {
        hCanvasIter->nextScanLine();
    }

    for(int pixelIndex = 0; pixelIndex != location.getX(); ++pixelIndex)
    {
        hCanvasIter->nextPixel();
    }
    
    Color retrievedColor(hCanvasIter->getColor());
    
    myMutex.unlock();
        
    return retrievedColor;
}

int BasicCanvas::getWidth() const
{
    return hCanvas->getWidth();
}

int BasicCanvas::getHeight() const
{
    return hCanvas->getHeight();
}
        
HBitmapIterator BasicCanvas::createBitmapIterator() const
{
    return hCanvas->createIterator();
}

HBitmapIterator BasicCanvas::createBitmapReverseIterator() const
{
    return hCanvas->createReverseIterator();
}
