#!/usr/bin/python3
import sys


def is_safe(board, row, col, n):
    """Check if a queen can be placed on board[row][col]"""
    for j in range(col):
        if board[row][j] == 1:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, n, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def solve_nqueens_util(board, col, n, solutions):
    """Solve the N queens problem using backtracking"""
    if col >= n:
        solution = []
        for i in range(n):
            for j in range(n):
                if board[i][j] == 1:
                    solution.append([i, j])
        solutions.append(solution)
        return True

    res = False
    for i in range(n):
        if is_safe(board, i, col, n):
            board[i][col] = 1
            res = solve_nqueens_util(board, col + 1, n, solutions) or res
            board[i][col] = 0

    return res


def solve_nqueens(n):
    """Solve the N queens problem"""
    board = [[0 for x in range(n)] for y in range(n)]
    solutions = []
    solve_nqueens_util(board, 0, n, solutions)
    return solutions


def main():
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

    solutions = solve_nqueens(n)
    solutions.sort(key=lambda x: (x[0][1], x[1][1], x[2][1], x[3][1]))
    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    main()
