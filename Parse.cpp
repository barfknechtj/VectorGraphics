#include "Parse.h"
#include <iostream>

namespace Parse
{
    void trim(std::string& sourceString,
              std::string const& trimmables)
    {
        auto first = sourceString.find_first_not_of(trimmables);
        if (first == std::string::npos)
        {
            sourceString.clear();
            return;
        }
        sourceString = sourceString.substr(first);
        
        auto last = sourceString.find_last_not_of(trimmables);
        sourceString = sourceString.substr(0, last + 1);
    }
    
    void eat(std::istream& sourceStream,
             const std::string& edibles)
    {
        int nextChar{EOF};
        while ((nextChar = sourceStream.peek()) != EOF)
        {
            if (edibles.find(nextChar) != std::string::npos)
            {
                sourceStream.ignore();
            }
            else
            {
                break;
            }
        }
    }
}