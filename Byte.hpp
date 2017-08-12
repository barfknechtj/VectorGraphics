//
//  Byte.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/11/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef Byte_hpp
#define Byte_hpp

#include <stdio.h>
#include <iostream>

namespace Binary
{
    class Byte
    {
    public:
        
        static unsigned char read(std::istream& is);
    };
}

#endif /* Byte_hpp */
