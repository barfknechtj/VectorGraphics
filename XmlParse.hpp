//
//  XmlParser.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/2/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef XmlParser_hpp
#define XmlParser_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>
#include "VectorGraphic.h"
#include "Parse.h"
#include "Element.hpp"

bool getElement(std::istream& xml, std::string& name);
bool getAttribute(std::istream& xml, std::string& name, std::string& value);

//------------------------------------------------------------------------
class InvalidXmlSyntax : public std::exception
{
public:
//    InvalidXmlSyntax() {};
    virtual const char* what() = 0;
};

class UnexpectedEOF : public InvalidXmlSyntax
{
public:
//    UnexpectedEOF() {};
    const char* what();
};

class InvalidXmlEndTag : public InvalidXmlSyntax
{
public:
//    InvalidXmlEndTag() {};
    const char* what();
};

#endif /* XmlParser_hpp */
