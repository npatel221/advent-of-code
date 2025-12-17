#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
class Safe
{
   public:
    Safe(const int& inStartPosition, const int& inEndPosition,
         const int& inDialPosition, const int& inPasswordTarget)
        : startPosition(inStartPosition),
          endPosition(inEndPosition),
          dialPosition(inDialPosition)
    {
        dialRange = (endPosition - startPosition) + 1;
    }

    size_t GetPassword()
    {
        return password;
    }

    bool ApplyRotation(const std::string& command)
    {
        bool result{false};
        char direction;
        size_t magnitude;

        if (!command.empty())
        {
            // parse from string
            direction = command.at(0);
            magnitude = std::stoul(command.substr(1));

            // check valid inputs prior to application
            if ((direction == 'L') || (direction == 'R'))
            {
                result = true;
            }
        }

        if (result)
        {
            std::cout << "current pos: " << (int)dialPosition;

            if (direction == 'R')
            {
                dialPosition = (dialPosition + magnitude) % dialRange;
            }
            else
            {
                dialPosition =
                    (dialPosition + dialRange - (magnitude % dialRange)) %
                    dialRange;
            }

            // password is # of times dial is left at 0
            if (dialPosition == passwordTarget)
            {
                ++password;
            }

            std::cout << "\t\tcommand: " << direction << (int)magnitude
                      << "\t\tfinal pos: " << (int)dialPosition << "\n";
        }
        return result;
    }

   private:
    int startPosition{0};
    int endPosition{0};
    int dialPosition{0};
    int dialRange{0};
    int passwordTarget{0};
    size_t password{0};
};

using namespace std;

/**
 * @brief Check whether a file path is valid and its of file type
 *
 * @param[in] filePath string file path to check
 * @return true valid
 * @return false otherwise
 */
bool IsFilePathValid(const string& filePath)
{
    filesystem::path path(filePath);
    bool result =
        (filesystem::exists(path) && filesystem::is_regular_file(path));
    return result;
}

bool OpenFileAndReadAsString(const string& filePath, vector<string>& lines)
{
    // check valid path and empty vector before populating
    bool result = IsFilePathValid(filePath) && (lines.empty());

    ifstream file;
    // only attempt opening if previous checks passed
    if (result)
    {
        file.open(filePath);
        result &= file.is_open();
    }

    if (result)
    {
        string line;
        // parse line by line
        while (getline(file, line))
        {
            lines.emplace_back(line);
        }
    }
    return result;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cerr << "Failed to provide input file path: ./aoc2025_day01 "
                "<input_file>.txt\n";
        return 1;
    }

    string inputFilePath = argv[1];
    // read file content
    vector<string> fileContent{};
    bool result = OpenFileAndReadAsString(inputFilePath, fileContent);

    int startPosition{0};
    int endPosition{99};
    int dialPosition{50};
    int passwordTarget{0};

    // instantiate
    Safe safeInstance(startPosition, endPosition, dialPosition, passwordTarget);
    if (result)
    {
        for (const string& line : fileContent)
        {
            if (safeInstance.ApplyRotation(line) == false)
            {
                result = false;
                break;
            }
        }
    }

    if (result)
    {
        cout << "Password: " << safeInstance.GetPassword() << endl;
    }
    else
    {
        cerr << "Apply rotation failed" << endl;
    }
}