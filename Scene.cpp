//
//  Scene.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 7/30/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "Scene.hpp"

using Scene = Framework::Scene;

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

Scene::LayerIterator Scene::insert(LayerIterator it, Layer&& layer)
{
    return myLayers.insert(it, layer);
}

void Scene::pushBack(const Layer& layer)
{
    myLayers.push_back(layer);
    return;
}

void Scene::pushBack(Layer&& layer)
{
    myLayers.push_back(layer);
    return;
}

void Scene::draw(HCanvas& canvas)
{
    for (auto layer : myLayers)
    {
        layer.draw(canvas);
    }
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
