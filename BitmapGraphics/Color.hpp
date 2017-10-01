//
//  Color.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/15/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef Color_hpp
#define Color_hpp

#include <stdio.h>
#include "Byte.hpp"

namespace BitmapGraphics
{
    class Color
    {
    public:
        Color() = default;
        Color(const std::string& hexColorValue);
        ~Color() = default;
        
        template<typename T>
        Color(const std::initializer_list<T> data)
        {
            auto it = data.begin();
            auto itEnd = data.end();
            if(it != itEnd) {red = *it++;};
            if(it != itEnd) {green = *it++;};
            if(it != itEnd) {blue = *it;};
        }
        
        static Color read(std::istream& is);
        void write(std::ostream& os);
        
        Binary::Byte getBlue() const {return blue;}
        Binary::Byte getGreen() const {return green;}
        Binary::Byte getRed() const {return red;}
        
    private:
        Binary::Byte blue;
        Binary::Byte green;
        Binary::Byte red;
    };
    
    bool operator==(const Color& lhs, const Color& rhs);
}

#endif /* Color_hpp */
