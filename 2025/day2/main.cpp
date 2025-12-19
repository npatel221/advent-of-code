#include <iostream>

#include "FileUtils.h"
#include "Range.h"

int main(int argc, char* argv[])
{
    std::cout << "Hello World: Day 02" << std::endl;
    if (argc < 2)
    {
        std::cerr << "Failed to provide input file path: ./aoc2025_day02 "
                     "<input_file>.txt\n";
        return 1;
    }

    std::string inputFilePath = argv[1];

    const char lineendDelimeter = ',';
    std::vector<std::string> fileContent =
        ReadInputFile(inputFilePath, lineendDelimeter);  // read file content

    // Part #1
    for (const auto& line : fileContent)
    {
        auto [begin, end] = ParseRange(line);
        std::cout << "Begin: " << begin << "\tEnd: " << end << std::endl;
    }

    // Part #2
}