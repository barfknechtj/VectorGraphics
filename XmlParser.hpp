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
#include <map>
#include <vector>
#include "VectorGraphic.h"
#include "Parse.h"
#include <iostream>
#include <stack>

bool getElement(std::istream& xml, std::string& name);
bool getAttribute(std::istream& xml, std::string& name, std::string& value);

namespace Xml
{
    using AttributeMap = std::map<std::string, std::string>;
    
    class Element
    {
    public:
        Element() = default;
        Element(const std::string& name);
        Element(const Element& rhs) = default;
        Element(Element&& rhs) = default;
        Element& operator=(const Element& rhs) = default;
        Element& operator=(Element&& rhs) = default;
        ~Element() = default;
        
        std::string const& getName() const;
        std::string getAttribute(const std::string& key) const;
        std::string getAttribute(const std::string&& key) const;
        AttributeMap const& getAttributes() const;
        std::vector<std::shared_ptr<Element>> const& getChildElements() const;
        
        void setName(const std::string& name);
        void addAttribute(std::string key, std::string value);
        std::shared_ptr<Element> addChildElement(std::string childElementName);
        
    private:
        std::string myName;
        AttributeMap myAttributes;
        std::vector<std::shared_ptr<Element>> myChildElements;
    };
    
    using ChildElements = std::vector<std::shared_ptr<Element>>;
    using HElement = std::shared_ptr<Element>;
    
    class Reader
    {
    public:
        Reader() = default;
        ~Reader() = default;
        
        void pushElementTagToStack(const std::string& elementName);
        void popElementTagFromStack();
        bool checkForEndTag(std::istream& xml);
        bool checkForSingleLineEndTag(std::istream& xml);
        std::string verifyEndTag(std::istream& xml);
        void processElementsUntilEndTag(std::istream& srcXml,
                                        std::shared_ptr<Element> parentElement,
                                        std::string& endTag);
        std::shared_ptr<Element> loadXml(std::istream& srcXml);
        
    private:
        std::stack<std::string> myElementStack;
    };
    
}

#endif /* XmlParser_hpp */
