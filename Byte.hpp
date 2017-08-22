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
        Byte(uint8_t byte = 0) : myValue(byte) { };
        ~Byte() = default;
        
        static uint8_t read(std::istream& is);
        void write(std::ostream& os) const;
        
        operator uint8_t() const {return myValue;}
        
    private:
        uint8_t myValue;
    };
    
}

#endif /* Byte_hpp */
