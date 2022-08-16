cdef extern from "mouse.h":
    cdef struct Position:
        long x
        long y

    Position get_position()
    bint positions_are_equal(const Position *a, const Position *b)
