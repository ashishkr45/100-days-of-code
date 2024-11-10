#include <iostream>
using namespace std;

class Heap {

	int* arr;
	int size;
	int capacity;

	int leftChild(int i) {
		return 2*i + 1;
	}

	int rightChild(int i) {
		return 2*i + 2;
	}

	int parent(int i) {
		return (i - 1) / 2;
	}

	void heapifyUP(int idx) {
		while (idx >= 0 && arr[idx] > arr[parent(idx)]) {
			swap(arr[idx], arr[parent(idx)]);
			idx = parent(idx);
		}	
	}

	void heapifyDown(int idx) {
		if(idx >= size) {
			return;
		}

		int max = idx;
		if(leftChild(idx) < size && arr[leftChild(idx)] > arr[max]){
			max = leftChild(idx);
		}

		if(rightChild(idx) < size && arr[rightChild(idx) > arr[max]]){
			max = rightChild(idx);
		}
		
		swap(arr[idx], arr[max]);

		if(max != idx){
			heapifyDown(max);
		}
	}

public:
	Heap(int capacity) {
		this->capacity = capacity;
		this->arr = new int[capacity];
		this->size = 0;
	}
	
	~Heap() {
		delete arr;
	}

	void insert(int data) { //insert a node in the heap
		if (size == capacity) {
			cout << "Heap is Full!\n";
			return;
		}

		arr[size] = data;
		heapifyUP(size);
		size++;
	}

	int pop() { //remove the top node form the heap
		if(size <= 0) {
			cout << "Heap is empty\n";
			return -1;
		}
		int max = arr[0];
		swap(arr[0], arr[size-1]);
		size--; //reducing the size cuz, a node just poped
		heapifyDown(0);
		return max;
	}

	int top() {
		return (size > 0) ? arr[0] : -1;
	}

	bool empty() {
		return size == 0;
	}
};

int main() {
	Heap heap(10);
	heap.insert(9);
	heap.insert(4);
	heap.insert(8);
	heap.insert(1);
	heap.insert(2);
	heap.insert(5);

	while (!heap.empty()) {
		cout << "Top: " << heap.top() << endl; 
		heap.pop();
	}
	
	return 0;
}