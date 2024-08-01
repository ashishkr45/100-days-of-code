#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<vector<char>> board)
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

bool isSafe(vector<vector<char>> board, int row, int col)
{
    int n = board.size();

    /*checking if any outher Queen is present in current row*/
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] == 'Q')
        {
            return false;
        }
    }

    /*checking vertically for a queen*/
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    /*checking for diagonal-left safty*/
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    /*checking for diagonal-right safty*/
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void nQueen(vector<vector<char>> board, int row)
{
    int n = board.size();

    if (row == n)
    {
        printVec(board);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, row, j))
        {
            board[row][j] = 'Q';
            nQueen(board, row + 1);
            board[row][j] = '.';
        }
    }
    /*ones we've itrated over every place in the column and found each place unsafe
    the by dafault the function will return to the previous stack level*/
}

int main()
{
    vector<vector<char>> board;

    int n;
    cout << "Enter the size of board: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<char> row;
        for (int j = 0; j < n; j++)
        {
            row.push_back('.');
        }
        board.push_back(row);
    }
    nQueen(board, 0);

    return 0;
}