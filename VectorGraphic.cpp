#include "VectorGraphic.h"

#include <algorithm>

namespace VG
{
    VectorGraphic::VectorGraphic(HStroke stroke) :
    myShapeStyle{ShapeStyle::Closed}, hStroke(stroke)
    {
    }
    
    bool VectorGraphic::isOpen() const
    {
        return myShapeStyle == ShapeStyle::Open;
    }
    
    bool VectorGraphic::isClosed() const
    {
        return myShapeStyle == ShapeStyle::Closed;
    }
    
    void VectorGraphic::openShape()
    {
        myShapeStyle = ShapeStyle::Open;
    }
    
    void VectorGraphic::closeShape()
    {
        myShapeStyle = ShapeStyle::Closed;
    }
    
    int VectorGraphic::getWidth() const
    {
        if (myPath.size() > 0)
        {
            auto xMin = myPath[0].getX();
            auto xMax = myPath[0].getX();
            
            for (auto point : myPath)
            {
                xMax = std::max(point.getX(), xMax);
                xMin = std::min(point.getX(), xMin);
            }
            
            return xMax - xMin;
        }
        
        return 0;
    }
    
    int VectorGraphic::getHeight() const
    {
        if (myPath.size() > 0)
        {
            auto yMin = myPath[0].getY();
            auto yMax = myPath[0].getY();
            
            for (auto point : myPath)
            {
                yMax = std::max(point.getY(), yMax);
                yMin = std::min(point.getY(), yMin);
            }
            
            return yMax - yMin;
        }
        
        return 0;
    }
    
    size_t VectorGraphic::getPointCount() const
    {
        return myPath.size();
    }
    
    void VectorGraphic::addPoint(const Point& p)
    {
        myPath.push_back(p);
    }
    
    Point VectorGraphic::getPoint(int index) const
    {
        return myPath.at(index); // throws std::out_of_range if index out of range
    }
    
    void VectorGraphic::removePoint(const Point& p)
    {
        myPath.erase(std::remove(myPath.begin(), myPath.end(), p), myPath.end());
    }
    
    void VectorGraphic::erasePoint(int index)
    {
        if (index >= 0 && static_cast<std::size_t>(index) < myPath.size())
        {
            auto pos = myPath.begin() + index;
            myPath.erase(pos);
        }
        else
        {
            throw std::out_of_range{"index out of range"};
        }
    }
    
    void VectorGraphic::setStroke(HStroke& stroke)
    {
        hStroke = stroke;
    }
    
    void VectorGraphic::setStroke(HStroke&& stroke)
    {
        hStroke = std::move(stroke);
    }
    
    // TODO: add support for closed VG's
    void VectorGraphic::draw(HCanvas& canvas, const Point& offset)
    {
        HPen hPen = hStroke->createPen();
        
        Points::iterator pointIter = myPath.begin();
        VG::Point startPoint = *pointIter;
        ++pointIter;
        
        while(pointIter != myPath.end())
        {
            VG::Point endPoint = *pointIter;
            
            // draw points between startPoint and endPoint
            LineIterator lineIter(startPoint, endPoint);
            while(!lineIter.isEnd())
            {
                VG::Point point = lineIter.getCurrentPoint();
                
                int x0 = point.getX();
                int y0 = point.getY();
                
                int x = x0 + offset.getX();
                int y = y0 + offset.getY();
                
                hPen->drawPoint(canvas, Point(x, y));
                lineIter.nextPoint();
            }
            
            startPoint = endPoint;
            ++pointIter;
        }
        
        if(this->isClosed())
        {
            // draw points to close VectorGraphic
            LineIterator lineIter(*myPath.begin(), *(--myPath.end()));
            while(!lineIter.isEnd())
            {
                VG::Point point = lineIter.getCurrentPoint();
                
                int x0 = point.getX();
                int y0 = point.getY();
                
                int x = x0 + offset.getX();
                int y = y0 + offset.getY();
                
                hPen->drawPoint(canvas, Point(x, y));
                lineIter.nextPoint();
            }
        }
    }
    
    bool VectorGraphic::operator==(const VectorGraphic& rhs) const
    {
        return (myPath == rhs.myPath) && (myShapeStyle == rhs.myShapeStyle);
    }
    
    bool VectorGraphic::operator!=(const VectorGraphic& rhs) const
    {
        return ! (*this == rhs);
    }
}
