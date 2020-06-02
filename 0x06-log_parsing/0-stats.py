#!/usr/bin/python3
""" parse log and print status codes """
import sys


count = 0
size = 0
status = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
while True:
    try:
        if count == 10:
            print("File size: " + str(size))
            for x in sorted(status):
                if status[x] != 0:
                    print(str(x) + ": " + str(status[x]))
            count = 0
        data = sys.stdin.readline()
        splt = data.split()
        size += int(splt[8])
        status[int(splt[7])] += 1
        count = count + 1
    except KeyboardInterrupt:
        print("File size: " + str(size))
        for x in sorted(status):
            if status[x] != 0:
                print(str(x) + ": " + str(status[x]))
        sys.exit()
