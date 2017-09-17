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
#include <vector>
#include <memory>
#include <utility>
#include "Color.hpp"
#include "IBitmapIterator.hpp"

namespace BitmapGraphics
{
    using ScanLine = std::list<Color>;
    using ScanLineCollection = std::list<ScanLine>;
    
    
    class Bitmap
    {        
    private:
        
        int myWidth;
        int myHeight;
        ScanLineCollection myScanLineCollection;
        
    public:
        
        typedef ScanLine::iterator ColorIterator;
        typedef ScanLineCollection::iterator ScanLineIterator;
        typedef ScanLineCollection::reverse_iterator ScanLineRevIterator;
        
        Bitmap() = default;
        Bitmap(const int& width, const int& height, std::istream& sourceStream = std::cin);
        Bitmap(const int& width, const int& height, const Color& backgroundColor);
        ~Bitmap() = default;
        
        ScanLineIterator begin() {return myScanLineCollection.begin();}
        ScanLineRevIterator rbegin() {return myScanLineCollection.rbegin();}
        ScanLineIterator end() {return myScanLineCollection.end();}
        ScanLineRevIterator rend() {return myScanLineCollection.rend();}
        
        HBitmapIterator createIterator();
        HBitmapIterator createReverseIterator();
        
        int calcNumOfPads() const;
        
        void write(std::ostream& destinationStream) const;

        int getWidth() const {return static_cast<int>(myWidth);}
        int getHeight() const {return static_cast<int>(myHeight);}
    };
    
    using HBitmap = std::shared_ptr<Bitmap>;
}

#endif /* Bitmap_hpp */
