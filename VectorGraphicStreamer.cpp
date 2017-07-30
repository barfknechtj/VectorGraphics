#include "VectorGraphicStreamer.h"
#include "Parse.h"
#include "Point.h"
#include <iostream>
#include <sstream>

namespace
{
    bool getAttribute(std::istream& xml,
                      std::string& name,
                      std::string& value)
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
    
    bool getElement(std::istream& xml,
                    std::string& name)
    {
        // eat leftovers from any previous element
        Parse::eat(xml, " \n\t\r/>");
        
        char c{};
        if (! xml.get(c))
        {
            return false;
        }
        
        if (c != '<')
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
    
    int toInt(const std::string& value)
    {
        int v{};
        std::stringstream ss(value);
        ss >> v;
        return v;
    }
}

namespace VG
{
    
    // Assumes only one vector graphic in XML file
    VectorGraphic VectorGraphicStreamer::fromXml(std::istream& xml)
    {
        xml.exceptions(std::ios_base::eofbit | std::ios_base::failbit | std::ios_base::badbit);
        
        // Get the first XML element in the input. It should be "VectorGraphic"
        
        std::string name;
        
        if (! getElement(xml, name))
        {
            throw std::runtime_error{"Invalid XML"};
        }
        
        if (name != "VectorGraphic")
        {
            throw std::runtime_error{"Invalid XML: element tag not VectorGraphic"};
        }
        
        // Get attributes for VectorGraphic
        
        std::string value;
        VG::VectorGraphic graphic;
        
        while (getAttribute(xml, name, value))
        {
            if (name == "closed")
            {
                if (value == "true")
                {
                    graphic.closeShape();
                }
                else if (value == "false")
                {
                    graphic.openShape();
                }
                else
                {
                    std::stringstream sstr;
                    sstr << "Bad value for \"closed\" attribute: " << value;
                    throw std::runtime_error{sstr.str().c_str()};
                }
            }
        }
        
        // Now get all the sub-elements of VectorGraphic (Points)
        
        while (getElement(xml, name))
        {
            if (name == "Point")
            {
                bool foundX{false};
                bool foundY{false};
                int x{0};
                int y{0};
                while (getAttribute(xml, name, value))
                {
                    if (name == "x")
                    {
                        foundX = true;
                        x = toInt(value);
                    }
                    else if (name == "y")
                    {
                        foundY = true;
                        y = toInt(value);
                    }
                }
                
                if (foundX && foundY)
                {
                    graphic.addPoint(VG::Point(x, y));
                }
            }
            else if (name == "/VectorGraphic")
            {
                break;
            }
        }
        
        return graphic;
    }
    
    void VectorGraphicStreamer::toXml(const VectorGraphic& vg,
                                      std::ostream& os)
    {
        os << "<VectorGraphic closed=";
        if (vg.isClosed())
        {
            os << "\"true\">" << std::endl;
        }
        else
        {
            os << "\"false\">" << std::endl;
        }
        
        for (auto i = 0; i < vg.getPointCount(); ++i)
        {
            auto p = vg.getPoint(i);
            os << "<Point x=\"" << p.getX() << "\" y=\"" << p.getY() << "\"/>" << std::endl;
        }
        
        os << "/VectorGraphic>";
    }
    
}
