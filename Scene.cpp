//
//  Scene.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 7/30/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "Scene.hpp"

using PlacedGraphic = Framework::PlacedGraphic;
using Layer = Framework::Layer;
using Scene = Framework::Scene;

Layer::Layer(const std::string& alias)
    : myAlias(alias)
{
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



//------------------------------------------------------------------------
Scene::Scene(const int& width, const int& height)
    : myWidth(width), myHeight(height)
{
}

int Scene::getWidth() const
{
    return myWidth;
}

void Scene::setWidth(const int& width)
{
    myWidth = width;
}

int Scene::getHeight() const
{
    return myHeight;
}

void Scene::setHeight(const int& height)
{
    myHeight = height;
}
