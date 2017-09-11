//
//  BasicCanvas.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/7/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "BasicCanvas.hpp"
#include <fstream>
#include <stack>

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
}

Color BasicCanvas::getPixelColor(VG::Point const& location) const
{
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
        
    return hCanvasIter->getColor();
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
