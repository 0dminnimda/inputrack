#include "mouse.h"

#if defined(_WIN32) || defined(WIN32) || defined(MS_WINDOWS) || defined(_MSC_VER)
#include <windows.h>

bool positions_are_equal(const Position *a, const Position *b)
{
    return (a != NULL && b != NULL && a->x == b->x && a->y == b->y);
}

Position get_position()
{
    POINT p = {0, 0};
    GetCursorPos(&p);
    return (Position) {p.x, p.y};
}

#else
#error "Unknown compiler"
#endif

