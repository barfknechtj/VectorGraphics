//
//  XmlWriter.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/6/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "XmlWriter.hpp"

//------------------------------------------------------------------------
std::ostream& Xml::Writer::writeXml(Xml::HElement element, std::ostream& os)
{
    os << "<";
    writeName(element, os);
    writeAttributes(element, os);
    
    if(element->hasChildren())
    {
        os << ">\n";
        for (auto childElement : element->getChildElements())
        {
            writeXml(childElement, os);
        }
        writeNewLineEndTag(element, os);
    }
    else
    {
        os << "/>\n";
    }
    
    return os;
}

std::ostream& Xml::Writer::writeName(Xml::HElement element, std::ostream& os)
{
    os << element->getName();
    return os;
}

std::ostream& Xml::Writer::writeAttributes(Xml::HElement element, std::ostream& os)
{
    auto attributes = element->getAttributes();
    std::map<std::string, std::string>::iterator it;
    
    for (it = attributes.begin(); it != attributes.end(); ++it)
    {
        os << " " << it->first << "=\"" << it->second << "\"";
    }
    
    return os;
}

std::ostream& Xml::Writer::writeNewLineEndTag(Xml::HElement element, std::ostream& os)
{
    os << "</";
    writeName(element, os);
    os << ">\n";
    return os;
}
