#include "ProductIdValidator.h"

#include <iostream>

ProductIdValidator::ProductIdValidator(const std::vector<Range> ranges)
    : rangeInput(std::move(ranges))
{
}

bool ProductIdValidator::IsRepeatedTwice(const uint32_t& pIdInt) const
{
    bool result{false};
    std::string pId = std::to_string(pIdInt);
    size_t strSize = pId.size();
    if ((strSize % 2) == 0)
    {
        // check palindrome / repeating
        size_t halfIndex = strSize / 2;
        result = (pId.substr(0, halfIndex) == pId.substr(halfIndex));
    }
    return result;
}

bool ProductIdValidator::ContainsRepeatedChunks(const uint32_t& pIdInt) const
{
    bool result{false};
    std::string pId = std::to_string(pIdInt);
    size_t strSize = pId.size();

    // Try all possible substring lengths from 1 to n/2
    for (size_t len = 1; len <= strSize / 2; ++len)
    {
        if (strSize % len != 0) continue;  // substring must divide total length

        std::string pattern = pId.substr(0, len);
        bool allMatch = true;

        // Check every chunk
        for (size_t i = len; i < strSize; i += len)
        {
            if (pId.substr(i, len) != pattern)
            {
                allMatch = false;
                break;  // early exit if mismatch
            }
        }

        if (allMatch)
        {
            result = true;  // repeated pattern found
            break;
        }
    }

    return result;
}

uint64_t ProductIdValidator::CalculateSumOfInvalidIdPart1()
{
    uint64_t result{0};
    const std::vector<uint32_t> invalidIdList = FindInvalidIdsPart1();

    for (const auto& id : invalidIdList)
    {
        result += id;
    }
    return result;
}

uint64_t ProductIdValidator::CalculateSumOfInvalidIdPart2()
{
    uint64_t result{0};
    const std::vector<uint32_t> invalidIdList = FindInvalidIdsPart2();

    for (const auto& id : invalidIdList)
    {
        result += id;
    }
    return result;
}

std::vector<uint32_t> ProductIdValidator::FindInvalidIdsPart1() const
{
    std::vector<uint32_t> result{};
    for (const auto& range : rangeInput)
    {
        for (auto rangeIter = range.begin; rangeIter <= range.end; ++rangeIter)
        {
            if (IsRepeatedTwice(rangeIter))
            {
                result.emplace_back(rangeIter);
            }
        }
    }
    return result;
}

std::vector<uint32_t> ProductIdValidator::FindInvalidIdsPart2() const
{
    std::vector<uint32_t> result{};
    for (const auto& range : rangeInput)
    {
        for (auto rangeIter = range.begin; rangeIter <= range.end; ++rangeIter)
        {
            if (ContainsRepeatedChunks(rangeIter))
            {
                result.emplace_back(rangeIter);
            }
        }
    }
    return result;
}