#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// numbers is order from 0 - 99
// rotation: right or left
// current: 11, R8, right by 8, current = 19
// current: 19, L19, left by 19, current = 0
// circular dial - past 0 - then it goes to 99, past 99 - goes to 0
// password: # of times current position is 0.
// sample input
/*
L68
L30
R48
L5
R60
L55
L1
L99
R14
L82
*/
// starting position 50

// Safe has a dial start position 0
// Safe has a dial end position 99
// Safe dial starts at position 50
// Safe has a ApplyRotation
// Safe has a GetCurrentPosition
// Safe has a read input function

class Safe
{
   public:
    Safe(const uint8_t& inStartPosition, const uint8_t& inEndPosition,
         const uint8_t& inDialPosition)
        : startPosition(inStartPosition),
          endPosition(inEndPosition),
          dialPosition(inDialPosition)
    {
    }

    uint8_t GetDialPosition()
    {
        return dialPosition;
    }

    void ApplyRotation()
    {
    }

   private:
    uint8_t startPosition{0};
    uint8_t endPosition{0};
    uint8_t dialPosition{0};
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

void ParseInput()
{
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

    uint8_t startPosition{0};
    uint8_t endPosition{99};
    uint8_t dialPosition{50};

    // instantiate
    Safe safeInstance(startPosition, endPosition, dialPosition);

    cout << "Hello, from aoc2025_day1!\n";
    cout << "Dial position: " << safeInstance.GetDialPosition() << endl;
}