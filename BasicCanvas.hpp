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
#include <mutex>
#include "Point.h"
#include "Color.hpp"
#include "Bitmap.hpp"
#include "ICanvas.hpp"

namespace BitmapGraphics
{
    class BasicCanvas : public ICanvas
    {
    private:
        HBitmap hCanvas;
        HBitmapIterator hCanvasIter;
        
        std::mutex myMutex;
        
    public:
        BasicCanvas(const int& width, const int& height,
                    const Color& background  = Color{0,0,0});
        
        virtual void setPixelColor (VG::Point const& location,
                                    Color const& color);
        virtual Color getPixelColor (VG::Point const& location);
        virtual int getWidth() const;
        virtual int getHeight() const;
        virtual HBitmapIterator createBitmapIterator() const;
        virtual HBitmapIterator createBitmapReverseIterator () const;
    };
}

#endif /* BasicCanvas_hpp */
