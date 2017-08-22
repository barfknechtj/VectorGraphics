//
//  Byte.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/11/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "Byte.hpp"

uint8_t Binary::Byte::read(std::istream& is)
{
    char temp;
    is.get(temp);
    uint8_t byte = static_cast<uint8_t>(temp);
    
    return byte;
}

void Binary::Byte::write(std::ostream& os) const
{    
    std::copy(&myValue, &myValue + sizeof(uint8_t), std::ostream_iterator<uint8_t>(os));
}
