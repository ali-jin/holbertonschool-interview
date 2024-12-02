#!/usr/bin/python3
""" Prime Game """


def isWinner(x, nums):
    """
    Determinate the winner of the prime game
    """
    if x != len(nums):
        return None

    nums.sort()
    primes = sieve_of_eratosthenes(max(nums))
    maria_wins = 0
    ben_wins = 0

    for n in nums:
        prime_count = 0
        for prime in primes:
            if prime <= n:
                prime_count += 1
            else:
                break

        if prime_count % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None


def sieve_of_eratosthenes(n):
    """ Genarate all prime numbers in range of n """
    primes = [True for _ in range(n + 1)]
    p = 2
    while p * p <= n:
        if primes[p]:
            for i in range(p * p, n + 1, p):
                primes[i] = False
        p += 1
    return [p for p in range(2, n + 1) if primes[p]]
