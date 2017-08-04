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

namespace XML
{
    class Element
    {
    public:
        using AttributeMap = std::map<std::string, std::string>;
        using ChildElements = std::vector<Element>;
        
        Element() = default;
        Element(const std::string& name);
        Element(const Element& rhs) = default;
        Element(Element&& rhs) = default;
        Element& operator=(const Element& rhs) = default;
        Element& operator=(Element&& rhs) = default;
        ~Element() = default;
        
        std::string getName() const;
        std::string getAttribute(const std::string& key);
        std::string getAttribute(const std::string&& key);
        AttributeMap getAttributes() const;
        std::vector<Element> getChildElements() const;
        
        void addAttribute(std::pair<std::string, std::string> attribute);
        void addChildElement(const Element& childElement);
        
    private:
        std::string myName;
        AttributeMap myAttributes;
        std::vector<Element> myChildElements;
    };
}

#endif /* XmlParser_hpp */
