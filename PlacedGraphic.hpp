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

namespace Framework
{
    using Point = VG::Point;
    using HVectorGraphic = VG::HVectorGraphic;
    
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
        void moveGraphic(HVectorGraphic& graphic);
        HVectorGraphic const& getGraphic() const;
        
        bool operator==(const PlacedGraphic& rhs) const;
        bool operator!=(const PlacedGraphic& rhs) const;
        
    private:
        Point placementPoint;
        HVectorGraphic hGraphic;
    };
}

#endif /* PlacedGraphic_hpp */
