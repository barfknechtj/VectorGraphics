//
//  SceneReader.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/5/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef SceneReader_hpp
#define SceneReader_hpp

#include <stdio.h>
#include "Scene.hpp"
#include "XmlParse.hpp"
#include "VectorGraphic.h"

using namespace Xml;

namespace Framework
{
    class SceneReader
    {
    public:
        static Scene readScene(const Element& sceneElement);
        
    private:
        static HLayer _readLayer(const Element& layerElement);
        static HPlacedGraphic _readPlacedGraphic(const Element& pgElement);
        static HVectorGraphic _readVectorGraphic(const Element& vgElement);
    };
}
    
#endif /* SceneReader_hpp */
