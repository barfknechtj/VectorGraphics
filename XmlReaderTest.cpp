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
#include "Utilities.h"

TEST(getName, Element)
{
    Xml::Element element("GRAPHIC");
    CHECK_EQUAL("GRAPHIC", element.getName());
}

TEST(getAttributeRValue, Element)
{
    Xml::Element element("GRAPHIC");
    std::pair<std::string, std::string> attributeX{"x", "111"};
    std::pair<std::string, std::string> attributeY{"y", "222"};
    element.addAttribute("x", "111");
    element.addAttribute("y", "222");
    
    CHECK_EQUAL(std::string{"111"}, element.getAttribute("x"));
    CHECK_EQUAL(std::string{"222"}, element.getAttribute("y"));
}

TEST(getAttributeLValue, Element)
{
    Xml::Element element("GRAPHIC");
    std::string xPoint{"x"};
    std::string yPoint{"y"};
    std::pair<std::string, std::string> attributeX{xPoint, "111"};
    std::pair<std::string, std::string> attributeY{yPoint, "222"};
    element.addAttribute("x", "111");
    element.addAttribute("y", "222");
    
    CHECK_EQUAL(std::string{"111"}, element.getAttribute(xPoint));
    CHECK_EQUAL(std::string{"222"}, element.getAttribute(yPoint));
}

TEST(getAttributes, Element)
{
    Xml::Element element("GRAPHIC");
    std::pair<std::string, std::string> attributeX{"x", "111"};
    std::pair<std::string, std::string> attributeY{"y", "222"};
    Xml::AttributeMap refMap{attributeX, attributeY};
    element.addAttribute("x", "111");
    element.addAttribute("y", "222");
    
    CHECK_EQUAL(true, refMap == element.getAttributes());
}

TEST(getChildElements, Element)
{
    Xml::Element parent("parent");
    parent.addChildElement("child1");
    parent.addChildElement("child2");
    
    CHECK_EQUAL("child1", parent.getChildElements()[0]->getName());
    CHECK_EQUAL("child2", parent.getChildElements()[1]->getName());
}

//------------------------------------------------------------------------
#define STR(a) #a

const char* const SceneXml = STR(
<Scene width="800" height="600">
    <Layer alias="sky">
        <PlacedGraphic x="0" y="0">
            <VectorGraphic closed="true">
                <Point x="1" y="2" />
                <Point x="3" y="4" />
                <Point x="5" y="6" />
            </VectorGraphic>
        </PlacedGraphic>
        <PlacedGraphic x="700" y="0">
            <VectorGraphic closed="true">
                <Point x="7" y="8" />
                <Point x="9" y="10" />
                <Point x="11" y="12" />
            </VectorGraphic>
        </PlacedGraphic>
    </Layer>
    <Layer alias="mountains">
        <PlacedGraphic x="250" y="250">
            <VectorGraphic closed="false">
                <Point x="13" y="14" />
                <Point x="15" y="19" />
                <Point x="17" y="18" />
            </VectorGraphic>
        </PlacedGraphic>
    </Layer>
</Scene>);

TEST(loadXml, XmlReader)
{
    std::stringstream xmlStream(SceneXml);
    Xml::Reader reader;
    
    Xml::HElement root = reader.loadXml(xmlStream);
    
    CHECK_EQUAL("Scene", root->getName());
    CHECK_EQUAL("800", root->getAttribute("width"));
    CHECK_EQUAL("600", root->getAttribute("height"));
    try
    {
        root->getAttribute("depth").empty();
    }
    catch(std::exception)
    {
        CHECK(true);
    }
    
    Xml::AttributeMap attributes = root->getAttributes();
    CHECK(!attributes.empty());
    CHECK_EQUAL(2, attributes.size());
    CHECK_EQUAL("800", attributes["width"])
    CHECK_EQUAL("600", attributes["height"])
    
    Xml::ChildElements children = root->getChildElements();
    CHECK(!children.empty());
    CHECK_EQUAL(2, children.size());
    
    Xml::HElement layer0 = children[0];
    CHECK_EQUAL("Layer", layer0->getName());
    attributes = layer0->getAttributes();
    CHECK(!attributes.empty());
    CHECK_EQUAL(1, attributes.size());
    CHECK_EQUAL("sky", layer0->getAttribute("alias"));
    
    Xml::ChildElements layerChildren = layer0->getChildElements();
    CHECK(!layerChildren.empty());
    CHECK_EQUAL(2, layerChildren.size());
    Xml::HElement placedGraphic = layerChildren[0];
    CHECK_EQUAL("PlacedGraphic", placedGraphic->getName());
    attributes = placedGraphic->getAttributes();
    CHECK(!attributes.empty());
    CHECK_EQUAL(2, attributes.size());
    CHECK_EQUAL("0", placedGraphic->getAttribute("x"));
    CHECK_EQUAL("0", placedGraphic->getAttribute("y"));
}
