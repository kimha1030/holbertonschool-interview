#!/usr/bin/python3
"""
Task 0. Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """ Given an n x n 2D matrix, rotate it 90
        degrees clockwise
    """
    new_matrix = []
    col = len(matrix) - 1
    len_m = len(matrix)
    for col in range(len_m):
        tmp = []
        for row in range(len_m-1, -1, -1):
            tmp.append(matrix[row][col])
        new_matrix.append(tmp)
    for i in range(len_m):
        for j in range(len_m):
            matrix[i][j] = new_matrix[i][j]
