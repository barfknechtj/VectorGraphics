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

namespace BitmapGraphics
{
    class IBitmapEncoder
    {
    public:
        using HBitmapEncoder = std::shared_ptr<IBitmapEncoder>;
        
        virtual ~IBitmapEncoder() = default;
        virtual HBitmapEncoder clone(HBitmapIterator& hBitmapIter) = 0;
        virtual void encodeToStream(std::ostream& destinationStream) = 0;
        virtual std::string getMimeType() const = 0;
    };
    
    class WindowsBitmapEncoder : public IBitmapEncoder
    {
    public:
        WindowsBitmapEncoder(HBitmapIterator bitmapIter = nullptr,
                             const std::string& mimeType = "image/x-ms-bmp");
        ~WindowsBitmapEncoder() = default;
        
        HBitmapEncoder clone(HBitmapIterator& hBitmapIter) override;
        void encodeToStream(std::ostream& destinationStream) override;
        std::string getMimeType() const override {return myMimeType;}
        
    private:
        std::string myMimeType;
        HBitmapIterator hBitmapIter;
        HBitmapHeader hBitmapHeader;
        
        void _encodeHeaderToStream(std::ostream& destinationStream);
        void _encodeBitmapToStream(std::ostream& destinationStream);
        uint _calcNumOfPads() const;
        uint _calcFileSize() const;
    };
}

#endif /* WindowsBitmapEncoder_hpp */
