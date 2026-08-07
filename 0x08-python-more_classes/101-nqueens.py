#!/usr/bin/python3
"""N Queens puzzle solver."""

import sys


def is_safe(board, row, col, n):
    """Check if a queen can be placed at row, col."""
    for r in range(row):
        c = board[r]

        # Same column
        if c == col:
            return False

        # Same diagonal
        if abs(c - col) == abs(r - row):
            return False

    return True


def solve(board, row, n):
    """Find all solutions using backtracking."""
    if row == n:
        solution = []
        for r in range(n):
            solution.append([r, board[r]])
        print(solution)
        return

    for col in range(n):
        if is_safe(board, row, col, n):
            board[row] = col
            solve(board, row + 1, n)


if __name__ == "__main__":

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = [-1] * n
    solve(board, 0, n)
