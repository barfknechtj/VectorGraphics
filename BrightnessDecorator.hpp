//
//  BrightnessDecorator.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/5/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef BrightnessDecorator_hpp
#define BrightnessDecorator_hpp

#include <stdio.h>
#include "BitmapIterator.hpp"
#include "ranged_number.hpp"
#include "Color.hpp"

namespace BitmapGraphics
{
    class BrightnessDecorator : public IBitmapIterator
    {
    public:
        BrightnessDecorator(HBitmapIterator& hBitmapIter,
                            const int& brightnessAdjust);
        virtual ~BrightnessDecorator() = default;
        
        virtual void nextScanLine();
        virtual bool isEndOfImage();
        
        virtual void nextPixel();
        virtual bool isEndOfScanLine();
        
        virtual Color getColor() const;
        virtual uint getBitmapWidth() const;
        virtual uint getBitmapHeight() const;
        
    private:
        int myBrightener;
        HBitmapIterator _myIter;
    };
    
    using AdjustedComponent = ranged_number<int, 0, 255>;
}

#endif /* BrightnessDecorator_hpp */
