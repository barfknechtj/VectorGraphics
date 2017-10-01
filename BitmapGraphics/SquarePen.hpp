//
//  SquarePen.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/11/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef SquarePen_hpp
#define SquarePen_hpp

#include <stdio.h>
#include "SquareStroke.hpp"
#include "Point.h"

namespace BitmapGraphics
{
    class SquarePen : public IPen
    {
    public:
        SquarePen(const SquareStroke& stroke);
        ~SquarePen() = default;
        
        SquarePen(const SquarePen& src) = default;
        SquarePen& operator=(const SquarePen& src) = default;
        SquarePen(SquarePen&& src) = default;
        SquarePen& operator=(SquarePen&& src) = default;
        
        void drawPoint(const HCanvas& canvas,
                       const VG::Point& point);
        
    private:
        SquareStroke myStroke;
    };
}

#endif /* SquarePen_hpp */
