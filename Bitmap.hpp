//
//  Bitmap.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef Bitmap_hpp
#define Bitmap_hpp

#include <stdio.h>
#include <list>
#include <memory>
#include <utility>
#include "Color.hpp"
#include "IBitmapIterator.hpp"

namespace BitmapGraphics
{
    
    class Bitmap
    {
    public:
        typedef std::list<Color> ScanLine;
        
    private:
        typedef std::list<ScanLine> ScanLineCollection;
        
        int myWidth;
        int myHeight;
        ScanLineCollection myScanLineCollection;
        
    public:
        
        typedef ScanLine::iterator ColorIterator;
        typedef ScanLineCollection::iterator ScanLineIterator;
        
        Bitmap() = default;
        Bitmap(const int& width, const int& height, std::istream& sourceStream = std::cin);
        ~Bitmap() = default;
        
        ScanLineIterator begin() {return myScanLineCollection.begin();}
        ScanLineIterator end() {return myScanLineCollection.end();}
        
        HBitmapIterator createIterator();
        
        int calcNumOfPads() const;
        
        void write(std::ostream& destinationStream) const;
        
        int getWidth() const {return static_cast<int>(myWidth);}
        int getHeight() const {return static_cast<int>(myHeight);}
    };
    
    using HBitmap = std::shared_ptr<Bitmap>;
}

#endif /* Bitmap_hpp */
