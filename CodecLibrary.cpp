//
//  CodecLibrary.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/3/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "CodecLibrary.hpp"

using namespace BitmapGraphics;
using HBitmapEncoder = std::shared_ptr<IBitmapEncoder>;
using HBitmapIterator = std::shared_ptr<IBitmapIterator>;

HBitmapDecoder CodecLibrary::createDecoder(std::istream& bitmapStream,
                                           const std::string& mimeType)
{
    // other decoders can be created from here based off their MimeType
    if(mimeType == "image/x-ms-bmp")
    {
        if(bitmapStream.rdbuf()->in_avail())
        {
            WindowsBitmapHeader header(bitmapStream);
            HBitmap hBitmap = std::make_shared<Bitmap>(header.getBitmapWidth(),
                                                       header.getBitmapHeight(),
                                                       bitmapStream);
            return std::make_shared<WindowsBitmapDecoder>(hBitmap);
        } else {
            HBitmap hBitmap = std::make_shared<Bitmap>();
            return std::make_shared<WindowsBitmapDecoder>(hBitmap);
        }
    }
    // auto lookup from registered decoders
    else if(mimeType == "") {
        
        for(auto decoderIter = myDecoders.begin(); decoderIter != myDecoders.end(); ++decoderIter)
        {
            WindowsBitmapDecoder* decoder = dynamic_cast<WindowsBitmapDecoder*>(decoderIter->get());
            if(decoder->isSupported(bitmapStream))
            {
                return decoder->clone(bitmapStream);
            }
        }
    }
    
    // unsupported
    throw std::runtime_error("Decoder for provided MimeType and/or file not supported");
}

HBitmapEncoder CodecLibrary::createEncoder(const std::string& mimeType,
                                           HBitmapIterator hIter)
{
    // other encoders can be created from here based off their MimeType
    if(mimeType == "image/x-ms-bmp")
    {
        return std::make_shared<WindowsBitmapEncoder>(hIter, mimeType);
    }
    else{
        throw std::runtime_error("Encoder for provided MimeType not supported");
    }
}

void CodecLibrary::registerDecoder(HBitmapDecoder hDecoder)
{
    myDecoders.push_back(hDecoder);
}

void CodecLibrary::registerEncoder(HBitmapEncoder hEncoder)
{
    myEncoders.push_back(hEncoder);
}
