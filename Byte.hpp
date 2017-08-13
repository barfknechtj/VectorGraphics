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
        Byte() = default;
        ~Byte() = default;
        
        template<typename T>
        Byte(const std::initializer_list<T> data)
        {
            myByteData = static_cast<unsigned char>(*data.begin());
        }
        
        static unsigned char read(std::istream& is);
        void write(std::ostream& os);
        
        void operator=(unsigned char& c) {myByteData = c;}
        operator unsigned char() const {return myByteData;}
        
    private:
        unsigned char myByteData;
    };
    
}

#endif /* Byte_hpp */
