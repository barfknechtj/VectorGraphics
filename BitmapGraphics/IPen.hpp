//
//  IPen.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/11/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef IPen_hpp
#define IPen_hpp

#include <stdio.h>
#include "Point.h"
#include "IPen.hpp"

namespace BitmapGraphics
{
    class IPen
    {
    public:
        virtual void drawPoint(const HCanvas& canvas,
                               const VG::Point& point) = 0;
    };
    
    using HPen = std::shared_ptr<IPen>;
}

#endif /* IPen_hpp */
