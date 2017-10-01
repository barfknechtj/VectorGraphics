//
//  DoubleWord.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/11/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef DoubleWord_hpp
#define DoubleWord_hpp

#include <stdio.h>
#include <iostream>

namespace Binary
{
    class DoubleWord
    {
    public:
        DoubleWord(uint32_t value = 0) : myValue (value) { };
        ~DoubleWord() = default;
        
        static DoubleWord readLittleEndian(std::istream& sourceStream);
        static DoubleWord readBigEndian(std::istream& sourceStream);
        
        void writeLittleEndian(std::ostream& destinationStream) const;
        void writeBigEndian(std::ostream& destinationStream) const;
        
        operator uint32_t () const {return myValue;}
        
    private:
        uint32_t myValue;
        
        void writeNativeOrder(std::ostream& destinationStream) const;
        void writeSwappedOrder(std::ostream& destinationStream) const;
    };
}

#endif /* DoubleWord_hpp */
