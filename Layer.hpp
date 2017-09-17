//
//  Layer.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/14/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef Layer_hpp
#define Layer_hpp

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
        
        Layer() = default;
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
        PlacedGraphicIterator insert(PlacedGraphicIterator it,
                                     PlacedGraphic&& placedGraphic);
        void pushBack(const PlacedGraphic& placedGraphic);
        void pushBack(PlacedGraphic&& placedGraphic);
        
        void draw(HCanvas& canvas);
        
        PlacedGraphicIterator erase(PlacedGraphicIterator it);
        void remove(const PlacedGraphic& placedGraphic);
        
        std::string getAlias() const;
        void setAlias(const std::string& alias);
        
        bool operator==(const Layer& rhs) const;
        bool operator!=(const Layer& rhs) const;
        
    private:
        PlacedGraphicCollection myGraphics;
        std::string myAlias;
    };
}

#endif /* Layer_hpp */
