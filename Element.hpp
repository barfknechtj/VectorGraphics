//
//  Element.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/6/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef Element_hpp
#define Element_hpp

#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <memory>

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
        bool hasChildren() const;
        
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
}

#endif /* Element_hpp */
