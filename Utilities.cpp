#include "Utilities.h"
#include "Parse.h"
#include "Point.h"
#include <iostream>
#include <sstream>

namespace
{
    int toInt(const std::string& value)
    {
        int v{};
        std::stringstream ss(value);
        ss >> v;
        return v;
    }
}
