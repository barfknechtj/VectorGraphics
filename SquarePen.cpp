//
//  SquarePen.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/11/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "SquarePen.hpp"

using namespace BitmapGraphics;

SquarePen::SquarePen(const SquareStroke& stroke)
    : myStroke(stroke)
{
}

void SquarePen::drawPoint(const HCanvas& canvas,
                          const VG::Point& point)
{
    canvas->setPixelColor(point, myStroke.getColor());
}
