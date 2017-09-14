//
//  SquareStroke.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/11/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "SquareStroke.hpp"
#include "SquarePen.hpp"

using namespace BitmapGraphics;

SquareStroke::SquareStroke(const int& size, const Color& color)
    : mySize(size), myColor(color)
{
}

void SquareStroke::setSize(const int& size)
{
    mySize = size;
}

int SquareStroke::getSize() const
{
    return mySize;
}

void SquareStroke::setColor(Color const& color)
{
    myColor = color;
}

Color SquareStroke::getColor() const
{
    return myColor;
}

HPen SquareStroke::createPen()
{    
    return std::make_shared<SquarePen>(*this);
}
