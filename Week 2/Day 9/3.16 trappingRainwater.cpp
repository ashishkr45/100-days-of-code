// LEETCODE
/*42. Trapping Rain Water*/

#include <iostream>
#include <climits>
using namespace std;

int trap(int *height, int n);
void printArray(int *arr, int n);

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int height[size];
    cout << "Enter the hight of the bars: ";
    for (int i = 0; i < size; i++)
    {
        cin >> height[i];
    }

    cout << "Water traped: " << trap(height, size) << endl;

    return 0;
}

int trap(int *height, int n)
{
    int leftMax[20000], rightMax[20000];
    leftMax[0] = height[0]; // we'll get zero
    rightMax[n - 1] = height[n - 1];

    /*Calculating the maximim bar on the left side of the current one*/
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], height[i - 1]);
    }

    /*Calculating the maximim bar on the right side of the current one*/
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], height[i + 1]);
    }

    int waterStored = 0;
    for (int i = 0; i < n; i++)
    {
        int currH2O = min(leftMax[i], rightMax[i]) - height[i];
        if (currH2O > 0)
            waterStored += currH2O;
    }

    return waterStored;
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}