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

// TODO: getAttribute, getAttributes, getChildElements, addAttribute, addChildElement
