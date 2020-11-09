#!/usr/bin/python3
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

    coins = sorted(coins, reverse=True)

    for coin in coins:
        while coin_total + coin <= total:
            coin_total += coin
            count += 1
        if coin_total == total:
            return count
    return -1
