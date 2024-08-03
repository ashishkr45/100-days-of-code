#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<char>> &board)
{
    int rows = board.size();
    int cols = board[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << "___________" << endl;
}

int Ways(vector<vector<char>> &board, int n, int m)
{
    if (n >= (int)board.size() || m >= (int)board[0].size())
        return 0;

    if (n == (int)board.size() - 1 && m == (int)board[0].size() - 1)
    {
        printBoard(board);
        return 1;
    }

    board[n][m] = '#';
    int way1 = Ways(board, n + 1, m);
    int way2 = Ways(board, n, m + 1);
    board[n][m] = '.'; // Restore the board

    return way1 + way2;
}

int main()
{
    int n, m;
    cout << "Enter the Rows: ";
    cin >> n;
    cout << "Enter the Columns: ";
    cin >> m;

    vector<vector<char>> board(n, vector<char>(m, '.'));

    board[n - 1][m - 1] = '@';

    cout << "Total ways: " << Ways(board, 0, 0) << endl;
    return 0;
}
