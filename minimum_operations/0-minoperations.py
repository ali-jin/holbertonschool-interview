#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    """
    Calculates the fewest number of operations needed to result in exactly n

    Args:
        n (int): An integer

    Returns:
        int: number of operations needed to result in exactly n, or 0.
    """
    if n <= 1:
        return 0

    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    return operations
