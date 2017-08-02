#pragma once

#include "Point.h"
#include <vector>

namespace VG
{
    using Points = std::vector<Point>;
    
    class VectorGraphic
    {
    public:
        VectorGraphic();
        VectorGraphic(const VectorGraphic& rhs) = default;
        VectorGraphic(VectorGraphic&& rhs) = default;
        VG::VectorGraphic& operator=(const VectorGraphic& rhs) = default;
        VG::VectorGraphic& operator=(VectorGraphic&& rhs) = default;
        ~VectorGraphic() = default;
        
        // TODO: add templated addPoint
        void addPoint(const Point& p);
        void removePoint(const Point& p);
        void erasePoint(int index);
        
        void openShape();
        void closeShape();
        
        bool isOpen() const;
        bool isClosed() const;
        
        int getWidth() const;
        int getHeight() const;
        
        size_t getPointCount() const;
        Point getPoint(int index) const;
        
        bool operator==(const VectorGraphic& rhs) const;
        bool operator!=(const VectorGraphic& rhs) const;
        
    private:
        Points myPath;
        
        enum class ShapeStyle { Open, Closed } myShapeStyle;
    };
    
    using HVectorGraphic = std::shared_ptr<VectorGraphic>;
}
