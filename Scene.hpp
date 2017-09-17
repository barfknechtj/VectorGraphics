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
#include "Layer.hpp"

namespace Framework
{    
    class Scene
    {
    private:
        typedef std::list<Layer> LayerCollection;
        
    public:
        typedef LayerCollection::iterator LayerIterator;
        
        Scene() = default;
        Scene(const int& width, const int& height);
        Scene(const Scene& rhs) = default;
        Scene(Scene&& rhs) = default;
        Scene& operator=(const Scene& rhs) = default;
        Scene& operator=(Scene&& rhs) = default;
        ~Scene() = default;
        
        bool operator==(const Scene& rhs) const;
        bool operator!=(const Scene& rhs) const;
        
        LayerIterator begin();
        LayerIterator end();
        size_t size() const;
        
        LayerIterator insert(LayerIterator it, const Layer& layer);
        LayerIterator insert(LayerIterator it, Layer&& layer);
        void pushBack(const Layer& layer);
        void pushBack(Layer&& layer);
        
        void draw(HCanvas& canvas);
        
        LayerIterator erase(LayerIterator it);
        void remove(const Layer& layer);
        
        int getWidth() const;
        void setWidth(const int& width);
        
        int getHeight() const;
        void setHeight(const int& height);
        
    private:
        LayerCollection myLayers;
        int myWidth;
        int myHeight;
    };
}

#endif /* Scene_hpp */
