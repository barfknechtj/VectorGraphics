//
//  Byte.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/11/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "Byte.hpp"

unsigned char Binary::Byte::read(std::istream& is)
{
    char temp;
    is.get(temp);
    unsigned char byteData = static_cast<unsigned char>(temp);
    
    return byteData;
}
