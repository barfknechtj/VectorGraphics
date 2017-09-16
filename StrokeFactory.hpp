//
//  StrokeFactory.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef StrokeFactory_hpp
#define StrokeFactory_hpp

#include <stdio.h>
#include "IStroke.hpp"

namespace BitmapGraphics
{
    class StrokeFactory
    {
    public:
        static HStroke createStroke(const std::string& strokeType = "square",
                                    const int& size = 1,
                                    const Color& color = Color{0, 0, 0});
        
    private:
        StrokeFactory() = delete;
        ~StrokeFactory() = delete;
    };
}

#endif /* StrokeFactory_hpp */
