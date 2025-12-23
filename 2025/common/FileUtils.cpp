#include "FileUtils.h"

#include <filesystem>
#include <fstream>

bool IsFilePathValid(const std::string& filePath)
{
    std::filesystem::path path(filePath);
    return std::filesystem::exists(path) &&
           std::filesystem::is_regular_file(path);
}

std::vector<std::string> ReadInputFile(const std::string& filePath)
{
    return ReadInputFile(filePath, '\n');
}

std::vector<std::string> ReadInputFile(const std::string& filePath,
                                       const char& delimiter)
{
    std::vector<std::string> result{};
    if (IsFilePathValid(filePath))
    {
        std::ifstream file(filePath);
        std::string line;
        while (getline(file, line, delimiter))
        {
            result.emplace_back(std::move(line));
        }
    }
    return result;
}
