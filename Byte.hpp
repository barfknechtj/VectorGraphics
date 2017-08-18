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
        Byte(unsigned char byte = 0) : myValue(byte) { };
        ~Byte() = default;
        
        template<typename T>
        Byte(const std::initializer_list<T> data)
        {
            myValue = static_cast<unsigned char>(*data.begin());
        }
        
        static unsigned char read(std::istream& is);
        void write(std::ostream& os) const;
        
        void operator=(unsigned char& c) {myValue = c;}
        operator unsigned char() const {return myValue;}
        
    private:
        unsigned char myValue;
    };
    
}

#endif /* Byte_hpp */
