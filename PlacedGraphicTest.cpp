    //
//  PlacedGraphicTest.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 7/29/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "PlacedGraphic.hpp"
#include "VectorGraphic.h"
#include "Point.h"
#include "TestHarness.h"

TEST(ctor, PlacedGraphic)
{
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    Framework::PlacedGraphic pg(VG::Point(44, 55), vg);
    
    constexpr VG::Point expected(44, 55);
    CHECK_EQUAL(expected, pg.getPlacementPoint());
    CHECK_EQUAL(vg, pg.getGraphic());
}

TEST(setPlacementPoint, PlacedGraphic)
{
    Framework::PlacedGraphic graphic;
    graphic.setPlacementPoint(VG::Point(44, 55));
    
    constexpr VG::Point expected(44, 55);
    CHECK_EQUAL(expected, graphic.getPlacementPoint());
}

TEST(setGraphic, PlacedGraphic)
{
    Framework::PlacedGraphic pg;
    VG::HVectorGraphic vg(new VG::VectorGraphic);
    pg.setGraphic(vg);
    
    CHECK_EQUAL(vg, pg.getGraphic());
}

TEST(equal, PlacedGraphic)
{
    VG::HVectorGraphic vg1(new VG::VectorGraphic);
    Framework::PlacedGraphic pg1(VG::Point(2, 2), vg1);
    
    VG::HVectorGraphic vg2(new VG::VectorGraphic);
    Framework::PlacedGraphic pg2(VG::Point(2, 2), vg2);
    
    CHECK_EQUAL(false, pg1 == pg2)
}
