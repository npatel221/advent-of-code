#include <iostream>
#include <vector>

#include "FileUtils.h"
#include "ProductIdValidator.h"
#include "Range.h"

int main(int argc, char* argv[])
{
    std::cout << "--- Day 2: Gift Shop ---" << std::endl;
    if (argc < 2)
    {
        std::cerr << "Failed to provide input file path: ./aoc2025_day02 "
                     "<input_file>.txt\n";
        return 1;
    }

    std::string inputFilePath = argv[1];

    // read file content
    const char lineendDelimeter = ',';
    std::vector<std::string> fileContent =
        ReadInputFile(inputFilePath, lineendDelimeter);

    // extact input from str
    std::vector<Range> rangeInput{};
    for (const auto& line : fileContent)
    {
        rangeInput.emplace_back(ParseRange(line));
    }

    ProductIdValidator productIdValidator(std::move(rangeInput));

    std::cout << "Part #1: " << productIdValidator.SumOfInvalidIdPart1()
              << std::endl;

    std::cout << "Part #2: " << productIdValidator.SumOfInvalidIdPart2()
              << std::endl;
}