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
    unsigned char byte = static_cast<unsigned char>(temp);
    
    return byte;
}

void Binary::Byte::write(std::ostream& os)
{
    os.put(static_cast<char>(myByteData));
}
