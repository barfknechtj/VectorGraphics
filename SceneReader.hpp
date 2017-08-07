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

namespace Framework
{
    class SceneReader
    {
    public:
        static Framework::Scene readScene(const Xml::Element& element);
    };
}
    
#endif /* SceneReader_hpp */
