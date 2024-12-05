#include <iostream>
#include <vector>
using namespace std;

void insert(int arr[], int &n, int val) {
	int i = n;
	arr[n++] = val;

	while(i != 0 && arr[(i - 1) / 2] < arr[i] ) {//max heap
		swap(arr[(i - 1) / 2], arr[i]);
		i = (i - 1) / 2;
	}
} 

void heapifyDown(int arr[], int n, int i) {
	int max = i, left = 2 * i + 1, right = 2 * i + 2;
	if(left <= n && arr[left] > max) max = left; 
	if(right <= n && arr[right] > max) max = right; 

	if(max != i) {
		swap(arr[i], arr[max]);
		heapifyDown(arr, n, max);
	}
}

void delateHeap(int arr[], int &n) {
	heap[0] = heap[n--];
	heapifyDown(arr, n, 0);
}

int main() {
	int arr[100];
	int n = 0; //no's now stored in heap

	int cap;
	cout << "Enter the Capacity of Heap: ";
	cin >> cap;

	cout << "Enter the Elements of the Heap: ";
	for(int i = 0; i < cap; ++i) {
		int val;
		cin >> val;

		insert(arr, n, val);
	}

	cout << "Enter the indices to remove: ";
	int idx;
	vector<int> idn;
	cin >> idx;

	while (idx > 0) {
		idn.push_back(idx);
		cin >> idx;
	}
	

	return 0;
}