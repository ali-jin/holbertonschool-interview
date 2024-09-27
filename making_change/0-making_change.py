#!/usr/bin/python3
""" Making Change """


def makeChange(coins, total):
    """_summary_

    Args:
        coins (_type_): _description_
        total (_type_): _description_
    """
    if total == 0:
        return 0

    min_coins = [float("inf")] * (total + 1)
    min_coins[0] = 0

    coins.sort(reverse=True)

    for coin in coins:
        for i in range(coin, total + 1):
            min_coins[i] = min(min_coins[i], min_coins[i - coin] + 1)

    return -1 if min_coins[total] == float("inf") else min_coins[total]
