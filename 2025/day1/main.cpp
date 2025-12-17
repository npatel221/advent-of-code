#include <cstdint>
#include <filesystem>
#include <fstream>
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

    bool debugFlag = true;
    for (const std::string& line : fileContent)
    {
        auto [direction, magnitude] = ParseCommand(line);
        safe.ApplyRotation(direction, magnitude, debugFlag);
    }
    std::cout << "Password: " << safe.GetPassword() << std::endl;
}