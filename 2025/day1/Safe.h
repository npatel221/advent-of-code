#include <cstddef>
#include <cstdint>

class Safe
{
   public:
    explicit Safe(const uint8_t& dialStartingPosition);

    /**
     * @brief num of times the dial points to passwordTarget
     *
     * @return size_t
     */
    size_t GetPassword() const;

    /**
     * @brief Perform rotation on the safe and move the dial into a position
     *
     * @param[in] direction 'L' or 'R'
     * @param[in] magnitude how much to move the dial by
     * @param[in] debug flag for print out
     * @param[in] countEveryZero flag to count when dial at 0 or not
     */
    void ApplyRotation(char direction, size_t magnitude, bool debug = false,
                       bool countEveryZero = false);

    /**
     * @brief reset the safe and put it in init position
     *
     */
    void Reset();

   private:
    /// @brief lowest num on safe where dial can begin
    const int startPosition{0};

    /// @brief highest num on safe where dial can end
    const int endPosition{99};

    /// @brief range for the dial in increments
    const int dialRange = (endPosition - startPosition) + 1;

    /// @brief matching key where password is
    const int passwordTarget{0};

    /// @brief starting position of dial when beginning puzzle
    const int dialBeginPosition{};

    /// @brief current position of the dial
    int dialPosition{};

    /// @brief num of times the dial points to passwordTarget
    size_t password{0};

    /**
     * @brief perform tick on the dial (left by 1 or right by 1)
     *
     * @param[in] step how many ticks to move by
     */
    void IncrementDial(int step);
};
