//
//  Word.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/11/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef Word_hpp
#define Word_hpp

#include <stdio.h>
#include <iostream>
#include "Byte.hpp"
#include "Endianness.h"

namespace Binary
{
    class Word
    {
        public:
            Word(unsigned short value = 0) : myValue (value) { };
            ~Word() = default;
        
            template<typename T>
            Word(const std::initializer_list<T> data)
            {
                myValue = static_cast<unsigned short>(*data.begin());
            }
        
            Word& operator=(Word const& original);
            Word& operator=(unsigned short value);
        
            static Word readLittleEndian(std::istream& sourceStream);
            static Word readBigEndian(std::istream& sourceStream);
            void writeLittleEndian(std::ostream& destinationStream) const;
            void writeBigEndian(std::ostream& destinationStream) const;

            operator unsigned short () const {return myValue;}
        
        private:
            unsigned short myValue;
    };
}

#endif /* Word_hpp */
