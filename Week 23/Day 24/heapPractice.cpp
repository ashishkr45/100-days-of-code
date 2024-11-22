#include <iostream>
using namespace std;

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void maxHeapify(int arr[], int n, int i) {
	int parent = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if(left < n && arr[left] > arr[parent]) {
		parent = left;
	}

	if(right < n && arr[right] > arr[parent]) {
		parent = right;
	}

	if(parent != i) {
		swap(arr, i, parent);
		maxHeapify(arr, n, parent);
	}
}

void insertIntoMaxHeap(int arr[], int n, int val) {
	arr[n] = val;
	int i = n;
	n++;

	int parent = (i - 1) / 2;

	while(i != 0 && arr[parent] < arr[i]) {
		swap(arr, i, parent);
		parent = (parent - 1) / 2;
	}
}

void buildMaxHeap(int arr[], int n) 
{
    for(int i = (n/2)-1; i>= 0; i--){
        maxHeapify(arr, n, i);
    }   
}

bool isPrime(int num) {
	if(num <= 1) return false;
	if(num == 2 || num == 3) return false;
	if(num % 2 == 0 || num % 3 == 0) return false;

	for(int i = 5; i * i <= num; i+=6) {
		if(num % i == 0 || num % (i + 2) == 0) return false;
	}
	return true;
}

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