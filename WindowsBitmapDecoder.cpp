//
//  WindowsBitmapDecoder.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/2/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "WindowsBitmapDecoder.hpp"
#include "WindowsBitmapHeader.hpp"

using namespace BitmapGraphics;
using HBitmapIterator = std::shared_ptr<IBitmapIterator>;
using HBitmapHeader = std::shared_ptr<WindowsBitmapHeader>;
using HBitmap = std::shared_ptr<Bitmap>;

WindowsBitmapDecoder::WindowsBitmapDecoder(HBitmap bitmap)
    : hBitmap(bitmap)
{
}

HBitmapDecoder WindowsBitmapDecoder::clone(std::istream& sourceStream)
{
    if(!isSupported(sourceStream))
    {
        throw std::runtime_error("File type unidentifiable in header");
    }
    
    // read from bitmap header
    HBitmapHeader hHeader = std::make_shared<WindowsBitmapHeader>();
    hHeader->readFileHeader(sourceStream);
    hHeader->readInfoHeader(sourceStream);
    
    // read from bitmap pixel data
    HBitmap hBitmap = std::make_shared<Bitmap>(hHeader->getBitmapWidth(),
                                               hHeader->getBitmapHeight(),
                                               sourceStream);
    
    // create decoder
    HBitmapDecoder hDecoder = std::make_shared<WindowsBitmapDecoder>(hBitmap);
    hDecoder->setMimeType("image/x-ms-bmp");
    
    return hDecoder;
}

bool WindowsBitmapDecoder::isSupported(std::istream& sourceStream) const
{
    int var1 = sourceStream.peek();
    sourceStream.seekg(1);
    int var2 = sourceStream.peek();
    
    // reset stream
    sourceStream.seekg(0, sourceStream.beg);
    
    /* ASCII codes 66 and 77 indicate "BM" which identifies
       binary as a WindowsBitmap */
    if (var1 == 66 && var2 == 77)
    {
        return true;
    }
    else {
        return false;
    }
}

HBitmapIterator WindowsBitmapDecoder::createIterator()
{
    if(!hBitmap)
    {
        throw std::runtime_error("User must specify bitmap to decode");
    }
    else {
        return hBitmap->createIterator();
    }
}
