//
//  SlashStroke.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 9/16/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef SlashStroke_hpp
#define SlashStroke_hpp

#include <stdio.h>
#include "IStroke.hpp"

namespace BitmapGraphics
{
    class SlashStroke : public IStroke
    {
    public:
        SlashStroke(const int& size, const Color& color);
        ~SlashStroke() = default;
        
        SlashStroke(const SlashStroke& src) = default;
        SlashStroke& operator=(const SlashStroke& src) = default;
        SlashStroke(SlashStroke&& src) = default;
        SlashStroke& operator=(SlashStroke&& src) = default;
        
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

#endif /* SlashStroke_hpp */
