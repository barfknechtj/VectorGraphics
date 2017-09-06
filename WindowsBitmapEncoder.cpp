//
//  WindowsBitmapEncoder.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/2/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "WindowsBitmapEncoder.hpp"

using namespace Binary;
using namespace BitmapGraphics;

const std::string WindowsBitmapEncoder::myMimeType{"image/x-ms-bmp"};

WindowsBitmapEncoder::WindowsBitmapEncoder(HBitmapIterator bitmapIter)
    : hBitmapIter(bitmapIter)
{
    // initialize header for encoder, ignored if creating prototype
    if(bitmapIter != nullptr)
    {
        // retrieve/calculate bitmap sizing from bitmapIterator
        const uint bitmapWidth{bitmapIter->getBitmapWidth()};
        const uint bitmapHeight{bitmapIter->getBitmapHeight()};
        const uint headersize{54};
        const uint fileSize{_calcFileSize()};
        const uint compressionSize{fileSize - headersize};
        
        // assumed header settings
        const uint horizontalPixelsPerMeter{2834};
        const uint verticalPixelsPerMeter{2834};
    
        hBitmapHeader = std::make_shared<WindowsBitmapHeader>(fileSize,
                                                              bitmapWidth,
                                                              bitmapHeight,
                                                              compressionSize,
                                                              horizontalPixelsPerMeter,
                                                              verticalPixelsPerMeter);
    }
}

HBitmapEncoder WindowsBitmapEncoder::clone(HBitmapIterator& hBitmapIter)
{
    return std::make_shared<WindowsBitmapEncoder>(hBitmapIter);
}

void WindowsBitmapEncoder::_encodeHeaderToStream(std::ostream& destinationStream)
{
    hBitmapHeader->write(destinationStream);
}

void WindowsBitmapEncoder::_encodeBitmapToStream(std::ostream& destinationStream)
{
    int numOfPadsOnLine = _calcNumOfPads();
    char pads[] = {0x0, 0x0, 0x0};
    
    while (!hBitmapIter->isEndOfImage())
    {
        while (!hBitmapIter->isEndOfScanLine())
        {
            hBitmapIter->getColor().write(destinationStream);
            hBitmapIter->nextPixel();
        }
        
        destinationStream.write(pads, numOfPadsOnLine);
        hBitmapIter->nextScanLine();
    }
}

void WindowsBitmapEncoder::encodeToStream(std::ostream& destinationStream)
{
    if(!hBitmapIter)
    {
        throw std::runtime_error("User must specify bitmap data to encode");
    } else {
        _encodeHeaderToStream(destinationStream);
        _encodeBitmapToStream(destinationStream);
    }   
}

uint WindowsBitmapEncoder::_calcNumOfPads() const
{
    /* 0x0 is inserted into bitmaps to make them 4-byte
     aligned. Caluclate number of pads used to construct
     bitmap  */
    
    uint bitmapWidth{hBitmapIter->getBitmapWidth()};
    uint colorComponents = 3;
    uint byteAlignment = 4;
    uint numOfPads = 0;
    
    if (auto remainder = bitmapWidth * colorComponents % byteAlignment)
    {
        numOfPads = byteAlignment - remainder;
    }
    
    return numOfPads;
}

uint WindowsBitmapEncoder::_calcFileSize() const
{
    // without color table
    uint headerSize{54}; // without color table
    
    // retrieve/calculate bitmap sizing from bitmapIterator
    uint bitmapWidth{hBitmapIter->getBitmapWidth()};
    uint bitmapHeight{hBitmapIter->getBitmapHeight()};
    uint pixelComponents{3};
    uint numOfPadsOnLine = _calcNumOfPads();
    uint bitmapSize{bitmapWidth * bitmapHeight *
        pixelComponents + (numOfPadsOnLine * bitmapHeight)};
    
    return headerSize + bitmapSize;
}
