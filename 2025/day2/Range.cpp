#include "Range.h"

#include <charconv>

Range ParseRange(const std::string& rangeStr)
{
    Range result{};

    size_t pos = rangeStr.find('-');
    std::string left = rangeStr.substr(0, pos);
    std::string right = rangeStr.substr(pos + 1);

    result.begin = std::stoull(left);
    result.end = std::stoull(right);
    return result;
}