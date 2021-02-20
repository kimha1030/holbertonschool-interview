#!/usr/bin/python3
"""
Validate utf-8
"""


def validUTF8(data):
    """Method that determines if a data is a valid UTF-8 encoding"""
    count = 0
    for i in data:
        i = format(i, '#010b')[-8:]
        if count != 0:
            count = count - 1
        elif i[0] == '1':
            if count == 1 or count > 4:
                return False
            count = count - 1
    if count == 0:
        return True
    else:
        return False
