//
//  IBitmapIterator.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/4/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef IBitmapIterator_hpp
#define IBitmapIterator_hpp

#include <stdio.h>

namespace BitmapGraphics
{
    class IBitmapIterator : public std::iterator<std::forward_iterator_tag, Color>
    {
    public:
        virtual ~IBitmapIterator() = default;
        
        virtual void nextScanLine() = 0;
        virtual bool isEndOfImage() = 0;
        
        virtual void nextPixel() = 0;
        virtual bool isEndOfScanLine() = 0;
        
        virtual Color getColor() const = 0;
        virtual uint getBitmapWidth() const = 0;
        virtual uint getBitmapHeight() const = 0;
    };
    
    using HBitmapIterator = std::shared_ptr<IBitmapIterator>;
}

#endif /* IBitmapIterator_hpp */
