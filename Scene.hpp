//
//  Scene.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 7/30/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <stdio.h>
#include <list>
#include <string>
#include "PlacedGraphic.hpp"

namespace Framework
{
    using PlacedGraphic = Framework::PlacedGraphic;
    
    class Layer
    {
    private:
        typedef std::list<PlacedGraphic> PlacedGraphicCollection;
        
    public:
        typedef PlacedGraphicCollection::iterator PlacedGraphicIterator;
        
        Layer(const std::string& alias);
        Layer(const Layer& rhs) = default;
        Layer(Layer&& rhs) = default;
        Layer& operator=(const Layer& rhs) = default;
        Layer& operator=(Layer&& rhs) = default;
        ~Layer() = default;
        
        PlacedGraphicIterator begin();
        PlacedGraphicIterator end();
        size_t size() const;
        
        PlacedGraphicIterator insert(PlacedGraphicIterator it,
                                     const PlacedGraphic& placedGraphic);
        
        PlacedGraphicIterator erase(PlacedGraphicIterator it);
        void remove(const PlacedGraphic& placedGraphic);
        
        std::string getAlias() const;
        void setAlias(const std::string& alias);
        
    private:
        PlacedGraphicCollection myGraphics;
        std::string myAlias;
    };
    
    class Scene
    {
    private:
        typedef std::list<Layer> LayerCollection;
        
    public:
        typedef LayerCollection::iterator LayerIterator;
        
        Scene(const int& width, const int& height);
        Scene(const Scene& rhs) = default;
        Scene(Scene&& rhs) = default;
        Scene& operator=(const Scene& rhs) = default;
        Scene& operator=(Scene&& rhs) = default;
        ~Scene() = default;
        
        // TODO: insert, remove, iteration support.
        
        int getWidth() const;
        void setWidth(const int& width);
        
        int getHeight() const;
        void setHeight(const int& height);
        
    private:
        LayerCollection layers;
        int myWidth;
        int myHeight;
    };
}

#endif /* Scene_hpp */
