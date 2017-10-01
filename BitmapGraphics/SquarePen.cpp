//
//  SquarePen.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/11/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "SquarePen.hpp"
#include "Point.h"

using namespace BitmapGraphics;

SquarePen::SquarePen(const SquareStroke& stroke)
    : myStroke(stroke)
{
}

/* draws a square with each side the size of the
   stroke with the top left anchored at the point
   arg */
void SquarePen::drawPoint(const HCanvas& canvas,
                          const VG::Point& point)
{
    int x0 = point.getX();
    int y0 = point.getY();
    
    int rowIndex = 0;
    
    while(rowIndex != myStroke.getSize())
    {
        
        int columnIndex = 0;
        
        while(columnIndex != myStroke.getSize())
        {
            
            int x = x0 + columnIndex;
            int y = y0 + rowIndex;
            
            // verify point is on canvas before drawing
            if(0 <= x &&
               x < canvas->getWidth() &&
               0 <= y &&
               y < canvas->getHeight())
            {
                canvas->setPixelColor(VG::Point(x, y),
                                      myStroke.getColor());
            }

            ++columnIndex;
        }
        
        ++rowIndex;
    }
}
