#pragma once

#include <cstdint>
#include <string>

struct Range
{
    uint32_t begin;
    uint32_t end;
};

Range ParseRange(const std::string& line);