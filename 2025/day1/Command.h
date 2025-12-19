#pragma once

#include <cstddef>
#include <string>

/**
 * @brief represents command to the dial. It has a direction (L, R) and a
 * magnitude (int)
 *
 */
struct Command
{
    char direction{};  // 'L' or 'R'
    size_t magnitude{};
};

/**
 * @brief Converts a string representing command to a known type
 *
 * @param[in] line command string
 * @return Command with direction and magnitude
 */
Command ParseCommand(const std::string& line);