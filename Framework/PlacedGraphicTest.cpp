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
    VG::HVectorGraphic hVg(new VG::VectorGraphic);
    Framework::PlacedGraphic pg(VG::Point(44, 55), hVg);
    
    constexpr VG::Point expected(44, 55);
    CHECK_EQUAL(expected, pg.getPlacementPoint());
    CHECK_EQUAL(hVg, pg.getGraphic());
}

TEST(getAndSetPlacementPoint, PlacedGraphic)
{
    Framework::PlacedGraphic graphic;
    graphic.setPlacementPoint(VG::Point(44, 55));
    
    constexpr VG::Point expected(44, 55);
    CHECK_EQUAL(expected, graphic.getPlacementPoint());
}

TEST(getAndSetGraphic, PlacedGraphic)
{
    Framework::PlacedGraphic pg;
    VG::HVectorGraphic hVg(new VG::VectorGraphic);
    pg.setGraphic(hVg);
    
    CHECK_EQUAL(hVg, pg.getGraphic());
}

TEST(getAndSetRGraphic, PlacedGraphic)
{
    
    VG::VectorGraphic vg;
    vg.addPoint(VG::Point(100,100));
    
    Framework::PlacedGraphic pg;
    VG::HVectorGraphic hVg = std::make_shared<VG::VectorGraphic>(vg);
    pg.setGraphic(hVg);
    
    CHECK_EQUAL(true,
                VG::Point(100,100) == pg.getGraphic()->getPoint(0));
}

TEST(equal, PlacedGraphic)
{
    VG::HVectorGraphic hVg1(new VG::VectorGraphic);
    Framework::PlacedGraphic pg1(VG::Point(2, 2), hVg1);
    
    VG::HVectorGraphic hVg2(new VG::VectorGraphic);
    Framework::PlacedGraphic pg2(VG::Point(2, 2), hVg2);
    
    CHECK_EQUAL(false, pg1 == pg2)
}

TEST(unequal, PlacedGraphic)
{
    VG::HVectorGraphic hVg1(new VG::VectorGraphic);
    Framework::PlacedGraphic pg1(VG::Point(2, 2), hVg1);
    
    VG::HVectorGraphic hVg2(new VG::VectorGraphic);
    Framework::PlacedGraphic pg2(VG::Point(2, 3), hVg2);
    
    CHECK_EQUAL(true, pg1 != pg2)
}
