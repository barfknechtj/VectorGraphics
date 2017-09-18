//
//  SlashPen.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef SlashPen_hpp
#define SlashPen_hpp

#include <stdio.h>
#include "SlashStroke.hpp"
#include "Point.h"

namespace BitmapGraphics
{
    class SlashPen : public IPen
    {
    public:
        SlashPen(const SlashStroke& stroke);
        ~SlashPen() = default;
        
        SlashPen(const SlashPen& src) = default;
        SlashPen& operator=(const SlashPen& src) = default;
        SlashPen(SlashPen&& src) = default;
        SlashPen& operator=(SlashPen&& src) = default;
        
        void drawPoint(const HCanvas& canvas,
                       const VG::Point& point);
        
    private:
        SlashStroke myStroke;
    };
}

#endif /* SlashPen_hpp */
