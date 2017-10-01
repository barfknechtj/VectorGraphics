//
//  SquareStroke.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/11/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef SquareStroke_hpp
#define SquareStroke_hpp

#include <stdio.h>
#include "IStroke.hpp"

namespace BitmapGraphics
{
    class SquareStroke : public IStroke
    {
    public:
        SquareStroke(const int& size, const Color& color);
        ~SquareStroke() = default;
        
        SquareStroke(const SquareStroke& src) = default;
        SquareStroke& operator=(const SquareStroke& src) = default;
        SquareStroke(SquareStroke&& src) = default;
        SquareStroke& operator=(SquareStroke&& src) = default;
        
        virtual void setSize(const int& size);
        virtual int getSize() const;
        virtual void setColor(Color const& color);
        virtual Color getColor() const;
        virtual HPen createPen();
        
    private:
        int mySize;
        Color myColor;
    };
}

#endif /* SquareStroke_hpp */
