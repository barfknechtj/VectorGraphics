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

std::string XML::Element::getAttribute(std::string& key)
{
    return myAttributes[key];
}

XML::attributeMap XML::Element::getAttributes() const
{
    return myAttributes;
}

std::vector<XML::Element> XML::Element::getChildElements() const
{
    return myChildElements;
}

// TODO: addAttribute, addChildElement
