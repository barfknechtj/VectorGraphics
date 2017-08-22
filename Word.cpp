//
//  Word.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/11/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "Word.hpp"

Binary::Word& Binary::Word::operator=(Word const& original)
{
    this->myValue = original.myValue;
    return *this;
}

Binary::Word& Binary::Word::operator=(uint16_t value)
{
    this->myValue = value;
    return *this;
}

Binary::Word Binary::Word::readLittleEndian(std::istream& sourceStream)
{
    auto byte1 = Binary::Byte::read(sourceStream);
    auto byte2 = Binary::Byte::read(sourceStream);
    Binary::Word word;
    
    word.myValue |= byte2 << 8;
    word.myValue |= byte1;

    return word;
}

Binary::Word Binary::Word::readBigEndian(std::istream& sourceStream)
{
    auto byte1 = Binary::Byte::read(sourceStream);
    auto byte2 = Binary::Byte::read(sourceStream);
    Binary::Word word;
    
    word.myValue |= byte1 << 8;
    word.myValue |= byte2;
    
    return word;
}

void Binary::Word::writeLittleEndian(std::ostream& destinationStream) const
{
#ifdef Little_Endian_

    Byte byte1 = myValue;
    Byte byte2 = myValue >> 8;
    byte1.write(destinationStream);
    byte2.write(destinationStream);
    
#else
    
    Byte byte1 = myValue;
    Byte byte2 = myValue >> 8;
    byte2.write(destinationStream);
    byte1.write(destinationStream);

#endif
}


void Binary::Word::writeBigEndian(std::ostream& destinationStream) const
{
#ifdef Little_Endian_
    
    Byte byte1 = myValue;
    Byte byte2 = myValue >> 8;
    byte2.write(destinationStream);
    byte1.write(destinationStream);
 
#else
    
    Byte byte1 = myValue;
    Byte byte2 = myValue >> 8;
    byte1.write(destinationStream);
    byte2.write(destinationStream);
    
#endif
}

