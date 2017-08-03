//
//  SceneTest.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 7/30/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include "Scene.hpp"
#include "TestHarness.h"
#include "Point.h"
#include "VectorGraphic.h"


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

//------------------------------------------------------------------------
TEST(equal, Scene)
{
    Framework::Scene scene1(0,0);
    Framework::Scene scene2(0,0);
    
    CHECK_EQUAL(true, scene1 == scene2);
}

TEST(unequalWidth, Scene)
{
    Framework::Scene scene1(0,0);
    Framework::Scene scene2(1000,0);
    
    CHECK_EQUAL(true, scene1 != scene2);
}

TEST(unequalHeight, Scene)
{
    Framework::Scene scene1(0,0);
    Framework::Scene scene2(0,10000);
    
    CHECK_EQUAL(true, scene1 != scene2);
}

TEST(unequalLayerQuantity, Scene)
{
    Framework::Scene scene1(0,0);
    Framework::Scene scene2(0,10000);
    Framework::Layer layer1("red");
    scene1.insert(scene1.begin(), layer1);
    
    CHECK_EQUAL(true, scene1 != scene2);
}

TEST(unequalLayerAliases, Scene)
{
    Framework::Scene scene1(0,0);
    Framework::Scene scene2(0,10000);
    Framework::Layer layer1("red");
    Framework::Layer layer2("blue");
    scene1.insert(scene1.begin(), layer1);
    scene2.insert(scene1.begin(), layer2);
    
    CHECK_EQUAL(true, scene1 != scene2);
}

TEST(beginAndEnd, Scene)
{
    Framework::Scene scene(100, 0);
    
    CHECK_EQUAL(true, ++scene.begin() == scene.end());
}

TEST(size, Scene)
{
    Framework::Scene scene(1,1);
    
    CHECK_EQUAL(0, scene.size());
    
    Framework::Layer layer("red");
    scene.insert(scene.begin(), layer);
    
    CHECK_EQUAL(1, scene.size());
}

TEST(insert, Scene)
{
    VG::HVectorGraphic testGraphic(new VG::VectorGraphic());
    testGraphic->openShape();
    auto pg1 = Framework::PlacedGraphic(VG::Point(11,22), testGraphic);
    Framework::Layer layer("red");
    layer.insert(layer.begin(), pg1);
    Framework::Scene scene(1,1);
    scene.insert(scene.begin(), layer);
    
    auto alias = scene.begin()->getAlias();
    
    CHECK_EQUAL(1, scene.size());
    CHECK_EQUAL("red", alias);
}

TEST(remove, Scene)
{
    Framework::Layer layer1("red");
    Framework::Layer layer2("blue");
    Framework::Scene scene(1,1);
    scene.insert(scene.begin(), layer1);
    scene.insert(scene.begin(), layer2);
    scene.remove(layer1);
    auto alias = scene.begin()->getAlias();
    
    CHECK_EQUAL(1, scene.size());
    CHECK_EQUAL("blue", alias);
}

TEST(erase, Scene)
{
    Framework::Layer layer1("red");
    Framework::Scene scene(1,1);
    scene.insert(scene.begin(), layer1);
    scene.erase(scene.begin());
    
    CHECK_EQUAL(0, scene.size());
}

TEST(getAndSetWidth, Scene)
{
    Framework::Scene scene(100, 0);
    
    CHECK_EQUAL(100, scene.getWidth());
    
    scene.setWidth(200);
    
    CHECK_EQUAL(200, scene.getWidth());
}

TEST(getAndSetHeight, Scene)
{
    Framework::Scene scene(0, 100);
    
    CHECK_EQUAL(100, scene.getHeight());
    
    scene.setHeight(200);
    
    CHECK_EQUAL(200, scene.getHeight());
}

/* Future Test Cases
struct LayerMatcher
{
    LayerMatcher() :
    myMountainsFound(false),
    mySeaFound(false),
    mySkyFound(false)
    {
    }
    
    void operator()(const Framework::Layer& layer)
    {
        if (layer.getAlias() == "Mountains")
        {
            myMountainsFound = true;
        }
        else if (layer.getAlias() == "Sea")
        {
            mySeaFound = true;
        }
        else if (layer.getAlias() == "Sky")
        {
            mySkyFound = true;
        }
    }
    
    bool allLayersFound()
    {
        return myMountainsFound && mySeaFound && mySkyFound;
    }
    
    bool onlyMountainsSkyFound()
    {
        return myMountainsFound && !mySeaFound && mySkyFound;
    }
    
private:
    bool myMountainsFound;
    bool mySeaFound;
    bool mySkyFound;
};

TEST(pushBack, Scene)
{
    Framework::Scene scene(800, 600);
    scene.pushBack(Framework::Layer("Mountains"));
    scene.pushBack(Framework::Layer("Sea"));
    scene.pushBack(Framework::Layer("Sky"));
    
    LayerMatcher matcher = std::for_each(scene.begin(), scene.end(), LayerMatcher());
    CHECK(matcher.allLayersFound());
}

TEST(remove, Scene)
{
    Framework::Scene scene(800, 600);
    scene.pushBack(Framework::Layer("Mountains"));
    scene.pushBack(Framework::Layer("Sea"));
    scene.pushBack(Framework::Layer("Sky"));
    
    scene.remove(Framework::Layer("Sea"));
    
    LayerMatcher matcher = std::for_each(scene.begin(), scene.end(), LayerMatcher());
    CHECK(matcher.onlyMountainsSkyFound());
}
*/
