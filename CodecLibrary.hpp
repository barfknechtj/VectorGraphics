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
#include "BitmapIterator.hpp"

namespace BitmapGraphics
{
    class CodecLibrary
    {
    public:
        using HBitmapDecoder = std::shared_ptr<IBitmapDecoder>;
        using HBitmapEncoder = std::shared_ptr<IBitmapEncoder>;
        using HBitmapIterator = std::shared_ptr<IBitmapIterator>;
        
        CodecLibrary() = default;
        ~CodecLibrary() = default;

        HBitmapDecoder createDecoder(std::istream& bitmapStream = std::cin,
                                     const std::string& mimeType = "");
        HBitmapEncoder createEncoder(const std::string& mimeType,
                                     HBitmapIterator hIter);

        void registerDecoder(HBitmapDecoder hDecoder);
        void registerEncoder(HBitmapEncoder hEncoder);
        
    private:        
        std::list<HBitmapDecoder> myDecoders;
        std::list<HBitmapEncoder> myEncoders;
    };
}
#endif /* CodecLibrary_hpp */
