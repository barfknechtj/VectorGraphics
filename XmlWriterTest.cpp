//
//  XmlWriterTest.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/6/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include <stdio.h>
#include "TestHarness.h"
#include "XmlParse.hpp"
#include "XmlWriter.hpp"
#include "XmlReader.hpp"

TEST(writeName, XmlWriter)
{
    Xml::HElement element = std::make_shared<Xml::Element>("Dog");
    
    Xml::Writer writer;
    std::stringstream ss;
    writer.writeName(element, ss);
//    writer.writeName(element, std::cout);
    
    CHECK_EQUAL("Dog", ss.str());
}

TEST(writeAttributes, XmlWriter)
{
    Xml::HElement element = std::make_shared<Xml::Element>("Dog");
    element->addAttribute("x", "1");
    element->addAttribute("y", "2");
    
    Xml::Writer writer;
    std::stringstream ss;
    writer.writeAttributes(element, ss);
//    writer.writeAttributes(element, std::cout);
    
    CHECK_EQUAL(" x=\"1\" y=\"2\"", ss.str());
}

TEST(simpleWriteXml, XmlWriter)
{
    const char* ref =
    "<animals>\n<dog color=\"black\" paws=\"4\">\n<lab/>\n"
    "<beagle/>\n</dog>\n<cat/>\n</animals>\n";

    Xml::HElement animals = std::make_shared<Xml::Element>("animals");
    auto dog = animals->addChildElement("dog");
    auto lab = dog->addChildElement("lab");
    auto beagle = dog->addChildElement("beagle");
    auto cat = animals->addChildElement("cat");
    dog->addAttribute("paws", "4");
    dog->addAttribute("color", "black");
 
    Xml::Writer writer;
    std::stringstream ss;
    writer.writeXml(animals, ss);
    
    CHECK_EQUAL(ref, ss.str())
//    writer.writeXml(animals, std::cout);
}

#define STR(b) #b

const char* const xmlScene = STR(
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



TEST(writeXml, XmlWriter)
{
    Xml::Reader reader;
    std::stringstream xmlStream(xmlScene);
    Xml::HElement root = reader.loadXml(xmlStream);
//    writer.writeXml(root, std::cout);
}
