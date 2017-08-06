//
//  XmlParser.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/2/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "XmlParser.hpp"
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

//------------------------------------------------------------------------
Xml::Element::Element(const std::string& name)
    : myName(name)
{
}

std::string const& Xml::Element::getName() const
{
    return myName;
}

std::string Xml::Element::getAttribute(const std::string& key) const
{
    return myAttributes.at(key);
}

std::string Xml::Element::getAttribute(const std::string&& key) const
{
    return myAttributes.at(key);
}

Xml::AttributeMap const& Xml::Element::getAttributes() const
{
    return myAttributes;
}

Xml::ChildElements const& Xml::Element::getChildElements() const
{
    return myChildElements;
}

void Xml::Element::setName(const std::string& name)
{
    myName = name;
}

void Xml::Element::addAttribute(std::string key, std::string value)
{
    myAttributes.insert(std::make_pair(key, value));
}

std::shared_ptr<Xml::Element> Xml::Element::addChildElement(std::string childElementName)
{
    auto childElement = std::make_shared<Element>(childElementName);
    myChildElements.push_back(childElement);
    return childElement;
}

//------------------------------------------------------------------------
void Xml::Reader::_pushElementTagToStack(const std::string& elementName)
{
    myElementStack.push(elementName);
}

void Xml::Reader::_popElementTagFromStack()
{
    myElementStack.pop();
}

bool Xml::Reader::_checkForEndTag(std::istream& xml)
{
    return (xml.peek() == '/');
}

bool Xml::Reader::_checkForSingleLineEndTag(std::istream& xml)
{
    return (xml.peek() == '/');
}

std::string Xml::Reader::_verifyEndTag(std::istream& xml)
{
    std::string endTag;
    char c{};
    Parse::eat(xml, " /");
    xml.get(c);
    while (c != '>')
    {
        endTag.push_back(c);
        xml.get(c);
    }
    
    Parse::trim(endTag);
    _popElementTagFromStack();
    return endTag;
}

void Xml::Reader::_processElementsUntilEndTag(std::istream& srcXml,
                                             std::shared_ptr<Element> parentElement,
                                             std::string& endTagOnStack)
{
    std::string newEndTag;

    while(endTagOnStack != newEndTag)
    {
        if (srcXml.peek() == EOF)
        {
            throw std::runtime_error{"Invalid XML: Missing end tag"};
        }
        
        // check for and verify endTag on new line
        Parse::eat(srcXml, " <");
        if(srcXml.peek() == '/')
        {
            newEndTag = _verifyEndTag(srcXml);
            Parse::eat(srcXml, " \n\t\r><");
        }
        // check for and remove comment lines
        else if(srcXml.peek() == '!')
        {
            char c{};
            while (c != '>')
            {
                srcXml.get(c);
            }
            Parse::eat(srcXml, " \n\t\r><");
            
        }
        // process any other line type
        else
        {
            std::string elementName;
            std::string attributeName;
            std::string value;
            
            Parse::eat(srcXml);
            if(getElement(srcXml, elementName))
            {
                _pushElementTagToStack(elementName);
                auto childElement = parentElement->addChildElement(elementName);
                while(getAttribute(srcXml, attributeName, value))
                {
                    childElement->addAttribute(attributeName, value);
                }
                
                // check for single line end tag
                if(srcXml.peek() == '/')
                {
                    Parse::eat(srcXml, " \n\t\r/>");
                    _popElementTagFromStack();
                }
                
                // check for nested elements
                else
                {
                    Parse::eat(srcXml, " \n\t\r/>");
                    _processElementsUntilEndTag(srcXml, childElement, myElementStack.top());
                }
            }
        }
    }
}

// assumes there is only one root element in Xml
std::shared_ptr<Xml::Element> Xml::Reader::loadXml(std::istream& srcXml)
{
    std::shared_ptr<Xml::Element> root{new Element};
    std::string elementName;
    std::string attributeName;
    std::string value;
    
    // process root
    Parse::eat(srcXml, " \n\t\r/<");
    if(getElement(srcXml, elementName))
    {
        root->setName(elementName);
        _pushElementTagToStack(elementName);
    }
    
    while(getAttribute(srcXml, attributeName, value))
    {
        root->addAttribute(attributeName, value);
    }
    
    if(srcXml.peek() == '/')
    {
       _popElementTagFromStack();
    }
    else
    {
        Parse::eat(srcXml, " \n\t\r/>");
        _processElementsUntilEndTag(srcXml, root, elementName);
    }
    
    // all end tags should be popped
    if(myElementStack.size())
    {
        throw std::runtime_error{"Invalid XML: Incorrect number of end tags"};
    }
    
    return root;
}

