//
//  DoubleWord.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/11/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "DoubleWord.hpp"
#include "Byte.hpp"
#include "Endianness.h"

Binary::DoubleWord& Binary::DoubleWord::operator=(DoubleWord const& original)
{
    this->myValue = original.myValue;
    return *this;
}

Binary::DoubleWord& Binary::DoubleWord::operator=(unsigned long value)
{
    this->myValue = value;
    return *this;
}

Binary::DoubleWord Binary::DoubleWord::readLittleEndian(std::istream& sourceStream)
{
    DoubleWord doubleWord;

    for (auto byte = 0; byte != sizeof(unsigned int); ++byte)
    {
        char c = 0;
        if(!sourceStream.get(c))
        {
            throw(std::runtime_error("Invalid stream size"));
        }
        
        // cast to temporary uint to avoid sign-extension
        unsigned int temp = static_cast<unsigned char>(c);
        doubleWord.myValue |= temp << (8 * byte);
    }
    
    return doubleWord;
}
Binary::DoubleWord Binary::DoubleWord::readBigEndian(std::istream& sourceStream)
{
    DoubleWord doubleWord;
    
    for (int byte = static_cast<int>(sizeof(unsigned int) - 1); byte != -1; --byte)
    {
        char c = 0;
        if(!sourceStream.get(c))
        {
            throw(std::runtime_error("Error message"));
        }
        
        // cast to temporary uint to avoid sign-extension
        unsigned int temp = static_cast<unsigned char>(c);
        doubleWord.myValue |= temp << (8 * byte);
    }
    
    return doubleWord;
}

void Binary::DoubleWord::writeLittleEndian(std::ostream& destinationStream) const
{
#ifdef Little_Endian_
    
    Byte byte1 = myValue;
    Byte byte2 = myValue >> 8;
    Byte byte3 = myValue >> 16;
    Byte byte4 = myValue >> 24;
    byte1.write(destinationStream);
    byte2.write(destinationStream);
    byte3.write(destinationStream);
    byte4.write(destinationStream);
    
#else
    
    Byte byte1 = myValue;
    Byte byte2 = myValue >> 8;
    Byte byte3 = myValue >> 16;
    Byte byte4 = myValue >> 24;
    byte4.write(destinationStream);
    byte3.write(destinationStream);
    byte2.write(destinationStream);
    byte1.write(destinationStream);
    
#endif
}

void Binary::DoubleWord::writeBigEndian(std::ostream& destinationStream) const
{
#ifdef Little_Endian_
    
    Byte byte1 = myValue;
    Byte byte2 = myValue >> 8;
    Byte byte3 = myValue >> 16;
    Byte byte4 = myValue >> 24;
    byte4.write(destinationStream);
    byte3.write(destinationStream);
    byte2.write(destinationStream);
    byte1.write(destinationStream);

#else
    
    Byte byte1 = myValue;
    Byte byte2 = myValue >> 8;
    Byte byte3 = myValue >> 16;
    Byte byte4 = myValue >> 24;
    byte1.write(destinationStream);
    byte2.write(destinationStream);
    byte3.write(destinationStream);
    byte4.write(destinationStream);
    
#endif
}
