#!/usr/bin/python3
""" minOperations function """

def minOperations(n):
    """ finds the minimum number of copy/paste operations """
    result = 0
    for i in range(2, n + 1):
        while n % i == 0:
            result += i
            n = n / i
    return result;
