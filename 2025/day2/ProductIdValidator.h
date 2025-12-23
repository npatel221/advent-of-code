#pragma once

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

    bool IsRepeatedTwice(const uint32_t& pIdInt) const;
    bool ContainsRepeatedChunks(const uint32_t& pIdInt) const;

    std::vector<uint32_t> FindInvalidIdsPart1() const;
    std::vector<uint32_t> FindInvalidIdsPart2() const;
};