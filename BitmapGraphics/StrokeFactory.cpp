//
//  StrokeFactory.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "StrokeFactory.hpp"
#include "SquareStroke.hpp"
#include "SlashStroke.hpp"

using namespace BitmapGraphics;

HStroke StrokeFactory::createStroke(const std::string& strokeTip,
                                    const int& size,
                                    const Color& color)
{
    if(strokeTip == "square")
    {
        return HStroke{new SquareStroke(size, color)};
    }
    else if (strokeTip == "slash")
    {
        return HStroke{new SlashStroke(size, color)};
    }
    
    throw std::runtime_error("Invalid stroke type specified");
}
