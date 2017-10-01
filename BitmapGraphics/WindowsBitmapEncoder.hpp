//
//  WindowsBitmapEncoder.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/2/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef WindowsBitmapEncoder_hpp
#define WindowsBitmapEncoder_hpp

#include <stdio.h>
#include <memory>
#include <fstream>
#include "BitmapIterator.hpp"
#include "WindowsBitmapHeader.hpp"
#include "Bitmap.hpp"
#include "IBitmapEncoder.hpp"

namespace BitmapGraphics
{    
    class WindowsBitmapEncoder : public IBitmapEncoder
    {
    public:
        WindowsBitmapEncoder();
        ~WindowsBitmapEncoder() = default;
        
        HBitmapEncoder clone(HBitmapIterator& hBitmapIter) override;
        void encodeToStream(std::ostream& destinationStream) override;
        std::string getMimeType() const override {return myMimeType;}
        
    private:
        static const std::string myMimeType;
        HBitmapIterator hBitmapIter;
        HBitmapHeader hBitmapHeader;
        
        WindowsBitmapEncoder(HBitmapIterator bitmapIter);
        void _encodeHeaderToStream(std::ostream& destinationStream);
        void _encodeBitmapToStream(std::ostream& destinationStream);
        uint _calcNumOfPads() const;
        uint _calcFileSize() const;
    };
}

#endif /* WindowsBitmapEncoder_hpp */
