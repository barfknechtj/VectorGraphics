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

Binary::Word& Binary::Word::operator=(unsigned short value)
{
    this->myValue = value;
    return *this;
}

Binary::Word Binary::Word::readLittleEndian(std::istream& sourceStream)
{
    auto byte1 = Binary::Byte::read(sourceStream);
    auto byte2 = Binary::Byte::read(sourceStream);
    Binary::Word word;
    
    // shift byte2 to be more significant
    word.myValue |= byte2 << 8;
    word.myValue |= byte1;

    return word;
}

Binary::Word Binary::Word::readBigEndian(std::istream& sourceStream)
{
    auto byte1 = Binary::Byte::read(sourceStream);
    auto byte2 = Binary::Byte::read(sourceStream);
    Binary::Word word;
    
    // shift byte1 to be more significant
    word.myValue |= byte1 << 8;
    word.myValue |= byte2;
    
    return word;
}

void Binary::Word::writeLittleEndian(std::ostream& destinationStream) const
{
#ifdef Little_Endian_
    //    TODO: write generic function that writes in native order
    //    writeNativeOrder(destinationStream);
    Byte byte1 = myValue;
    Byte byte2 = myValue >> 8;
    byte1.write(destinationStream);
    byte2.write(destinationStream);
    
//    std::copy(&myValue, &myValue + sizeof(unsigned short), std::ostream_iterator<unsigned char>(destinationStream));
    
#else
//    TODO: write generic function that writes in swapped order
//    writeSwappedOrder(destinationStream);
    Byte byte1 = myValue;
    Byte byte2 = myValue >> 8;
    byte2.write(destinationStream);
    byte1.write(destinationStream);
#endif
}


void Binary::Word::writeBigEndian(std::ostream& destinationStream) const
{
#ifdef Little_Endian_
    //    TODO: write generic function that writes in swapped order
    //    writeSwappedOrder(destinationStream);
    Byte byte1 = myValue;
    Byte byte2 = myValue >> 8;
    byte2.write(destinationStream);
    byte1.write(destinationStream);
 
#else
//    TODO: write generic function that writes in native order
//    writeNativeOrder(destinationStream);
    Byte byte1 = myValue;
    Byte byte2 = myValue >> 8;
    byte1.write(destinationStream);
    byte2.write(destinationStream);
    
#endif
}

