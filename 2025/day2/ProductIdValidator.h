#pragma once

#include <functional>
#include <vector>

#include "Range.h"

class ProductIdValidator
{
   public:
    explicit ProductIdValidator(const std::vector<Range> ranges);

    uint64_t CalculateSumOfInvalidIdPart1();
    uint64_t CalculateSumOfInvalidIdPart2();

   private:
    std::vector<Range> rangeInput{};

    bool IsRepeatedTwice(const uint32_t& pIdInt);
    bool ContainsRepeatedChunks(const uint32_t& pIdInt);

    template <typename Rule>
    std::vector<uint32_t> FindInvalidIds(Rule rule) const
    {
        std::vector<uint32_t> result{};
        for (const auto& range : rangeInput)
        {
            for (auto rangeIter = range.begin; rangeIter <= range.end;
                 ++rangeIter)
            {
                if (rule(rangeIter))
                {
                    result.emplace_back(rangeIter);
                }
            }
        }
        return result;
    }

    template <typename Rule>
    uint64_t CalculateSum(Rule rule) const
    {
        uint64_t result{0};
        const std::vector<uint32_t> invalidIdList = FindInvalidIds(rule);

        for (const auto& id : invalidIdList)
        {
            result += id;
        }
        return result;
    }
};