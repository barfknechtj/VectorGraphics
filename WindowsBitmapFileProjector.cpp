//
//  WindowsBitmapFileProjector.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "WindowsBitmapFileProjector.hpp"

using namespace BitmapGraphics;

WindowsBitmapFileProjector::WindowsBitmapFileProjector(const std::string& filename,
                                                       CodecLibrary& codecLibrary)
: myFilename(filename), myCodecLibrary(codecLibrary)
{
}

void WindowsBitmapFileProjector::projectCanvas(HCanvas const& canvas)
{
    const std::string windowsMimeType = "image/x-ms-bmp";
    
    auto canvasIter{canvas->createBitmapReverseIterator()};
    auto encoder{myCodecLibrary.createEncoder(windowsMimeType, canvasIter)};
    
    std::ofstream outFile{myFilename, std::ios::binary};
    encoder->encodeToStream(outFile);
}
