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
#include "WindowsBitmapDecoder.hpp"
#include "WindowsBitmapEncoder.hpp"

namespace BitmapGraphics
{
    class CodecLibrary
    {
    public:
        using HBitmapDecoder = std::shared_ptr<IBitmapDecoder>;
        using HBitmapEncoder = std::shared_ptr<IBitmapEncoder>;
        
        CodecLibrary() = default;
        ~CodecLibrary() = default;
        
        void registerDecoder(HBitmapDecoder hDecoder);
        void registerEncoder(HBitmapEncoder hEncoder);
        
    private:        
        std::list<HBitmapDecoder> myDecoders;
        std::list<HBitmapEncoder> myEncoders;
    };
}
#endif /* CodecLibrary_hpp */
