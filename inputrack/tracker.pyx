from inputrack cimport mouse


def get_mouse_position():
    cdef mouse.Position p = mouse.get_position()
    return p.x, p.y


def track():
    cdef mouse.Position position, previous
    previous = mouse.get_position()

    while 1:
        position = mouse.get_position()

        if not mouse.positions_are_equal(&position, &previous):
            previous = position
            print(position.x, position.y)
