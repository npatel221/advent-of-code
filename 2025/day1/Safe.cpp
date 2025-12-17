#include "Safe.h"

#include <iostream>

Safe::Safe(const uint8_t& dialStartingPosition)
    : dialBeginPosition(dialStartingPosition), dialPosition(dialBeginPosition)
{
}

size_t Safe::GetPassword() const
{
    return password;
}

void Safe::IncrementDial(int step)
{
    dialPosition = (dialPosition + step + dialRange) % dialRange;
}

void Safe::ApplyRotation(char direction, size_t magnitude, bool debug,
                         bool countEveryZero)
{
    int prevPosition = dialPosition;  // cache old pos

    int step = (direction == 'R') ? 1 : -1;  // move forward or backward

    // brute force
    for (size_t i = 0; i < magnitude; ++i)
    {
        IncrementDial(step);

        // check if pos = 0
        if ((countEveryZero) && (dialPosition == passwordTarget))
        {
            ++password;
        }
    }

    // only increment when dial stopped at 0
    if ((!countEveryZero) && (dialPosition == passwordTarget))
    {
        ++password;
    }

    if (debug)
        std::cout << "current pos: " << prevPosition
                  << "\t\tcommand: " << direction << magnitude
                  << "\t\tfinal pos: " << dialPosition << std::endl;
}

void Safe::Reset()
{
    dialPosition = dialBeginPosition;  // put dial back to original position
                                       // when it started
    password = 0;                      // reset counter
}