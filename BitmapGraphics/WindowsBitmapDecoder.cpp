//
//  WindowsBitmapDecoder.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/2/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <sstream>
#include "WindowsBitmapDecoder.hpp"
#include "WindowsBitmapHeader.hpp"

using namespace BitmapGraphics;

const std::string WindowsBitmapDecoder::myMimeType{"image/x-ms-bmp"};

WindowsBitmapDecoder::WindowsBitmapDecoder()
    : myBitmapStream(std::cin)
{
    myBitmapStream.setstate(std::ios::badbit);
}

WindowsBitmapDecoder::WindowsBitmapDecoder(std::istream& sourceStream)
    : myBitmapStream(sourceStream)
{
}

HBitmapDecoder WindowsBitmapDecoder::clone(std::istream& sourceStream)
{
    return HBitmapDecoder{new WindowsBitmapDecoder(sourceStream)};
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
    bool isSupported = (var1 == 66 && var2 == 77) ? true : false;
    
    return isSupported;
}

HBitmapIterator WindowsBitmapDecoder::createIterator()
{
    if(myBitmapStream.bad())
    {
        throw std::runtime_error("User must specify bitmap to decode");
    }
    else {
        _decodeStream();
        return hBitmap->createIterator();
    }
}

void WindowsBitmapDecoder::_decodeStream()
{
    hBitmapHeader = std::make_shared<WindowsBitmapHeader>(myBitmapStream);
    hBitmap = std::make_shared<Bitmap>(hBitmapHeader->getBitmapWidth(),
                                       hBitmapHeader->getBitmapHeight(),
                                       myBitmapStream);
}


