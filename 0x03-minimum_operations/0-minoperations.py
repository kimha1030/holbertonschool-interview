#!/usr/bin/python3
"""
Calculate the fewest num of operations  needed to
result in exactly n H characters in the file.
"""


def minOperations(n):
    """
        Method that calculates the fewest number of
        operations needed to result in exactly n.
    """
    count = 0
    min_val = 2
    if n < 2:
        return 0
    while min_val <= n:
        if (n % min_val == 0):
            count = count + min_val
            n = n / min_val
        else:
            min_val = min_val + 1
    return (count)

if __name__ == "__main__":
    minOperations()
