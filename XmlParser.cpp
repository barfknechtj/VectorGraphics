//
//  XmlParser.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/2/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "XmlParser.hpp"

XML::Element::Element(const std::string& name)
    : myName(name)
{
}

std::string XML::Element::getName() const
{
    return myName;
}

std::string XML::Element::getAttribute(const std::string& key)
{
    return myAttributes[key];
}

std::string XML::Element::getAttribute(const std::string&& key)
{
    return myAttributes[key];
}

XML::Element::AttributeMap XML::Element::getAttributes() const
{
    return myAttributes;
}

std::vector<XML::Element> XML::Element::getChildElements() const
{
    return myChildElements;
}

void XML::Element::addAttribute(std::pair<std::string, std::string> attribute)
{
    myAttributes.insert(attribute);
}

void XML::Element::addChildElement(const XML::Element& childElement)
{
    myChildElements.push_back(childElement);
}
