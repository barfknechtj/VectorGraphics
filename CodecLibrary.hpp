//
//  CodecLibrary.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/3/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef CodecLibrary_hpp
#define CodecLibrary_hpp

#include <stdio.h>
#include "Bitmap.hpp"
#include "WindowsBitmapHeader.hpp"
#include "WindowsBitmapDecoder.hpp"
#include "WindowsBitmapEncoder.hpp"
#include "IBitmapIterator.hpp"

namespace BitmapGraphics
{
    class CodecLibrary
    {
    public:
        
        CodecLibrary() = default;
        ~CodecLibrary() = default;

        // creates decoder based off file identification in stream
        HBitmapDecoder createDecoder(std::istream& bitmapStream);
        
        // creates decoder based off mimeType
        HBitmapDecoder createDecoder(const std::string& mimeType,
                                     std::istream& bitmapStream);
        
        HBitmapEncoder createEncoder(const std::string& mimeType,
                                     HBitmapIterator hBitmapIter);

        void registerDecoder(HBitmapDecoder hDecoder);
        void registerEncoder(HBitmapEncoder hEncoder);
        
    private:        
        std::list<HBitmapDecoder> myDecoders;
        std::list<HBitmapEncoder> myEncoders;
    };
    
    using HCodecLibrary = std::shared_ptr<CodecLibrary>;
}
#endif /* CodecLibrary_hpp */
