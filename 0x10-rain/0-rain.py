#!/usr/bin/python3


def rain(walls):
    total = 0
    n = len(walls)

    for i in range(1, n - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]
        for j in range(i + 1, n):
            right = max(right, walls[j])
        total = total + (min(left, right) - walls[i])
    return total
