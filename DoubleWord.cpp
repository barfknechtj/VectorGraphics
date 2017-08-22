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

Binary::DoubleWord Binary::DoubleWord::readLittleEndian(std::istream& sourceStream)
{
    DoubleWord doubleWord;
    
    for (auto byte = 0; byte != sizeof(uint32_t); ++byte)
    {
        char c = 0;
        if(!sourceStream.get(c))
        {
            throw(std::runtime_error("Invalid stream size"));
        }
        
        // cast to temporary uint to avoid sign-extension
        uint32_t temp = static_cast<uint8_t>(c);
        doubleWord.myValue |= temp << (8 * byte);
    }
    
    return doubleWord;
}
Binary::DoubleWord Binary::DoubleWord::readBigEndian(std::istream& sourceStream)
{
    DoubleWord doubleWord;
    
    for (int byte = (sizeof(uint32_t) - 1); byte != -1; --byte)
    {
        char c = 0;
        if(!sourceStream.get(c))
        {
            throw(std::runtime_error("Error message"));
        }
        
        // cast to temporary uint to avoid sign-extension
        uint32_t temp = static_cast<uint8_t>(c);
        doubleWord.myValue |= temp << (8 * byte);
    }
    
    return doubleWord;
}

void Binary::DoubleWord::writeLittleEndian(std::ostream& destinationStream) const
{
#ifdef Little_Endian_
    
    writeNativeOrder(destinationStream);
    
#else
    
    writeSwappedOrder(destinationStream);
    
#endif
}

void Binary::DoubleWord::writeBigEndian(std::ostream& destinationStream) const
{
#ifdef Little_Endian_
    
    writeSwappedOrder(destinationStream);

#else
    
    writeNativeOrder(destinationStream);
    
#endif
}

void Binary::DoubleWord::writeNativeOrder(std::ostream& destinationStream) const
{
    Byte byte1 = myValue;
    Byte byte2 = myValue >> 8;
    Byte byte3 = myValue >> 16;
    Byte byte4 = myValue >> 24;
    byte1.write(destinationStream);
    byte2.write(destinationStream);
    byte3.write(destinationStream);
    byte4.write(destinationStream);
}
void Binary::DoubleWord::writeSwappedOrder(std::ostream& destinationStream) const
{
    Byte byte1 = myValue;
    Byte byte2 = myValue >> 8;
    Byte byte3 = myValue >> 16;
    Byte byte4 = myValue >> 24;
    byte4.write(destinationStream);
    byte3.write(destinationStream);
    byte2.write(destinationStream);
    byte1.write(destinationStream);
}
