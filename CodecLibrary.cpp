//
//  CodecLibrary.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/3/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "CodecLibrary.hpp"

using namespace BitmapGraphics;

// creates decoder based off file identification in stream
HBitmapDecoder CodecLibrary::createDecoder(std::istream& bitmapStream)
{
    for(const auto& decoder : myDecoders)
    {
        if(decoder->isSupported(bitmapStream))
        {
           return decoder->clone(bitmapStream);
        }
    }
    
    throw std::runtime_error("Decoder for provided file not supported");
}

// creates decoder based off mimeType
HBitmapDecoder CodecLibrary::createDecoder(std::istream& bitmapStream,
                                           const std::string& mimeType)
{
    for(const auto& decoder : myDecoders)
    {
        if(decoder->getMimeType() == mimeType)
        {
            return decoder->clone(bitmapStream);
        }
    }

    throw std::runtime_error("Decoder for provided MimeType not supported");
}

// creates encoder based off mimeType
HBitmapEncoder CodecLibrary::createEncoder(const std::string& mimeType,
                                           HBitmapIterator hBitmapIter)
{
    for(const auto& encoder : myEncoders)
    {
        if(encoder->getMimeType() == mimeType)
        {
            return encoder->clone(hBitmapIter);
        }
    }
    
    throw std::runtime_error("Encoder for provided MimeType not supported");
}

void CodecLibrary::registerDecoder(HBitmapDecoder hDecoder)
{
    myDecoders.push_back(hDecoder);
}

void CodecLibrary::registerEncoder(HBitmapEncoder hEncoder)
{
    myEncoders.push_back(hEncoder);
}
