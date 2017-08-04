//
//  XmlParserTest.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/2/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <stdio.h>
#include "TestHarness.h"
#include "XmlParser.hpp"

TEST(getName, Element)
{
    XML::Element element("GRAPHIC");
    CHECK_EQUAL("GRAPHIC", element.getName());
}

TEST(getAttributeRValue, Element)
{
    XML::Element element("GRAPHIC");
    std::pair<std::string, std::string> attributeX{"x", "111"};
    std::pair<std::string, std::string> attributeY{"y", "222"};
    element.addAttribute(attributeX);
    element.addAttribute(attributeY);
    
    CHECK_EQUAL(std::string{"111"}, element.getAttribute("x"));
    CHECK_EQUAL(std::string{"222"}, element.getAttribute("y"));
}

TEST(getAttributeLValue, Element)
{
    XML::Element element("GRAPHIC");
    std::string xPoint{"x"};
    std::string yPoint{"y"};
    std::pair<std::string, std::string> attributeX{xPoint, "111"};
    std::pair<std::string, std::string> attributeY{yPoint, "222"};
    element.addAttribute(attributeX);
    element.addAttribute(attributeY);
    
    CHECK_EQUAL(std::string{"111"}, element.getAttribute(xPoint));
    CHECK_EQUAL(std::string{"222"}, element.getAttribute(yPoint));
}

TEST(getAttributes, Element)
{
    XML::Element element("GRAPHIC");
    std::pair<std::string, std::string> attributeX{"x", "111"};
    std::pair<std::string, std::string> attributeY{"y", "222"};
    XML::Element::AttributeMap refMap{attributeX, attributeY};
    element.addAttribute(attributeX);
    element.addAttribute(attributeY);
    
    CHECK_EQUAL(true, refMap == element.getAttributes());
}

TEST(getChildElements, Element)
{
    XML::Element parent("parent");
    XML::Element child1("child1");
    XML::Element child2("child2");
    parent.addChildElement(child1);
    parent.addChildElement(child2);
    
    CHECK_EQUAL("child1", parent.getChildElements()[0].getName());
    CHECK_EQUAL("child2", parent.getChildElements()[1].getName());
}
// TODO: getChildElements, addChildElement
