#pragma once

#include <cstdint>
#include <string>

/**
 * @brief represents the input from txt file
 *
 */
struct Range
{
    /// @brief start of the range
    uint32_t begin;

    /// @brief end of range (inclusive)
    uint32_t end;
};

/**
 * @brief Converts raw string into start and end struct
 *
 * @param[in] line raw string
 * @return Range struct
 */
Range ParseRange(const std::string& line);