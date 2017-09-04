//
//  WindowsBitmapHeader.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "WindowsBitmapHeader.hpp"

using Binary::Byte;
using Binary::Word;
using Binary::DoubleWord;
using BitmapGraphics::WindowsBitmapHeader;

//-----file header-----
const DoubleWord WindowsBitmapHeader::fileHeaderBytes{10};
const Byte WindowsBitmapHeader::firstIdentifier{'B'};
const Byte WindowsBitmapHeader::secondIdentifier{'M'};
const DoubleWord WindowsBitmapHeader::reserved{0};

// without Color Table, offset is 54
const DoubleWord WindowsBitmapHeader::rawImageByteOffset{54};

//-----info header-----
const DoubleWord WindowsBitmapHeader::infoHeaderBytes{40};
const Word WindowsBitmapHeader::numberOfPlanes{1};
const Word WindowsBitmapHeader::bitsPerPixel{24};
const DoubleWord WindowsBitmapHeader::compressionType{0};
const DoubleWord WindowsBitmapHeader::numberOfColors{0};
const DoubleWord WindowsBitmapHeader::numberOfImportantColors{0};

WindowsBitmapHeader::WindowsBitmapHeader(std::istream& sourceStream)
{
    readFileHeader(sourceStream);
    readInfoHeader(sourceStream);
}

WindowsBitmapHeader::WindowsBitmapHeader(Binary::DoubleWord fSize,
                                         Binary::DoubleWord bWidth,
                                         Binary::DoubleWord bHeight,
                                         Binary::DoubleWord compSize,
                                         Binary::DoubleWord hPixelsPerMeter,
                                         Binary::DoubleWord vPixelsPerMeter)
    : fileSize(fSize), bitmapWidth(bWidth), bitmapHeight(bHeight),
      compressionSize(compSize), horizontalPixelsPerMeter(hPixelsPerMeter),
      verticalPixelsPerMeter(vPixelsPerMeter)
{
}

void WindowsBitmapHeader::readFileHeader(std::istream& sourceStream)
{
    verifyEquality(firstIdentifier, Byte::read(sourceStream), "firstIdentifier");
    verifyEquality(secondIdentifier, Byte::read (sourceStream), "secondIdentifier");
    this->fileSize = DoubleWord::readLittleEndian(sourceStream);
    verifyEquality(reserved, DoubleWord::readLittleEndian(sourceStream), "reserved");
    verifyEquality(rawImageByteOffset, DoubleWord::readLittleEndian(sourceStream), "rawImageByteOffset");
}

void WindowsBitmapHeader::readInfoHeader(std::istream& sourceStream)
{
    verifyEquality(infoHeaderBytes, DoubleWord::readLittleEndian(sourceStream), "infoHeaderBytes");
    this->bitmapWidth = DoubleWord::readLittleEndian(sourceStream);
    this->bitmapHeight = DoubleWord::readLittleEndian(sourceStream);
    verifyEquality(numberOfPlanes, Word::readLittleEndian(sourceStream), "numberOfPlanes");
    verifyEquality(bitsPerPixel, Word::readLittleEndian(sourceStream), "bitsPerPixel");
    verifyEquality(compressionType, DoubleWord::readLittleEndian(sourceStream), "compressionType");
    this->compressionSize = DoubleWord::readLittleEndian(sourceStream);
    this->horizontalPixelsPerMeter = DoubleWord::readLittleEndian(sourceStream);
    this->verticalPixelsPerMeter = DoubleWord::readLittleEndian(sourceStream);
    verifyEquality(numberOfColors, DoubleWord::readLittleEndian(sourceStream), "numberOfColors");
    verifyEquality(numberOfImportantColors, DoubleWord::readLittleEndian(sourceStream), "numberOfImportantColors");
}

void WindowsBitmapHeader::write(std::ostream& destinationStream) const
{
    writeFileHeader(destinationStream);
    writeInfoHeader(destinationStream);
}

void WindowsBitmapHeader::writeFileHeader(std::ostream& destinationStream) const
{
    firstIdentifier.write(destinationStream);
    secondIdentifier.write(destinationStream);
    fileSize.writeLittleEndian(destinationStream);
    reserved.writeLittleEndian(destinationStream);
    rawImageByteOffset.writeLittleEndian(destinationStream);
}

void WindowsBitmapHeader::writeInfoHeader(std::ostream& destinationStream) const
{
    infoHeaderBytes.writeLittleEndian(destinationStream);
    bitmapWidth.writeLittleEndian(destinationStream);
    bitmapHeight.writeLittleEndian(destinationStream);
    numberOfPlanes.writeLittleEndian(destinationStream);
    bitsPerPixel.writeLittleEndian(destinationStream);
    compressionType.writeLittleEndian(destinationStream);
    compressionSize.writeLittleEndian(destinationStream);
    horizontalPixelsPerMeter.writeLittleEndian(destinationStream);
    verticalPixelsPerMeter.writeLittleEndian(destinationStream);
    numberOfColors.writeLittleEndian(destinationStream);
    numberOfImportantColors.writeLittleEndian(destinationStream);
}
