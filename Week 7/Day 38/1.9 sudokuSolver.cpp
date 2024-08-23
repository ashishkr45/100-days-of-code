#include <iostream>

using namespace std;

int sudoku[9][9] = {
    {5, 0, 0, 0, 0, 0, 0, 0, 9},
    {0, 0, 3, 0, 0, 5, 0, 1, 0},
    {0, 6, 0, 0, 8, 0, 0, 0, 0},
    {0, 0, 0, 2, 0, 0, 0, 0, 7},
    {0, 0, 0, 0, 0, 0, 0, 5, 0},
    {0, 0, 0, 0, 0, 6, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 4, 0, 0, 0, 0, 7, 0, 0},
    {9, 0, 0, 0, 0, 0, 0, 0, 4}};

void printSudoku(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int digi, int col, int row)
{
    /*checking vertically*/
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][col] == digi)
            return false;
    }

    /*checking horizontally*/
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == digi)
            return false;
    }

    /*checking for the 3x3 grid*/
    int SR = (row / 3) * 3;
    int SC = (col / 3) * 3;

    for (int i = SR; i < SR + 3; i++) // SR - startingRow
    {
        for (int j = SC; j < SC + 3; j++) // SC - startingColumn
        {
            if (sudoku[i][j] == digi)
            {
                return false;
            }
        }
    }
    return true;
}

bool sudokuSolver(int row, int col)
{
    if (row == 9)
    {
        // sudoku Solved
        printSudoku(sudoku);
        return true;
    }

    int nextRow = (col + 1 == 9) ? (row + 1) : row;
    int nextCol = (col + 1 == 9) ? 0 : (col + 1);

    if (sudoku[row][col] != 0)
        return sudokuSolver(nextRow, nextCol);

    for (int i = 0; i <= 9; i++)
    {
        if (isSafe(i, col, row))
        {
            sudoku[row][col] = i;
            if (sudokuSolver(nextRow, nextCol))
            {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    sudokuSolver(0, 0);

    return 0;
}
