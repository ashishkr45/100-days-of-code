#include <iostream>
using namespace std;

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// Maintain max heap property
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr, i, largest);
        maxHeapify(arr, n, largest);
    }
}

// Insert an element into the heap
void insertIntoMaxHeap(int arr[], int &n, int value) {
    arr[n] = value;
    int i = n;
    n++;

    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr, i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

// Check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

// Print the heap
void printMaxHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100];
    int n = 0; // Number of elements in the heap
    int num_elements;

    cin >> num_elements;

    for (int i = 0; i < num_elements; i++) {
        int value;
        cin >> value;

        if (isPrime(value)) {
            insertIntoMaxHeap(arr, n, value);
        }
    }

    printMaxHeap(arr, n);

    return 0;
}