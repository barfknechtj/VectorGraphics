//
//  SlashPen.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "SlashPen.hpp"
#include "Point.h"

using namespace BitmapGraphics;

SlashPen::SlashPen(const SlashStroke& stroke)
: myStroke(stroke)
{
}

/* draws a slash with the diagonal having a number
   of pixels equal to myStroke's size. The stroke is
   anchored at the top right of the slash at
   the point arg */
void SlashPen::drawPoint(const HCanvas& canvas,
                         const VG::Point& point)
{
    int x0 = point.getX();
    int y0 = point.getY();
    
    int pointIndex = 0;
    
    while(pointIndex != myStroke.getSize())
    {
        int x = x0 - pointIndex;
        int y = y0 + pointIndex;
        
        // verify point is on canvas before drawing
        if(0 <= x &&
           x < canvas->getWidth() &&
           0 <= y &&
           y < canvas->getHeight())
        {
            canvas->setPixelColor(VG::Point(x, y),
                                  myStroke.getColor());
        }
        
        ++pointIndex;
    }
}
