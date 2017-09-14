//
//  IStroke.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/11/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef IStroke_hpp
#define IStroke_hpp

#include <stdio.h>
#include <memory>
#include "Color.hpp"
#include "ICanvas.hpp"
#include "IPen.hpp"

namespace BitmapGraphics
{
    class IStroke
    {
    public:
        virtual void setSize(const int& size) = 0;
        virtual int getSize() const = 0;
        virtual void setColor(Color const& color) = 0;
        virtual Color getColor() const = 0;
        virtual HPen createPen() = 0;
    };
    
    using HStroke = std::shared_ptr<IStroke>;
}


#endif /* IStroke_hpp */
