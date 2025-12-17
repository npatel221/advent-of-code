#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
class Safe
{
   public:
    Safe(const uint8_t& dialStartingPosition)
        : dialPosition(dialStartingPosition)
    {
    }

    size_t GetPassword() const
    {
        return password;
    }

    void ApplyRotation(char direction, size_t magnitude, bool debug)
    {
        int prevPosition = dialPosition;

        // precompute magnitude modulo range
        int effectiveMove = static_cast<int>(magnitude % dialRange);

        if (direction == 'R')
        {
            dialPosition = (dialPosition + effectiveMove) % dialRange;
        }
        else  // 'L' move
        {
            dialPosition =
                (dialPosition + dialRange - effectiveMove) % dialRange;
        }

        // password is # of times dial is left at 0
        if (dialPosition == passwordTarget)
        {
            ++password;
        }

        if (debug)
        {
            std::cout << "current pos: " << (int)prevPosition
                      << "\t\tcommand: " << direction << (int)magnitude
                      << "\t\tfinal pos: " << (int)dialPosition << std::endl;
        }
    }

   private:
    const int startPosition{0};
    const int endPosition{99};
    const int dialRange = (endPosition - startPosition) + 1;  // 100
    const int passwordTarget{0};

    int dialPosition{0};
    size_t password{0};
};

/**
 * @brief Check whether a file path is valid and its of file type
 *
 * @param[in] filePath string file path to check
 * @return true valid
 * @return false otherwise
 */
bool IsFilePathValid(const std::string& filePath)
{
    std::filesystem::path path(filePath);
    bool result = (std::filesystem::exists(path) &&
                   std::filesystem::is_regular_file(path));
    return result;
}

std::vector<std::string> ReadInputFile(const std::string& filePath)
{
    std::vector<std::string> result{};
    bool validPath = IsFilePathValid(filePath);
    if (validPath)
    {
        std::ifstream file(filePath);
        if (file.is_open())
        {
            std::string line;
            // parse line by line
            while (getline(file, line))
            {
                result.emplace_back(line);
            }
        }
    }
    return result;
}

struct Command
{
    char direction;  // 'L' or 'R'
    size_t magnitude;
};

Command ParseCommand(const std::string& line)
{
    Command result{};
    result.direction = line.at(0);
    result.magnitude = std::stoul(line.substr(1));
    return result;
}

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
    Safe safeInstance(dialPosition);

    bool debugFlag = true;
    for (const std::string& line : fileContent)
    {
        auto [direction, magnitude] = ParseCommand(line);
        safeInstance.ApplyRotation(direction, magnitude, debugFlag);
    }
    std::cout << "Password: " << safeInstance.GetPassword() << std::endl;
}