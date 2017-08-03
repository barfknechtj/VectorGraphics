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
    using attributeMap = std::map<std::string, std::string>;
    
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
        
        std::string getName() const;
        std::string getAttribute(std::string& key);
        attributeMap getAttributes() const;
        std::vector<Element> getChildElements() const;
        
        // TODO: addAttribute, addChildElement
        
    private:
        std::string myName;
        attributeMap myAttributes;
        std::vector<Element> myChildElements;
    };
}


#endif /* XmlParser_hpp */
