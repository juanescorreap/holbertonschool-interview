#!/usr/bin/python3
"""
Function that indicates the total
amount of rainwater retained
"""


def rain(walls):
    """
    Function that indicates the total
    amount of rainwater retained
    """
    if walls is None:
        return 0
    idxLeft = 0
    idxRight = len(walls) - 1
    leftMax = 0
    rightMax = 0
    rainwater = 0
    while (idxLeft <= idxRight):
        leftMax = max(leftMax, walls[idxLeft])
        rightMax = max(rightMax, walls[idxRight])
        if leftMax < rightMax:
            rainwater += leftMax - walls[idxLeft]
            idxLeft += 1
        else:
            rainwater += rightMax - walls[idxRight]
            idxRight -= 1
    return rainwater
