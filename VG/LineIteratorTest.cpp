//
//  LineIteratorTest.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/11/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <stdio.h>
#include <list>
#include "LineIterator.hpp"
#include "TestHarness.h"

TEST(nextPixel, LineIterator)
{
    VG::Point startPoint(0, 0);
    VG::Point endPoint(5, 5);
    
    VG::LineIterator lineIterator(startPoint, endPoint);
    std::list<VG::Point> points;
    
    while(!lineIterator.isEnd())
    {
        points.push_back(lineIterator.getCurrentPoint());
        lineIterator.nextPoint();
    }
    
    int x{0};
    int y{0};
    
    std::list<VG::Point>::iterator iter = points.begin();
    
    while(iter != points.end())
    {
        VG::Point refPoint(x, y);
        CHECK_EQUAL(true, refPoint == *iter);
        ++iter; ++x; ++y;
    }
}
