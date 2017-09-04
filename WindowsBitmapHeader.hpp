//
//  WindowsBitmapHeader.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef WindowsBitmapHeader_hpp
#define WindowsBitmapHeader_hpp

#include <stdio.h>
#include "DoubleWord.hpp"
#include "Word.hpp"
#include "Byte.hpp"
#include "VerifyEquality.h"

using Binary::Byte;
using Binary::Word;
using Binary::DoubleWord;

namespace BitmapGraphics
{
    class WindowsBitmapHeader
    {
    public:
        WindowsBitmapHeader() = default;
        WindowsBitmapHeader(Binary::DoubleWord fSize,
                            Binary::DoubleWord bWidth,
                            Binary::DoubleWord bHeight,
                            Binary::DoubleWord compSize,
                            Binary::DoubleWord hPixelsPerMeter,
                            Binary::DoubleWord vPixelsPerMeter);
        WindowsBitmapHeader(std::istream& sourceStream);
        ~WindowsBitmapHeader() = default;

        void readFileHeader(std::istream& sourceStream);
        void readInfoHeader(std::istream& sourceStream);
        
        void write(std::ostream& destinationStream) const;
        void writeFileHeader(std::ostream& destinationStream) const;
        void writeInfoHeader(std::ostream& destinationStream) const;
        
        Binary::DoubleWord getFileSize() const {return fileSize;};
        Binary::DoubleWord getBitmapWidth() const {return bitmapWidth;};
        Binary::DoubleWord getBitmapHeight() const {return bitmapHeight;};
        Binary::DoubleWord getHorizontalPixelsPerMeter() const {return horizontalPixelsPerMeter;};
        Binary::DoubleWord getVerticalPixelsPerMeter() const {return verticalPixelsPerMeter;};

    private:
        
        //-----file header-----
        const static Binary::DoubleWord fileHeaderBytes; // not actually in header
        const static Binary::Byte firstIdentifier;
        const static Binary::Byte secondIdentifier;
        Binary::DoubleWord fileSize;
        const static Binary::DoubleWord reserved;
        const static Binary::DoubleWord rawImageByteOffset;
        
        //-----info header-----
        const static Binary::DoubleWord infoHeaderBytes;
        Binary::DoubleWord bitmapWidth;
        Binary::DoubleWord bitmapHeight;
        const static Binary::Word numberOfPlanes;
        const static Binary::Word bitsPerPixel;
        const static Binary::DoubleWord compressionType;
        Binary::DoubleWord compressionSize;
        Binary::DoubleWord horizontalPixelsPerMeter;
        Binary::DoubleWord verticalPixelsPerMeter;
        const static Binary::DoubleWord numberOfColors;
        const static Binary::DoubleWord numberOfImportantColors;
    };
}

#endif /* WindowsBitmapHeader_hpp */
