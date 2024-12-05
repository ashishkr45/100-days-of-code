#include<iostream>
using namespace std;

void heapifyUp(int heap[], int n) {
    int i = n;
    while (i > 1 && heap[i] > heap[i / 2]) {
        swap(heap[i], heap[i / 2]);
        i = i / 2;
    }
}

void heapifyDown(int heap[], int n, int i) {
    int largest = i, left = 2 * i, right = 2 * i + 1;
    if (left <= n && heap[left] > heap[largest]) largest = left;
    if (right <= n && heap[right] > heap[largest]) largest = right;
    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapifyDown(heap, n, largest);
    }
}

void insertHeap(int heap[], int& n, int val) {
    heap[++n] = val;
    heapifyUp(heap, n);
}

void deleteHeap(int heap[], int& n) {
    if (n == 0) return;
    heap[1] = heap[n--];
    heapifyDown(heap, n, 1);
}

void printHeap(int heap[], int n) {
    for (int i = 1; i <= n; i++) cout << heap[i] << " ";
    cout << endl;
}

int main() {
    int heap[100], n = 0;

    insertHeap(heap, n, 10);
    insertHeap(heap, n, 20);
    insertHeap(heap, n, 5);
    insertHeap(heap, n, 30);

    cout << "Heap after insertion: ";
    printHeap(heap, n);

    deleteHeap(heap, n);
    cout << "Heap after deletion: ";
    printHeap(heap, n);

    return 0;
}
