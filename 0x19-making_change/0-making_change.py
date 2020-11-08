#!/usr/bin/pyton3
"""
function that determine the fewest number of coins
needed to meet a given total
"""


def makeChange(coins, total):
    """ Determine fewest number of coins to meet total """
    count = 0
    coin_total = 0

    if total <= 0:
        return 0

    coins.sort()

    for i in range(len(coins) - 1, 0, -1):
        while coin_total + coins[i] <= total:
            coin_total += coins[i]
            count += 1
        if coin_total == total:
            return count
    return -1
