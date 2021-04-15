#!/usr/bin/python3
"""
0-rain
"""


def rain(walls):
    """ Method that calculates how much water will be retained """
    if walls is None:
        return 0

    len_walls = len(walls)
    end_walls = len_walls - 1
    cap_water = 0

    for x in range(1, end_walls):
        left_val = walls[x]

        for y in range(x):
            left_val = max(walls[y], left_val)

        right_val = walls[x]
        start_walls = x + 1
        for y in range(start_walls, len_walls):
            right_val = max(walls[y], right_val)

        min_cap_water = min(left_val, right_val) - walls[x]
        cap_water = cap_water + min_cap_water
    return cap_water
