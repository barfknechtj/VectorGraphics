//
//  PlacedGraphic.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 7/29/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "PlacedGraphic.hpp"

Framework::PlacedGraphic::PlacedGraphic()
    : placementPoint(Point())
{
}

Framework::PlacedGraphic::PlacedGraphic(const Point& point,
                                        const HVectorGraphic& hVectorGraphic)
    : placementPoint(point), hGraphic(hVectorGraphic)
{
}

void Framework::PlacedGraphic::setPlacementPoint(Point const& placement)
{
    placementPoint = placement;
}

VG::Point const& Framework::PlacedGraphic::getPlacementPoint() const
{
    return placementPoint;
}

void Framework::PlacedGraphic::setGraphic(HVectorGraphic const& graphic)
{
    hGraphic = graphic;
}

VG::HVectorGraphic const& Framework::PlacedGraphic::getGraphic() const
{
    return hGraphic;
}
