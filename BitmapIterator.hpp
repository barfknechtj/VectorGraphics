//
//  BitmapIterator.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/31/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef BitmapIterator_hpp
#define BitmapIterator_hpp

#include <stdio.h>
#include <iterator>
#include "Color.hpp"
#include "Bitmap.hpp"
#include "DoubleWord.hpp"
#include "IBitmapIterator.hpp"

namespace BitmapGraphics
{
//    class IBitmapIterator : public std::iterator<std::forward_iterator_tag, Color>
//    {
//    public:
//        virtual ~IBitmapIterator() = default;
//        
//        virtual void nextScanLine() = 0;
//        virtual bool isEndOfImage() = 0;
//        
//        virtual void nextPixel() = 0;
//        virtual bool isEndOfScanLine() = 0;
//        
//        virtual Color getColor() const = 0;
//        virtual uint getBitmapWidth() const = 0;
//        virtual uint getBitmapHeight() const = 0;
//    };
    
    class BitmapIterator : public IBitmapIterator
    {
    public:
        BitmapIterator(Bitmap& bitmap);
        ~BitmapIterator() = default;
        
        void nextScanLine() override;
        bool isEndOfImage() override;
        
        void nextPixel() override;
        bool isEndOfScanLine() override;
        
        Color getColor() const override {return *_colorIter;}
        uint getBitmapWidth() const override {return myBitmap.getWidth();}
        uint getBitmapHeight() const override {return myBitmap.getHeight();}
        
    private:
        Bitmap& myBitmap;
        Bitmap::ScanLineIterator _scanLineIter;
        Bitmap::ColorIterator _colorIter;
    };
}

#endif /* BitmapIterator_hpp */
