#!/usr/bin/python3
def add_tuple(tuple_a=(), tuple_b=()):
    """Adds the first two elements of two tuples."""

    a = tuple_a[:2] + (0, 0)
    b = tuple_b[:2] + (0, 0)

    return (a[0] + b[0], a[1] + b[1])
