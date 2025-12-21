#include "Range.h"

#include <charconv>

Range ParseRange(const std::string& rangeStr)
{
    Range result{};

    size_t pos = rangeStr.find('-');
    std::string left = rangeStr.substr(0, pos);
    std::string right = rangeStr.substr(pos + 1);

    result.begin = static_cast<uint32_t>(std::stoul(left));
    result.end = static_cast<uint32_t>(std::stoul(right));
    return result;
}