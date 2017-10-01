//
//  ICanvas.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/7/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef ICanvas_h
#define ICanvas_h

#include "Point.h"
#include "Color.hpp"
#include "IBitmapIterator.hpp"

namespace BitmapGraphics
{
    class ICanvas
    {
    public:
        virtual void setPixelColor (VG::Point const& location, Color const& color) = 0;
        virtual Color getPixelColor (VG::Point const& location) = 0;
        virtual int getWidth () const = 0;
        virtual int getHeight () const = 0;
        virtual HBitmapIterator createBitmapIterator () const = 0;
        virtual HBitmapIterator createBitmapReverseIterator () const = 0;
    };
    
    using HCanvas = std::shared_ptr<ICanvas>;
}

#endif /* ICanvas_h */
