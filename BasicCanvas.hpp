//
//  BasicCanvas.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/7/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef BasicCanvas_hpp
#define BasicCanvas_hpp

#include <stdio.h>
#include <vector>
#include "Point.h"
#include "Color.hpp"
#include "Bitmap.hpp"

namespace BitmapGraphics
{
    class BasicCanvas
    {
    private:
        HBitmap hCanvas;
        HBitmapIterator hCanvasIter;
        
    public:
        // TODO: add safety around writing and projecting canvas at
        // same time
        BasicCanvas(const int& width, const int& height,
                    const Color& background  = Color{0,0,0});
        
        virtual void setPixelColor (VG::Point const& location,
                                    Color const& color);
        virtual Color getPixelColor (VG::Point const& location) const;
        virtual int getWidth() const;
        virtual int getHeight() const;
        virtual HBitmapIterator createBitmapIterator() const;
        
    };
}

#endif /* BasicCanvas_hpp */
