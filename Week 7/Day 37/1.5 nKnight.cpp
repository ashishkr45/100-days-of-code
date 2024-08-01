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

bool isSafe_for_Knight(vector<vector<char>> board, int row, int col)
{
    int n = board.size();

    // Checking if any other knight is present at positions relative to the given knight
    if (row + 2 < n && col + 1 < n && board[row + 2][col + 1] == 'K' &&
        row + 2 < n && col - 1 >= 0 && board[row + 2][col - 1] == 'K')
    {
        return false;
    }

    if (row - 2 >= 0 && col + 1 < n && board[row - 2][col + 1] == 'K' &&
        row - 2 >= 0 && col - 1 >= 0 && board[row - 2][col - 1] == 'K')
    {
        return false;
    }

    if (row + 1 < n && col + 2 < n && board[row + 1][col + 2] == 'K' &&
        row + 1 < n && col - 2 >= 0 && board[row + 1][col - 2] == 'K')
    {
        return false;
    }

    if (row - 1 >= 0 && col + 2 < n && board[row - 1][col + 2] == 'K' &&
        row - 1 >= 0 && col - 2 >= 0 && board[row - 1][col - 2] == 'K')
    {
        return false;
    }

    return true;
}

void nKnight(vector<vector<char>> board, int row)
{
    int n = board.size();

    if (row == n)
    {
        printVec(board);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe_for_Knight(board, row, j))
        {
            board[row][j] = 'K';
            nKnight(board, row + 1);
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
    nKnight(board, 0);

    return 0;
}