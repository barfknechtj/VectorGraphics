//
//  WindowsBitmapDecoder.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/2/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef WindowsBitmapDecoder_hpp
#define WindowsBitmapDecoder_hpp

#include <stdio.h>
#include <string>
#include <memory>
#include <fstream>
#include "WindowsBitmapHeader.hpp"
#include "Bitmap.hpp"
#include "IBitmapDecoder.hpp"


namespace BitmapGraphics
{    
    class WindowsBitmapDecoder : public IBitmapDecoder
    {
    public:
        WindowsBitmapDecoder();
        ~WindowsBitmapDecoder() = default;
        
        HBitmapDecoder clone(std::istream& sourceStream) override;
        HBitmapIterator createIterator() override;
        std::string getMimeType() const override {return myMimeType;};
        bool isSupported(std::istream& sourceStream) const override;
        
    private:
        static const std::string myMimeType;
        std::istream& myBitmapStream;
        HBitmap hBitmap;
        HBitmapHeader hBitmapHeader;
        
        WindowsBitmapDecoder(std::istream& sourceStream);
        void _decodeStream();
    };
}


#endif /* WindowsBitmapDecoder_hpp */
