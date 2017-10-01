//
//  XmlWriter.hpp
//  Assignment2
//
//  Created by Jared Barfknecht on 8/6/17.
//  Copyright © 2017 Jared Barfknecht. All rights reserved.
//

#ifndef XmlWriter_hpp
#define XmlWriter_hpp

#include <stdio.h>
#include <iostream>
#include "Element.hpp"

namespace Xml
{
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


#endif /* XmlWriter_hpp */
