//
//  XmlParser.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/2/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "XmlParser.hpp"

Xml::Element::Element(const std::string& name)
    : myName(name)
{
}

std::string Xml::Element::getName() const
{
    return myName;
}

std::string Xml::Element::getAttribute(const std::string& key)
{
    return myAttributes[key];
}

std::string Xml::Element::getAttribute(const std::string&& key)
{
    return myAttributes[key];
}

Xml::AttributeMap Xml::Element::getAttributes() const
{
    return myAttributes;
}

std::vector<Xml::Element> Xml::Element::getChildElements() const
{
    return myChildElements;
}

void Xml::Element::addAttribute(std::pair<std::string, std::string> attribute)
{
    myAttributes.insert(attribute);
}

void Xml::Element::addChildElement(const Xml::Element& childElement)
{
    myChildElements.push_back(childElement);
}
