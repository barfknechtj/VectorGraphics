//
//  SlashStroke.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "SlashStroke.hpp"
#include "SlashPen.hpp"

using namespace BitmapGraphics;

SlashStroke::SlashStroke(const int& size, const Color& color)
: mySize(size), myColor(color)
{
}

void SlashStroke::setSize(const int& size)
{
    mySize = size;
}

int SlashStroke::getSize() const
{
    return mySize;
}

void SlashStroke::setColor(Color const& color)
{
    myColor = color;
}

Color SlashStroke::getColor() const
{
    return myColor;
}

HPen SlashStroke::createPen()
{
    return std::make_shared<SlashPen>(*this);
}
