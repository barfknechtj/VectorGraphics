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

namespace Xml
{
    class Reader
    {
    public:
        Reader() = default;
        ~Reader() = default;
        
        std::shared_ptr<Element> loadXml(std::istream& srcXml);
        
    private:
        std::stack<std::string> myElementStack;
        
        void _pushElementTagToStack(const std::string& elementName);
        void _popElementTagFromStack();
        bool _checkForEndTag(std::istream& xml);
        bool _checkForSingleLineEndTag(std::istream& xml);
        std::string _verifyEndTag(std::istream& xml);
        void _processElementsUntilEndTag(std::istream& srcXml,
                                        std::shared_ptr<Element> parentElement,
                                        std::string& endTag);
    };
    
    class Writer
    {
    public:
        Writer() = default;
        ~Writer() = default;
        
        std::ostream& writeXml(Xml::HElement element, std::ostream& os);
        
        std::ostream& writeName(Xml::HElement element, std::ostream& os);
        std::ostream& writeAttributes(Xml::HElement element, std::ostream& os);
        std::ostream& writeChildElements(Xml::HElement element, std::ostream& os);
        std::ostream& writeNewLineEndTag(Xml::HElement element, std::ostream& os);
        
    };
    
}

#endif /* XmlParser_hpp */
