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

TEST(insertRValue, Scene)
{
    Framework::Layer layer("tree");
    VG::VectorGraphic vg;
    vg.addPoint(VG::Point(100,100));
    VG::HVectorGraphic testGraphic = std::make_shared<VG::VectorGraphic>(vg);
    auto pg = Framework::PlacedGraphic(VG::Point(1,1), testGraphic);
    layer.insert(layer.begin(), std::move(pg));
    
    Framework::Scene scene;
    auto it1 = scene.insert(scene.begin(), std::move(layer));
    
    CHECK_EQUAL(true, *(scene.begin()) == *it1);
    CHECK_EQUAL(1, scene.size());
    CHECK_EQUAL(1, scene.begin()->begin()->getPlacementPoint().getX());
    CHECK_EQUAL(1, scene.begin()->begin()->getPlacementPoint().getY());
    CHECK_EQUAL("tree", scene.begin()->getAlias());
}


TEST(pushBack, Scene)
{
    VG::HVectorGraphic testGraphic(new VG::VectorGraphic());
    testGraphic->openShape();
    auto pg1 = Framework::PlacedGraphic(VG::Point(11,22), testGraphic);
    Framework::Layer layer("red");
    layer.insert(layer.begin(), pg1);
    Framework::Scene scene(1,1);
    scene.pushBack(layer);
    
    CHECK_EQUAL(1, scene.size());
    CHECK_EQUAL("red", scene.begin()->getAlias());
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

// use struct for matching multiple layers in testing
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

TEST(pushBackWithStruct, Scene)
{
    Framework::Scene scene(800, 600);
    scene.pushBack(Framework::Layer("Mountains"));
    scene.pushBack(Framework::Layer("Sea"));
    scene.pushBack(Framework::Layer("Sky"));
    
    LayerMatcher matcher = std::for_each(scene.begin(), scene.end(), LayerMatcher());
    CHECK(matcher.allLayersFound());
}

TEST(removeWithStruct, Scene)
{
    Framework::Scene scene(800, 600);
    scene.pushBack(Framework::Layer("Mountains"));
    scene.pushBack(Framework::Layer("Sea"));
    scene.pushBack(Framework::Layer("Sky"));
    
    scene.remove(Framework::Layer("Sea"));
    
    LayerMatcher matcher = std::for_each(scene.begin(), scene.end(), LayerMatcher());
    CHECK(matcher.onlyMountainsSkyFound());
}
