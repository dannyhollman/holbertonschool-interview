#!/usr/bin/python3
""" Validates UTF-8 encoding """


def validUTF8(data):
    """ determines if bytes represent valid UTF-8 """
    try:
        bytes(data)
    except:
        return False
    return True
