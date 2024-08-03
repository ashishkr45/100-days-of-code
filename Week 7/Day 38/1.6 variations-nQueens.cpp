#include <iostream>
#include <vector>

using namespace std;

void printBoard(vector<vector<char>> board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << "___________" << endl;
}

bool Safe(vector<vector<char>> board, int row, int col)
{
    int n = board.size();

    for (int i = 0; i < row; i++) // checking the rows
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    for (int i = 0; i < n; i++) // checking the columns
    {
        if (board[row][i] == 'Q')
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) // left-diagonal
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j <= n; i--, j++) // right-diagonal
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void nQueens(vector<vector<char>> board, int row, bool &printed)
{
    int n = board.size();
    if (row == n)
    {
        if (!printed)
        {
            printBoard(board);
            printed = true;
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (Safe(board, row, i))
        {
            board[row][i] = 'Q';
            nQueens(board, row + 1, printed);
            board[row][i] = '.';
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the board: ";
    cin >> n;

    vector<vector<char>> board;

    for (int i = 0; i < n; i++)
    {
        vector<char> row;
        for (int j = 0; j < n; j++)
        {
            row.push_back('.');
        }
        board.push_back(row);
    }
    bool printed = false;
    nQueens(board, 0, printed);

    return 0;
}