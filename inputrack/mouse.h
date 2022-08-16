// #ifndef __cplusplus
// #include <stdbool.h>
// #endif
typedef int bool;
static const bool false = 0;
static const bool true = 1;

#ifndef __cplusplus
#   include <assert.h>
#else
#   include <cassert>
#endif

typedef struct Position {
    long x;
    long y;
} Position;

bool positions_are_equal(const Position *a, const Position *b);

Position get_position();
