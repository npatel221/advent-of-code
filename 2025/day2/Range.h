#pragma once

#include <string>

struct Range
{
    size_t begin;
    size_t end;
};

Range ParseRange(const std::string& line);