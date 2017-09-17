//
//  Element.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/6/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "Element.hpp"

Xml::Element::Element(const std::string& name)
: myName(name)
{
}

std::string const& Xml::Element::getName() const
{
    return myName;
}

std::string Xml::Element::getAttribute(const std::string& key) const
{
    return myAttributes.at(key);
}

std::string Xml::Element::getAttribute(const std::string&& key) const
{
    return myAttributes.at(key);
}

Xml::AttributeMap const& Xml::Element::getAttributes() const
{
    return myAttributes;
}

Xml::ChildElements const& Xml::Element::getChildElements() const
{
    return myChildElements;
}

void Xml::Element::setName(const std::string& name)
{
    myName = name;
}

void Xml::Element::addAttribute(std::string key, std::string value)
{
    myAttributes.insert(std::make_pair(key, value));
}

std::shared_ptr<Xml::Element> Xml::Element::addChildElement(std::string childElementName)
{
    auto childElement = std::make_shared<Element>(childElementName);
    myChildElements.push_back(childElement);
    return childElement;
}

bool Xml::Element::hasChildren() const
{
    return (!myChildElements.empty());
}
