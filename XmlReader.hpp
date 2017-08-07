//
//  XmlReader.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/6/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef XmlReader_hpp
#define XmlReader_hpp

#include <stdio.h>
#include <stack>
#include <memory>
#include <string>
#include <iostream>
#include "Element.hpp"
#include "Parse.h"
#include "XmlParse.hpp"

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
}

#endif /* XmlReader_hpp */
