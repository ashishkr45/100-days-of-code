#include <iostream>
using namespace std;

void problem1();
void problem2();
void problem3();

int main()
{
    cout << "Answer of problem 1: ";
    problem1();
    cout << endl;

    cout << "Answer of problem 2: ";
    problem2();
    cout << endl;

    cout << "Answer of problem 3: ";
    problem3();
    cout << endl;

    return 0;
}

void problem1()
{
    int arr[2][3] = {
        {4, 7, 8},
        {8, 8, 7}};

    int count = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == 7)
            {
                count++;
            }
        }
    }
    cout << "Count of 7's in array is: " << count;
}

void problem2()
{
    int nums[3][3] = {
        {1, 4, 9},
        {11, 4, 3},
        {2, 2, 3}};

    int sum = 0;
    for (int i = 0; i < 3; i++) // Change loop to iterate through all rows
    {
        for (int j = 0; j < 3; j++)
        {
            sum += nums[i][j];
        }
    }
    cout << "Total sum: " << sum;
}

void problem3()
{
    int mat[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << mat[j][i] << " ";
        }
        cout << endl;
    }
}
