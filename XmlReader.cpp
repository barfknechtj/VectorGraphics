//
//  XmlReader.cpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/6/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#include "XmlReader.hpp"

void Xml::Reader::_pushElementTagToStack(const std::string& elementName)
{
    myElementStack.push(elementName);
}

void Xml::Reader::_popElementTagFromStack()
{
    myElementStack.pop();
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
            throw UnexpectedEOF();
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
        throw InvalidXmlEndTag();
    }
    
    return root;
}
