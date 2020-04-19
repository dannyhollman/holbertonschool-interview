#!/usr/bin/python3


def canUnlockAll(boxes):
    if boxes is None:
        return True
    # loop through each box (index)
    for x in range(1, len(boxes) - 1):
        # Make list of all keys
        temp = []
        for index in range(len(boxes)):
            if index == x:
                continue
            for key in boxes[index]:
                temp.append(key)
        # check for key
        if x not in temp:
            return False
    return True
