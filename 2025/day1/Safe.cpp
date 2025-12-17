#include "Safe.h"

#include <iostream>

Safe::Safe(const uint8_t& dialStartingPosition)
    : dialPosition(dialStartingPosition)
{
}

size_t Safe::GetPassword() const
{
    return password;
}

void Safe::ApplyRotation(char direction, size_t magnitude, bool debug)
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
        dialPosition = (dialPosition + dialRange - effectiveMove) % dialRange;
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
