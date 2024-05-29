#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    """
    Calculates the fewest number of operations needed to result in exactly n

    Args:
        n (int): An integer

    Returns:
        int: number of operations needed to result in exactly n
    """
    dp = [0] * (n + 1)

    for i in range(1, n + 1):
        if i % 2 == 0:
            dp[i] = dp[i // 2] + 1
        else:
            dp[i] = dp[i - 1] + 1

    return dp[n]
