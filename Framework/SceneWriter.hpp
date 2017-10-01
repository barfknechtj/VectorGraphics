//
//  SceneWriter.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/6/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef SceneWriter_hpp
#define SceneWriter_hpp

#include <stdio.h>
#include "XmlParse.hpp"
#include "Scene.hpp"
#include "Utilities.h"

namespace Framework
{
    class SceneWriter
    {
    public:
        
        static Xml::HElement writeScene(Framework::Scene& scene);
    };
}

#endif /* SceneWriter_hpp */
