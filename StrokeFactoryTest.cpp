//
//  StrokeFactoryTest.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <stdio.h>
#include "TestHarness.h"
#include "IStroke.hpp"
#include "StrokeFactory.hpp"

using namespace BitmapGraphics;

TEST(defaultStroke, StrokeFactory)
{
    HStroke hStroke = StrokeFactory::createStroke();
    
    CHECK_EQUAL(1, hStroke->getSize());
    CHECK_EQUAL(true, (Color{0, 0, 0} == hStroke->getColor()));
}

TEST(GreenSquareStroke, StrokeFactory)
{
    HStroke hStroke = StrokeFactory::createStroke("square",
                                                  5, Color{0, 255, 0});
    
    CHECK_EQUAL(5, hStroke->getSize());
    CHECK_EQUAL(true, (Color{0, 255, 0} == hStroke->getColor()));
}

TEST(RedSlashStroke, StrokeFactory)
{
    HStroke hStroke = StrokeFactory::createStroke("slash",
                                                  10, Color{255, 0, 0});
    
    CHECK_EQUAL(10, hStroke->getSize());
    CHECK_EQUAL(true, (Color{255, 0, 0} == hStroke->getColor()));
}

TEST(InvalidStroke, StrokeFactory)
{
    try
    {
        StrokeFactory::createStroke("invalid", 1, Color{0, 0, 0});
        CHECK(false);
    }
    catch (const std::exception& exc)
    {
        std::cout << exc.what() << std::endl;
        CHECK(true);
    }
}
