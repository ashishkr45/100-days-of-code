#include <iostream>
using namespace std;

void swap(int *a, int *b) {
	int temp = a;
	a = b;
	b = temp;
}

void heapify(int i, int arr[], int n) {
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if(left < n && arr[left] > arr[max]) {
		max = left;
	}

	if(right < n && arr[right] > arr[max]) {
		max = right;
	}

	if(i != max) {
		swap(arr[max], arr[i]);
		heapify(max, arr, n);
	}
}

