//
//  SceneReader.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/5/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "SceneReader.hpp"

Framework::Scene Framework::SceneReader::readScene(Xml::Element sceneElement)
{
    Scene scene;
    scene.setHeight(std::stoi(sceneElement.getAttribute("height")));
    scene.setWidth(std::stoi(sceneElement.getAttribute("width")));
    
    for (auto layerElement : sceneElement.getChildElements())
    {
        Layer layer(layerElement->getAttribute("alias"));
        
        for (auto placedGraphicElement : layerElement->getChildElements())
        {
            PlacedGraphic placedGraphic;
            placedGraphic.setPlacementPoint(Point(std::stoi(placedGraphicElement->getAttribute("x")),
                                                  std::stoi(placedGraphicElement->getAttribute("y"))
                                                  ));
            
            for (auto vectorGraphicElement : placedGraphicElement->getChildElements())
            {
                HVectorGraphic vg = std::make_shared<VG::VectorGraphic>();
                if(vectorGraphicElement->getAttribute("closed") == "true")
                {
                    vg->closeShape();
                }
                else
                {
                    vg->openShape();
                }
                
                for (auto pointElement : vectorGraphicElement->getChildElements())
                {
                    vg->addPoint(Point(std::stoi(pointElement->getAttribute("x")),
                                       std::stoi(pointElement->getAttribute("y"))
                                       ));
                }

                placedGraphic.moveGraphic(vg);
            }

            layer.insert(layer.end(), std::move(placedGraphic));
        }

        scene.insert(scene.end(), std::move(layer));
    }
    
    return scene;
}
