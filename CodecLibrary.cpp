//
//  CodecLibrary.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/3/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "CodecLibrary.hpp"

using namespace BitmapGraphics;

void CodecLibrary::registerDecoder(HBitmapDecoder hDecoder)
{
    myDecoders.push_back(hDecoder);
}

void CodecLibrary::registerEncoder(HBitmapEncoder hEncoder)
{
    myEncoders.push_back(hEncoder);
}
