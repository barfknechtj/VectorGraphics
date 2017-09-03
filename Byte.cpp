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
    return is.get();
}

void Binary::Byte::write(std::ostream& os) const
{    
    os.put(myValue);
}
