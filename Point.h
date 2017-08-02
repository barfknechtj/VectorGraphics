#pragma once

#include <iosfwd>

namespace VG
{
    class Point
    {
    public:
        
        // TODO: add functions for rule of five
        constexpr Point() : myX{0}, myY(0) { }
        constexpr Point(int x, int y) : myX{x}, myY{y} { }
        
        constexpr int getX() const { return myX; }
        constexpr int getY() const { return myY; }
        
    private:
        int myX;
        int myY;
    };
    
    bool operator==(const Point& lhs, const Point& rhs);
    bool operator!=(const Point& lhs, const Point& rhs);
    
    std::ostream& operator<<(std::ostream& os, const Point& p);
}
