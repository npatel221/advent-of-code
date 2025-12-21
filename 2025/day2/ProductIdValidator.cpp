#include "ProductIdValidator.h"

#include <iostream>

ProductIdValidator::ProductIdValidator(const std::vector<Range> ranges)
    : rangeInput(std::move(ranges))
{
}

bool ProductIdValidator::IsRepeatedTwice(const uint32_t& pIdInt)
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

std::vector<uint32_t> ProductIdValidator::FindInvalidIdPart1()
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

uint64_t ProductIdValidator::SumOfInvalidIdPart1()
{
    uint64_t result{0};
    const std::vector<uint32_t> invalidIdList = FindInvalidIdPart1();

    for (const auto& id : invalidIdList)
    {
        result += id;
    }
    return result;
}