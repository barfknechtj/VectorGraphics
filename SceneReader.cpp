//
//  SceneReader.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/5/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "SceneReader.hpp"
#include "StrokeFactory.hpp"
#include "VectorGraphic.h"

using namespace Framework;
using namespace Xml;
using namespace VG;

Scene SceneReader::readScene(const Xml::Element& sceneElement)
{
    Scene scene;
    scene.setHeight(std::stoi(sceneElement.getAttribute("height")));
    scene.setWidth(std::stoi(sceneElement.getAttribute("width")));
    
    for (auto layerElement : sceneElement.getChildElements())
    {
        HLayer hLayer = _readLayer(*layerElement);

        scene.insert(scene.end(), *hLayer);
    }
    
    return scene;
}

HLayer SceneReader::_readLayer(const Element& layerElement)
{
    HLayer hLayer{new Layer(layerElement.getAttribute("alias"))};
    
    for (auto placedGraphicElement : layerElement.getChildElements())
    {
        HPlacedGraphic hPg{_readPlacedGraphic(*placedGraphicElement)};
        hLayer->insert(hLayer->end(), std::move(*hPg));
    }
    
    return hLayer;
}

HPlacedGraphic SceneReader::_readPlacedGraphic(const Element& pgElement)
{
    HPlacedGraphic hPg{new PlacedGraphic()};
    hPg ->setPlacementPoint(Point(std::stoi(pgElement.getAttribute("x")),
                                  std::stoi(pgElement.getAttribute("y"))
                                  ));
    
    for (auto vectorGraphicElement : pgElement.getChildElements())
    {
        HVectorGraphic hVg = _readVectorGraphic(*vectorGraphicElement);
        hPg->setGraphic(hVg);
    }
    
    return hPg;
}

HVectorGraphic SceneReader::_readVectorGraphic(const Element& vgElement)
{
    HVectorGraphic hVg{new VectorGraphic()};
    
    if(vgElement.getAttribute("closed") == "true")
    {
        hVg->closeShape();
    }
    else
    {
        hVg->openShape();
    }

    ChildElements vgChildren = vgElement.getChildElements();
    ChildElements::iterator vgChildIter = vgChildren.begin();

    // config stroke as per Xml
    if(vgChildIter->get()->getName() == "Stroke")
    {
        hVg->setStroke(StrokeFactory::createStroke(vgChildIter->get()->getAttribute("tip"),
                                                  std::stoi(vgChildIter->get()->getAttribute("size")),
                                                  Color(vgChildIter->get()->getAttribute("color"))));
        
        ++vgChildIter;
    }
    else
    {   // config stroke default: single pixel black square
        hVg->setStroke(StrokeFactory::createStroke());
    }

    while(vgChildIter != vgChildren.end())
    {
        hVg->addPoint(Point(std::stoi(vgChildIter->get()->getAttribute("x")),
                            std::stoi(vgChildIter->get()->getAttribute("y"))
                            ));
        
        ++vgChildIter;
    }

    return hVg;
}


