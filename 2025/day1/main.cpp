#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#include "Command.h"
#include "FileUtils.h"
#include "Safe.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Failed to provide input file path: ./aoc2025_day01 "
                     "<input_file>.txt\n";
        return 1;
    }

    std::string inputFilePath = argv[1];

    std::vector<std::string> fileContent =
        ReadInputFile(inputFilePath);  // read file content

    uint8_t dialPosition{50};

    // instantiate
    Safe safe(dialPosition);

    // Part #1
    bool debugFlag = false;
    bool countEveryZero = false;
    for (const std::string& line : fileContent)
    {
        auto [direction, magnitude] = ParseCommand(line);
        safe.ApplyRotation(direction, magnitude, debugFlag, countEveryZero);
    }
    std::cout << "Password #1: " << safe.GetPassword() << std::endl;

    // Part #1
    safe.Reset();  // put it back to where it started
    debugFlag = false;
    countEveryZero = true;
    for (const std::string& line : fileContent)
    {
        auto [direction, magnitude] = ParseCommand(line);
        safe.ApplyRotation(direction, magnitude, debugFlag, countEveryZero);
    }
    std::cout << "Password #2: " << safe.GetPassword() << std::endl;
}