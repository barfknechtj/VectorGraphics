//
//  Layer.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/14/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "Layer.hpp"

using PlacedGraphic = Framework::PlacedGraphic;
using Layer = Framework::Layer;

Layer::Layer(const std::string& alias)
: myAlias(alias)
{
}

bool Layer::operator==(const Layer& rhs) const
{
    return (myAlias == rhs.myAlias) &&
    (myGraphics == rhs.myGraphics);
}

bool Layer::operator!=(const Layer& rhs) const
{
    return !(*this == rhs);
}

Layer::PlacedGraphicIterator Layer::begin()
{
    return myGraphics.begin();
}

Layer::PlacedGraphicIterator Layer::end()
{
    return myGraphics.end();
}

size_t Layer::size() const
{
    return myGraphics.size();
}

Layer::PlacedGraphicIterator Layer::insert(PlacedGraphicIterator it,
                                           const PlacedGraphic& placedGraphic)
{
    return myGraphics.insert(it, placedGraphic);
}

Layer::PlacedGraphicIterator Layer::insert(PlacedGraphicIterator it,
                                           PlacedGraphic&& placedGraphic)
{
    return myGraphics.insert(it, placedGraphic);
}

void Layer::pushBack(const PlacedGraphic& placedGraphic)
{
    myGraphics.push_back(placedGraphic);
    return;
}

void Layer::draw(HCanvas& canvas)
{
    for(auto placedGraphic : myGraphics)
    {
        placedGraphic.draw(canvas);
    }
}

Layer::PlacedGraphicIterator Layer::erase(PlacedGraphicIterator it)
{
    return myGraphics.erase(it);
}

void Layer::remove(const PlacedGraphic& placedGraphic)
{
    myGraphics.remove(placedGraphic);
}

std::string Layer::getAlias() const
{
    return myAlias;
}

void Layer::setAlias(const std::string& alias)
{
    myAlias = alias;
}
