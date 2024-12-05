// You are using GCC
#include <iostream>

using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(int heap[], int size, int i)
{
    int mx = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < size && heap[mx] < heap[left]) mx = left;
    if(right < size && heap[mx] < heap[right]) mx = right;
    
    if(mx != i) {
        swap(heap[mx], heap[i]);
        minHeapify(heap, size, mx);
    }
}

void insertElement(int heap[], int &size, int value, int capacity) 
{
    heap[size] = value;
    int i = size;
    size++;
    
    while(i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[(i-1)/2], &heap[i]);
        i = (i - 1) / 2;
    }
}

void displayMinHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int findMaxValue(int heap[], int size)
{
    int max = heap[0];
    
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
        insertElement(heap, size, value, capacity);
    }

    displayMinHeap(heap, size);

    int maxValue = findMaxValue(heap, size);
    cout << "Maximum: " << maxValue;

    return 0;
}