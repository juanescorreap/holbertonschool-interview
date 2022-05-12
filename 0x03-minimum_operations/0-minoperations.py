#!/usr/bin/python3
"""method that calculates the fewest number of operations needed
to result in exactly n H characters in the file."""


def minOperations(n):
    """method that calculates the fewest number of operations needed
    to result in exactly n H characters in the file."""

    number_of_operations = 0
    operations_avaliable = 2
    j = n
    k = n

    if type(n) != int or n < 1:
        return 0

    while (True):
        j = k / operations_avaliable

        if k == 1:
            break

        if not j.is_integer():
            operations_avaliable += 1
        elif j.is_integer():
            number_of_operations += operations_avaliable
            operations_avaliable = 2
            k = j
        elif k == operations_avaliable:
            number_of_operations += operations_avaliable
            break

    return number_of_operations
