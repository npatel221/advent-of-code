#pragma once

#include <vector>

#include "Range.h"

class ProductIdValidator
{
   public:
    explicit ProductIdValidator(const std::vector<Range> ranges);

    uint64_t SumOfInvalidIdPart1();

   private:
    std::vector<Range> rangeInput{};

    bool IsRepeatedTwice(const uint32_t& pIdInt);
    std::vector<uint32_t> FindInvalidIdPart1();
};