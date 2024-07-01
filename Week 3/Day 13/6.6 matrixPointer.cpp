/*Just testing pointer in 2d Arrays*/

#include <iostream>
using namespace std;

void func(int (*mat)[4], int row, int col)
{
    cout << "1st row is = " << *(*mat) << endl;
    cout << "1st row element = " << *(*(mat + 1) + 2) << endl;
}

int main()
{
    int mat[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    func(mat, 4, 4);

    return 0;
}