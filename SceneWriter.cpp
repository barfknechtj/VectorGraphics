//
//  SceneWriter.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/6/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "SceneWriter.hpp"

Xml::HElement Framework::SceneWriter::writeScene(Framework::Scene& scene)
{
    auto sceneElement = std::make_shared<Xml::Element>("Scene");
    sceneElement->addAttribute("width",
                               std::to_string(scene.getWidth())),
    sceneElement->addAttribute("height",
                               std::to_string(scene.getHeight()));

    // process and add Layers
    for (auto layerIter = scene.begin(); layerIter != scene.end(); ++layerIter)
    {
        auto layerElement = sceneElement->addChildElement("Layer");
        layerElement->addAttribute("alias", layerIter->getAlias());
        
        // process and add PlacedGraphics
        for (auto placedGraphicIter = layerIter->begin();
             placedGraphicIter != layerIter->end();
             ++placedGraphicIter)
        {
            auto pgElement = layerElement->addChildElement("PlacedGraphic");
            pgElement->addAttribute("x",
                                    std::to_string(placedGraphicIter->getPlacementPoint().getX()));
            pgElement->addAttribute("y",
                                    std::to_string(placedGraphicIter->getPlacementPoint().getY()));
        
            // process and add VectorGraphics
            auto graphic = placedGraphicIter->getGraphic();
            auto vgElement = pgElement->addChildElement("VectorGraphic");
            vgElement->addAttribute("closed", boolToStr(graphic->isClosed()));
            
            //process and add Points
            for (auto pointIndex = 0; pointIndex != graphic->getPointCount(); ++pointIndex)
            {
                auto point = graphic->getPoint(pointIndex);
                auto pointElement = vgElement->addChildElement("Point");
                pointElement->addAttribute("x", std::to_string(point.getX()));
                pointElement->addAttribute("y", std::to_string(point.getY()));
                
            }
        }
    }
    
    return sceneElement;
}
