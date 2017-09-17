//
//  PlacedGraphic.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 7/29/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef PlacedGraphic_hpp
#define PlacedGraphic_hpp

#include <stdio.h>
#include "Point.h"
#include "VectorGraphic.h"
#include "ICanvas.hpp"

using namespace BitmapGraphics;
using namespace VG;

namespace Framework
{
    class PlacedGraphic
    {
    public:
        PlacedGraphic() = default;
        PlacedGraphic(const Point& point,
                      const HVectorGraphic& hVectorGraphic);
        PlacedGraphic(const PlacedGraphic& rhs) = default;
        PlacedGraphic(PlacedGraphic&& rhs) = default;
        PlacedGraphic& operator=(const PlacedGraphic& rhs) = default;
        PlacedGraphic& operator=(PlacedGraphic&& rhs) = default;
        ~PlacedGraphic() = default;
        
        void setPlacementPoint(Point const& placement);
        void setPlacementPoint(Point&& placement);
        Point const& getPlacementPoint() const;
        
        void setGraphic(HVectorGraphic const& graphic);
        HVectorGraphic const& getGraphic() const;
        
        void draw(HCanvas& canvas);
        
        bool operator==(const PlacedGraphic& rhs) const;
        bool operator!=(const PlacedGraphic& rhs) const;
        
    private:
        Point placementPoint;
        HVectorGraphic hGraphic;
    };
    
    using HPlacedGraphic = std::shared_ptr<PlacedGraphic>;
}

#endif /* PlacedGraphic_hpp */
