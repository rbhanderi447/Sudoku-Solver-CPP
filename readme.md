Sudoku Solver in C++

A simple command-line Sudoku solver in C++ using Backtracking and the Minimum Remaining Values (MRV) heuristic to solve puzzles efficiently.

Features
Backtracking: Tries possible digits and backtracks when a choice fails.
MRV Heuristic: Selects the empty cell with the fewest possible candidates.
Constraint Checking: Checks rows, columns, and 3×3 grids before placing digits.
Simple Input: Enter a Sudoku puzzle using 0 for empty cells.
How to Use
1. Compile
g++ main.cpp -o sudoku

2. Run
./sudoku

3. Enter the Puzzle

Enter all 81 numbers row by row, separated by spaces. Use 0 for empty cells.

Example:

8 0 0 0 0 0 0 0 0
0 0 3 6 0 0 0 0 0
0 7 0 0 9 0 2 0 0
0 5 0 0 0 7 0 0 0
0 0 0 0 4 5 7 0 0
0 0 0 1 0 0 0 3 0
0 0 1 0 0 0 0 6 8
0 0 8 5 0 0 0 1 0
0 9 0 0 0 0 4 0 0

Example Output
SOLUTION

8  1  2  7  5  3  6  4  9
9  4  3  6  8  2  1  7  5
6  7  5  4  9  1  2  8  3
1  5  4  2  3  7  8  9  6
3  6  9  8  4  5  7  2  1
2  8  7  1  6  9  5  3  4
5  2  1  9  7  4  3  6  8
4  3  8  5  2  6  9  1  7
7  9  6  3  1  8  4  5  2
