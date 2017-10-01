#pragma once

#include <iosfwd>

namespace VG
{
    class Point
    {
    public:
        constexpr Point() : myX{0}, myY(0) { }
        constexpr Point(int x, int y) : myX{x}, myY{y} { }
        Point(const Point& rhs) = default;
        Point(Point&& rhs) = default;
        Point& operator=(const Point& rhs) = default;
        Point& operator=(Point&& rhs) = default;
        ~Point() = default;
        
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
