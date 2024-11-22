/*

Problem Statement



Liam is a data analyst who is working on optimizing a list of numbers for further analysis. He decides to create a min heap from the integers he collects, as it allows him to efficiently retrieve the smallest number at any time.



After inserting the numbers into the min heap, he wants to visualize its structure and also find the maximum value among the elements.

Input format :
The first line contains an integer n, representing the number of integers Liam collected.

The second line consists of n space-separated integers, which are the values Liam wants to insert into the min heap.

Output format :
The output consists of two parts:

Display the elements of the min heap as integers separated by a space.
Display the maximum value among the elements in the min heap in the format: "Maximum: <value>".


Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ n ≤ 10

1 ≤ values ≤ 1000

Sample test cases :
Input 1 :
5
3 9 2 6 8
Output 1 :
2 6 3 9 8 
Maximum: 9
Input 2 :
8
25 15 17 32 23 5 12 8
Output 2 :
5 8 12 23 25 17 15 32 
Maximum: 32


*/
#include <iostream>

using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(int heap[], int size, int i)
{
    int parent = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < size && heap[left] < heap[parent]) {
        parent = left;
    }
    
    if(right < size && heap[right] < heap[parent]) {
        parent = right;
    }
    
    if(parent != i) {
        swap(i, parent);
        minHeapify(heap, size, parent);
    }
}

void buildMinHeap(int heap[], int size) 
{
    for(int i = (size / 2) - 1; i >= 0; i--) {
        minHeapify(heap, size, i);
    }
}

void insertElement(int heap[], int *size, int value) 
{
    heap[*size] = value;
    int i = *size;
    (*size)++;
    
    while(i != 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void displayMinHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int findMaxValue(int heap[], int size)
{
    int max =  heap[0];
    for(int i = 0; i < size; i++) {
        if(heap[i] > max) {
            max = heap[i];
        }
    }
    return max;
}

int main() {
    int n;
    cin >> n;

    int capacity = n; 
    int heap[capacity]; 
    int size = 0;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertElement(heap, &size, value);
    }

    displayMinHeap(heap, size);

    int maxValue = findMaxValue(heap, size);
    cout << "Maximum: " << maxValue;

    return 0;
}
