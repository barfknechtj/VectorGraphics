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
            Word(uint16_t value = 0) : myValue (value) { };
            ~Word() = default;
                
            static Word readLittleEndian(std::istream& sourceStream);
            static Word readBigEndian(std::istream& sourceStream);
            void writeLittleEndian(std::ostream& destinationStream) const;
            void writeBigEndian(std::ostream& destinationStream) const;

            operator uint16_t () const {return myValue;}
        
        private:
            uint16_t myValue;
    };
}

#endif /* Word_hpp */
