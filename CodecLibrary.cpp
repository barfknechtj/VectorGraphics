//
//  CodecLibrary.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/3/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "CodecLibrary.hpp"

using namespace BitmapGraphics;
using HBitmap = std::shared_ptr<Bitmap>;
using HBitmapDecoder = std::shared_ptr<IBitmapDecoder>;
using HBitmapEncoder = std::shared_ptr<IBitmapEncoder>;
using HBitmapIterator = std::shared_ptr<IBitmapIterator>;

HBitmapDecoder CodecLibrary::createDecoder(const std::string& mimeType,
                                           std::istream& bitmapStream)
{
    // other decoders can be created from here based off their MimeType
    if(mimeType == "image/x-ms-bmp")
    {
        WindowsBitmapHeader header(bitmapStream);
        HBitmap hBitmap = std::make_shared<Bitmap>(header.getBitmapWidth(),
                                                   header.getBitmapHeight(),
                                                   bitmapStream);
    
        return std::make_shared<WindowsBitmapDecoder>(hBitmap);
    }
    // auto lookup from registered decoders
    else if(mimeType == "") {
        
        WindowsBitmapDecoder* decoder = dynamic_cast<WindowsBitmapDecoder*>(myDecoders.begin()->get());
        
        return decoder->clone(bitmapStream);
        
    } else {
        throw std::runtime_error("Decoder for provided MimeType and/or file not supported");
    }
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
