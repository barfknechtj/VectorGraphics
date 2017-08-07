//
//  XmlParser.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/2/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "XmlParse.hpp"
#include "Utilities.h"
#include <iostream>
#include <memory>
#include <string>


bool getElement(std::istream& xml, std::string& name)
{
    char c{};
    if (xml.peek() == EOF)
    {
        return false;
    }
    
    name.clear();
    Parse::eat(xml);
    while (xml.get(c))
    {
        // whitespace delimits the element name
        if (isspace(c))
        {
            break;
        }
        
        if (c == '>')
        {
            xml.unget();
            break;
        }
        
        name.push_back(c);
    }
    
    Parse::trim(name);
    return true;
}

bool getAttribute(std::istream& xml, std::string& name, std::string& value)
{
    Parse::eat(xml);
    
    // Return false if no more attributes in the current element
    if (xml.peek() == '/' || xml.peek() == '>')
    {
        return false;
    }
    
    // Extract the next attribute name
    name.clear();
    char c{};
    while (xml.get(c))
    {
        if (c == '=')
        {
            break;
        }
        
        name.push_back(c);
    }
    Parse::trim(name);
    
    // Extract the next attribute value. Values are delimited
    // by quotes (single or double)
    value.clear();
    Parse::eat(xml);
    Parse::eat(xml, "\'\"");
    while (xml.get(c))
    {
        if (c == '\"' || c == '\'')
        {
            break;
        }
        
        value.push_back(c);
    }
    
    return true;
}





