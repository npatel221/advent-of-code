#include "Command.h"

#include <string>

Command ParseCommand(const std::string& line)
{
    Command result{};
    result.direction = line.at(0);                  // 1st char
    result.magnitude = std::stoul(line.substr(1));  // remaining items
    return result;
}
