#!/usr/bin/python3
""" parse log and print status codes """
import sys
from signal import signal, SIGINT


count = 0
size = 0
status = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}


def printer():
    print("File size: " + str(size))
    for x in sorted(status):
        if status[x] != 0:
            print(str(x) + ": " + str(status[x]))


def handler(signum, stack):
    printer()
    raise

signal(SIGINT, handler)

if __name__ == "__main__":
    for line in sys.stdin:
        if count == 10:
            printer()
            count = 0
        splt = line.split()
        size += int(splt[8])
        status[int(splt[7])] += 1
        count = count + 1
