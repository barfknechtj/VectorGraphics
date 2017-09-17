//
//  Color.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/15/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "Color.hpp"

BitmapGraphics::Color::Color(const std::string& hexColorValue)
{
    if(hexColorValue.length() != 6)
    {
        throw std::runtime_error("Invalid hex value given for color");
    }

    red = std::stoi(hexColorValue.substr(0, 2), 0, 16);
    green = std::stoi(hexColorValue.substr(2, 2), 0, 16);
    blue = std::stoi(hexColorValue.substr(4, 2), 0, 16);
}

BitmapGraphics::Color BitmapGraphics::Color::read(std::istream& is)
{
    BitmapGraphics::Color color;
    color.blue = Binary::Byte::read(is);
    color.green = Binary::Byte::read(is);
    color.red = Binary::Byte::read(is);
    
    return color;
}

void BitmapGraphics::Color::write(std::ostream& os)
{
    blue.write(os);
    green.write(os);
    red.write(os);
}

bool BitmapGraphics::operator==(const Color& lhs, const Color& rhs)
{
    return lhs.getBlue() == rhs.getBlue()   &&
           lhs.getGreen() == rhs.getGreen() &&
           lhs.getRed() == rhs.getRed();
}
