#include <iostream>
#include <vector>

using namespace std;

void heapify(int i, vector<int> &arr, int n) { // O(logn)
	int leftChild = 2*i + 1;
	int rightChild = 2*i + 2;
	int maxIdx = i; //stores the idx of max node, by default it's storing idx of parent

	if(leftChild < n && arr[leftChild] > arr[maxIdx]) { //leftChild < n checking if the leftChildIdx is actually valid
		maxIdx = leftChild;
	}

	if(rightChild < n && arr[rightChild] > arr[maxIdx]) {
		maxIdx = rightChild;
	}

	/*
	!for sorting in decending order
	if(leftChild < n && arr[leftChild] < arr[maxIdx]) { 
		maxIdx = leftChild;
	}

	if(rightChild < n && arr[rightChild] < arr[maxIdx]) {
		maxIdx = rightChild;
	}
		
	*/

	if(maxIdx != i) { //checking if the rootIdx i.e. 'i' isn't the maxIdx
		swap(arr[i], arr[maxIdx]);
		heapify(maxIdx, arr, n);
	}
}

void heapSort(vector<int> &nodes) { // O(n logn)
	/*step 1: building the maxHeap*/
	int n = nodes.size(); //size of array
	for (int i = n/2-1; i >= 0; i--) { //O(n) and caling the heapify overall: O(n logn)
		heapify(i, nodes, n); //i =  ith node, nodes = the array, n = size_of_arr
	}
	
	/*step 2: sorting the heap*/
	for (int i = n-1; i >= 0; i--) { // O(n logn)
		swap(nodes[0], nodes[i]); //swaping the largest node with the last idx of array
		/*since we swaped the heap needs fixing but the 0th(largest node) got its place in arr*/
		heapify(0, nodes, i); //reducing the size cuz, the 0th idx got its place
	}
	

}

int main() {
	vector<int> arr = {1, 4, 2, 5, 3};
	heapSort(arr);
	
	for (int i = 0; i <(int) arr.size(); i++) {
		cout<<arr[i]<<" ";
	}
	
	return 0;
}