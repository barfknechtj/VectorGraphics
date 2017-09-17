//
//  SceneReader.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/5/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "SceneReader.hpp"
#include "StrokeFactory.hpp"

using namespace Xml;

// TODO: reduce nested calls with separate subfunctions
Framework::Scene Framework::SceneReader::readScene(const Xml::Element& sceneElement)
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
                
                ChildElements vgChildren = vectorGraphicElement->getChildElements();
                ChildElements::iterator vgChildIter = vgChildren.begin();
                
                if(vgChildIter->get()->getName() == "Stroke")
                {
                    vg->setStroke(StrokeFactory::createStroke(vgChildIter->get()->getAttribute("tip"),
                                                              std::stoi(vgChildIter->get()->getAttribute("size")),
                                                              Color(vgChildIter->get()->getAttribute("color"))));
                    
                    ++vgChildIter;
                }
                else
                {   // default stroke is a single pixel black square
                    vg->setStroke(StrokeFactory::createStroke());
                }
                
                while(vgChildIter != vgChildren.end())
                {
                    vg->addPoint(Point(std::stoi(vgChildIter->get()->getAttribute("x")),
                                                 std::stoi(vgChildIter->get()->getAttribute("y"))
                                                 ));
                    
                    ++vgChildIter;
                }

                placedGraphic.moveGraphic(vg);
            }

            layer.insert(layer.end(), std::move(placedGraphic));
        }

        scene.insert(scene.end(), std::move(layer));
    }
    
    return scene;
}
