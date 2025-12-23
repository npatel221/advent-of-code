#pragma once

#include <vector>

#include "Range.h"

class ProductIdValidator
{
   public:
    /**
     * @brief Construct a new Product Id Validator object
     *
     * @param[in] ranges start-begin and it will take ownership
     */
    explicit ProductIdValidator(const std::vector<Range> ranges);

    /**
     * @brief Calculates sum of invalid Id's where its repeated twice
     *
     * @return uint64_t value
     */
    uint64_t CalculateSumOfInvalidIdPart1();

    /**
     * @brief Calculates sum of invalid id's where there is at least >= repeated
     * chunks
     *
     * @return uint64_t value
     */
    uint64_t CalculateSumOfInvalidIdPart2();

   private:
    /// @brief input
    std::vector<Range> rangeInput{};

    /**
     * @brief Check if its palindrome (repeated twice)
     *
     * @param[in] pIdInt uint32 value
     * @return true repeated
     * @return false non repeated
     */
    bool IsRepeatedTwice(const uint32_t& pIdInt) const;

    /**
     * @brief Check if its repeated chunks >= 2
     *
     * @param[in] pIdInt uint32 value
     * @return true repeated
     * @return false non repeated
     */
    bool ContainsRepeatedChunks(const uint32_t& pIdInt) const;

    /**
     * @brief Returns a list of invalid id's for part #1
     *
     * @return std::vector<uint32_t>
     */
    std::vector<uint32_t> FindInvalidIdsPart1() const;

    /**
     * @brief Returns a list of invalid id's for part #2
     *
     * @return std::vector<uint32_t>
     */
    std::vector<uint32_t> FindInvalidIdsPart2() const;
};