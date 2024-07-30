#!/usr/bin/python3
"""
Rain algorithm module
"""


def rain(walls):
    """ A function that calculate on how much
        water the walls can trap after rain

    Args:
        walls (list):  list of non-negative integer that
                        are the lenght of the walls.

    Returns:
        int: Total amount of rainwater retained.
    """
    res = 0
    lenght = len(walls)
    for index in range(lenght - 1):
        left = walls[index]
        for idx in range(index):
            left = max(left, walls[idx])
        right = walls[index]
        for idx in range(index + 1, lenght):
            right = max(right, walls[idx])
        res = res + (min(left, right) - walls[index])
    return res
