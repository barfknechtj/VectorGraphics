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
        
        template<typename T>
        DoubleWord(const std::initializer_list<T> data)
        {
            myValue = static_cast<uint32_t>(*data.begin());
        }
        
        DoubleWord& operator=(DoubleWord const& original);
        DoubleWord& operator=(uint32_t value);
        
        static DoubleWord readLittleEndian(std::istream& sourceStream);
        static DoubleWord readBigEndian(std::istream& sourceStream);
        void writeLittleEndian(std::ostream& destinationStream) const;
        void writeBigEndian(std::ostream& destinationStream) const;
        
        operator uint32_t () const {return myValue;}
        
    private:
        uint32_t myValue;
    };
}

#endif /* DoubleWord_hpp */
