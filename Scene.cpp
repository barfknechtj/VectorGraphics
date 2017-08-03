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

void Layer::pushBack(const PlacedGraphic& placedGraphic)
{
    myGraphics.push_back(placedGraphic);
    return;
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

bool Scene::operator==(const Scene& rhs) const
{
    return (myWidth  == rhs.myWidth)   &&
    (myHeight == rhs.myHeight)  &&
    (myLayers == rhs.myLayers);
}

bool Scene::operator!=(const Scene& rhs) const
{
    return !(*this == rhs);
}

Scene::LayerIterator Scene::begin()
{
    return myLayers.begin();
}

Scene::LayerIterator Scene::end()
{
    return myLayers.end();
}

size_t Scene::size() const
{
    return myLayers.size();
}

Scene::LayerIterator Scene::insert(LayerIterator it, const Layer& layer)
{
    return myLayers.insert(it, layer);
}

void Scene::pushBack(const Layer& layer)
{
    myLayers.push_back(layer);
    return;
}

Scene::LayerIterator Scene::erase(LayerIterator it)
{
    return myLayers.erase(it);
}

void Scene::remove(const Layer& layer)
{
    myLayers.remove(layer);
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
