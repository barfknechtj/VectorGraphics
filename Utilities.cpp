#include "Utilities.h"

std::string boolToStr(bool& b)
{
    return b ? "true" : "false";
}

std::string boolToStr(bool&& b)
{
    return b ? "true" : "false";
}
