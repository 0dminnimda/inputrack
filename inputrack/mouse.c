#include "mouse.h"

#if defined(_WIN32) || defined(WIN32) || defined(MS_WINDOWS) || defined(_MSC_VER)
#include <windows.h>

bool positions_are_equal(const Position *a, const Position *b)
{
    assert(a && b);
    return a->x == b->x && a->y == b->y;
}

// also see: https://docs.microsoft.com/en-us/windows/win32/inputdev/user-input

Position get_position()
{
    POINT p = {0, 0};
    GetCursorPos(&p);
    return (Position) {p.x, p.y};
}

// TODO: implement timer https://stackoverflow.com/questions/2150291/how-do-i-measure-a-time-interval-in-c

#else
#error "Unknown compiler"
#endif

