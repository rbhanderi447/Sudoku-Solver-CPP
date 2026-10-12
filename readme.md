# Sudoku Solver in C++

A simple command-line Sudoku solver written in C++ that uses **Backtracking** coupled with the **Minimum Remaining Values (MRV)** heuristic to solve $9 \times 9$ Sudoku puzzles efficiently.

---

## Features

* **Backtracking Algorithm:** Recursively attempts digit placements and backtracks immediately upon reaching an invalid state.
* **MRV Heuristic:** Optimizes search depth by prioritizing the empty cell with the fewest legal candidate numbers.
* **Constraint Validation:** Enforces standard Sudoku rules across rows, columns, and $3 \times 3$ subgrids.
* **Simple Input Format:** Accepts standard 81-digit grid inputs using `0` to denote empty cells.

---

## How to Use

### 1. Compilation

Compile the C++ source file using `g++` (or any standard C++ compiler):

```bash
g++ main.cpp -o sudoku

```

### 2. Execution

Run the compiled binary:

```bash
./sudoku

```

### 3. Entering a Puzzle

Input all 81 numbers row by row, separated by spaces or newlines. Use `0` to represent empty cells.

#### Example Input

```text
8 0 0 0 0 0 0 0 0
0 0 3 6 0 0 0 0 0
0 7 0 0 9 0 2 0 0
0 5 0 0 0 7 0 0 0
0 0 0 0 4 5 7 0 0
0 0 0 1 0 0 0 3 0
0 0 1 0 0 0 0 6 8
0 0 8 5 0 0 0 1 0
0 9 0 0 0 0 4 0 0

```

#### Example Output

```text
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

```

---

## How It Works

1. **Find Best Cell (MRV):** Scans the grid for the unassigned cell with the smallest number of valid choices (1–9).
2. **Validate Candidates:** For each valid candidate, checks if placing the digit maintains Sudoku constraints:
* Unique in the current row
* Unique in the current column
* Unique in the $3 \times 3$ subgrid


3. **Recursive Placement & Backtrack:** Places the valid digit and recursively attempts to solve the remaining grid. If a state leads to no solution, it resets the cell to `0` (backtracks) and tries the next candidate.
