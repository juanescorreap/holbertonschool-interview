#!/usr/bin/python3
"""
The N queens puzzle is the challenge of placing
N non-attacking queens on an NxN chessboard
"""
import sys


def nqueens(n: int):
    """
    Python3 program to solve N Queen
    Problem using backtracking
    """
    matrix = [[0 for x in range(n)] for y in range(n)]
    print(str(matrix))


if __name__ == "__main__":
    if len(sys.argv) > 2 or len(sys.argv) < 2:
        print("Usage: nqueens N")
        exit(1)

    if not sys.argv[1].isdigit():
        print("N must be a number")
        exit(1)

    if int(sys.argv[1]) < 4:
        print("N must be at least 4")
        exit(1)

    nqueens(int(sys.argv[1]))
