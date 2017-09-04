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
        using HBitmapIterator = std::shared_ptr<IBitmapIterator>;
        
        virtual ~IBitmapEncoder() = default;
        virtual HBitmapEncoder clone(HBitmapIterator& hBitmapIter) = 0;
        virtual void encodeToStream(std::ofstream& destinationStream) = 0;
        virtual std::string getMimeType() const = 0;
    };
    
    class WindowsBitmapEncoder : public IBitmapEncoder
    {
    private:
        using HBitmapHeader = std::shared_ptr<WindowsBitmapHeader>;
        using HBitmap = std::shared_ptr<Bitmap>;
        
    public:
        WindowsBitmapEncoder(HBitmapIterator bitmapIter = nullptr,
                             std::string mimeType = "image/x-ms-bmp");
        ~WindowsBitmapEncoder() = default;
        
        HBitmapEncoder clone(HBitmapIterator& hBitmapIter) override;
        void encodeToStream(std::ofstream& destinationStream) override;
        std::string getMimeType() const override {return myMimeType;}
        
    private:
        std::string myMimeType;
        HBitmapIterator hBitmapIter;
        HBitmapHeader hBitmapHeader;
        
        void _encodeHeaderToStream(std::ofstream& destinationStream);
        void _encodeBitmapToStream(std::ofstream& destinationStream);
        uint _calcNumOfPads() const;
        uint _calcFileSize();
    };
}

#endif /* WindowsBitmapEncoder_hpp */
