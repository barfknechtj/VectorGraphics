//
//  LayerTest.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/14/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include "Layer.hpp"
#include "TestHarness.h"
#include "VectorGraphic.h"
#include "PlacedGraphic.hpp"

TEST(equal, Layer)
{
    Framework::Layer layer1("blue");
    VG::HVectorGraphic testGraphic(new VG::VectorGraphic());
    auto pg1 = Framework::PlacedGraphic(VG::Point(1,1), testGraphic);
    layer1.insert(layer1.begin(), pg1);
    
    Framework::Layer layer2("blue");
    auto pg2 = Framework::PlacedGraphic(VG::Point(1,1), testGraphic);
    layer2.insert(layer2.begin(), pg2);
    
    CHECK_EQUAL(true, layer1 == layer2);
}

TEST(unequalAlias, Layer)
{
    Framework::Layer layer1("red");
    VG::HVectorGraphic testGraphic(new VG::VectorGraphic());
    auto pg1 = Framework::PlacedGraphic(VG::Point(1,1), testGraphic);
    layer1.insert(layer1.begin(), pg1);
    
    Framework::Layer layer2("blue");
    auto pg2 = Framework::PlacedGraphic(VG::Point(1,1), testGraphic);
    layer2.insert(layer2.begin(), pg2);
    
    CHECK_EQUAL(true, layer1 != layer2);
}

TEST(unequalPlacedGraphicQuantity, Layer)
{
    Framework::Layer layer1("red");
    VG::HVectorGraphic testGraphic(new VG::VectorGraphic());
    auto pg1 = Framework::PlacedGraphic(VG::Point(1,1), testGraphic);
    layer1.insert(layer1.begin(), pg1);
    
    Framework::Layer layer2("blue");
    
    CHECK_EQUAL(true, layer1 != layer2);
}

TEST(unequalPlacedGraphicPoints, Layer)
{
    Framework::Layer layer1("red");
    VG::HVectorGraphic testGraphic(new VG::VectorGraphic());
    auto pg1 = Framework::PlacedGraphic(VG::Point(1,1), testGraphic);
    layer1.insert(layer1.begin(), pg1);
    
    Framework::Layer layer2("blue");
    auto pg2 = Framework::PlacedGraphic(VG::Point(222,222), testGraphic);
    layer2.insert(layer2.begin(), pg2);
    
    CHECK_EQUAL(true, layer1 != layer2);
}

TEST(beginAndEnd, Layer)
{
    Framework::Layer layer("blue");
    
    CHECK_EQUAL(true, layer.begin() == layer.end());
    
    VG::HVectorGraphic testGraphic(new VG::VectorGraphic());
    auto pg = Framework::PlacedGraphic(VG::Point(1,1), testGraphic);
    layer.insert(layer.begin(), pg);
    
    CHECK_EQUAL(true, ++layer.begin() == layer.end());
}

TEST(size, Layer)
{
    Framework::Layer layer("blue");
    
    CHECK_EQUAL(0, layer.size());
    
    VG::HVectorGraphic testGraphic(new VG::VectorGraphic());
    auto pg = Framework::PlacedGraphic(VG::Point(1,1), testGraphic);
    layer.insert(layer.begin(), pg);
    
    CHECK_EQUAL(1, layer.size());
}

TEST(insert, Layer)
{
    Framework::Layer layer("tree");
    VG::HVectorGraphic testGraphic(new VG::VectorGraphic());
    auto pg = Framework::PlacedGraphic(VG::Point(1,1), testGraphic);
    auto it1 = layer.insert(layer.begin(), pg);
    
    CHECK_EQUAL(true, *(layer.begin()) == *it1);
    CHECK_EQUAL(1, layer.size());
    CHECK_EQUAL(1, layer.begin()->getPlacementPoint().getX());
    CHECK_EQUAL(1, layer.begin()->getPlacementPoint().getY());
    CHECK_EQUAL("tree", layer.getAlias());
}

TEST(insertRValue, Layer)
{
    Framework::Layer layer("tree");
    VG::VectorGraphic vg;
    vg.addPoint(VG::Point(100,100));
    VG::HVectorGraphic testGraphic = std::make_shared<VG::VectorGraphic>(vg);
    auto pg = Framework::PlacedGraphic(VG::Point(1,1), testGraphic);
    auto it1 = layer.insert(layer.begin(), std::move(pg));
    
    CHECK_EQUAL(true, *(layer.begin()) == *it1);
    CHECK_EQUAL(1, layer.size());
    CHECK_EQUAL(1, layer.begin()->getPlacementPoint().getX());
    CHECK_EQUAL(1, layer.begin()->getPlacementPoint().getY());
    CHECK_EQUAL("tree", layer.getAlias());
}

TEST(pushBack, Layer)
{
    Framework::Layer layer("tree");
    VG::HVectorGraphic testGraphic(new VG::VectorGraphic());
    auto pg = Framework::PlacedGraphic(VG::Point(1,1), testGraphic);
    layer.pushBack(pg);
    
    CHECK_EQUAL(1, layer.size());
    CHECK_EQUAL("tree", layer.getAlias());
}

TEST(erase, Layer)
{
    Framework::Layer layer("blue");
    VG::HVectorGraphic testGraphic(new VG::VectorGraphic());
    auto pg = Framework::PlacedGraphic(VG::Point(1,1), testGraphic);
    auto it1 = layer.insert(layer.begin(), pg);
    
    CHECK_EQUAL(1, layer.size());
    
    auto iterEnd = layer.erase(it1);
    
    CHECK_EQUAL(0, layer.size())
    CHECK_EQUAL(true, *layer.end() == *iterEnd);
}

TEST(remove, Layer)
{
    Framework::Layer layer("blue");
    VG::HVectorGraphic testGraphic(new VG::VectorGraphic());
    auto pg1 = Framework::PlacedGraphic(VG::Point(1,1), testGraphic);
    auto pg2 = Framework::PlacedGraphic(VG::Point(2,2), testGraphic);
    layer.insert(layer.begin(), pg1);
    layer.insert(layer.begin(), pg2);
    layer.remove(pg1);
    
    CHECK_EQUAL(1, layer.size())
    CHECK_EQUAL(2, layer.begin()->getPlacementPoint().getX());
    CHECK_EQUAL(2, layer.begin()->getPlacementPoint().getY());
}

TEST(getAndSetAlias, Layer)
{
    Framework::Layer layer("tree");
    CHECK_EQUAL("tree", layer.getAlias());
    
    layer.setAlias("rock");
    CHECK_EQUAL("rock", layer.getAlias());
}
