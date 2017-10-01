//
//  BitmapReverseIterator.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef BitmapReverseIterator_hpp
#define BitmapReverseIterator_hpp

#include <stdio.h>
#include <iterator>
#include "Color.hpp"
#include "Bitmap.hpp"
#include "DoubleWord.hpp"
#include "IBitmapIterator.hpp"

namespace BitmapGraphics
{
    class BitmapReverseIterator : public IBitmapIterator
    {
    public:
        BitmapReverseIterator(Bitmap& bitmap);
        ~BitmapReverseIterator() = default;
        
        void nextScanLine() override;
        bool isEndOfImage() override;
        
        void nextPixel() override;
        bool isEndOfScanLine() override;
        
        void begin() override;
        void end() override;
        
        void setColor(Color const& color) override {*_colorIter = color;}
        Color getColor() const override {return *_colorIter;}
        uint getBitmapWidth() const override {return myBitmap.getWidth();}
        uint getBitmapHeight() const override {return myBitmap.getHeight();}
        
    private:
        Bitmap& myBitmap;
        Bitmap::ScanLineRevIterator _scanLineIter;
        Bitmap::ColorIterator _colorIter;
    };
}

#endif /* BitmapReverseIterator_hpp */
