#pragma once

#include <vector>
#include "Point.h"
#include "ICanvas.hpp"
#include "IStroke.hpp"
#include "Color.hpp"
#include "SquareStroke.hpp"
#include "LineIterator.hpp"

using namespace BitmapGraphics;

namespace VG
{
    using Points = std::vector<Point>;
    
    class VectorGraphic
    {
    public:
        VectorGraphic(HStroke stroke = std::make_shared<SquareStroke>(1, Color{0, 0, 0}));
        VectorGraphic(const VectorGraphic& rhs) = default;
        VectorGraphic(VectorGraphic&& rhs) = default;
        VG::VectorGraphic& operator=(const VectorGraphic& rhs) = default;
        VG::VectorGraphic& operator=(VectorGraphic&& rhs) = default;
        ~VectorGraphic() = default;
        
        void addPoint(const Point& p);
        void removePoint(const Point& p);
        void erasePoint(int index);
        
        void setStroke(HStroke& stroke);
        void setStroke(HStroke&& stroke);
        
        void openShape();
        void closeShape();
        
        bool isOpen() const;
        bool isClosed() const;
        
        int getWidth() const;
        int getHeight() const;
        
        size_t getPointCount() const;
        Point getPoint(int index) const;
        
        void draw(HCanvas& canvas, const Point& offset);
        
        bool operator==(const VectorGraphic& rhs) const;
        bool operator!=(const VectorGraphic& rhs) const;
        
    private:
        Points myPath;
        HStroke hStroke;
        
        enum class ShapeStyle { Open, Closed } myShapeStyle;
    };
    
    using HVectorGraphic = std::shared_ptr<VectorGraphic>;
}
