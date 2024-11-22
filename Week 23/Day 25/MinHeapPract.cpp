#include <iostream>
using namespace std;

class Heap {
private:
	int *heap;
	int cap;
	int size;

	void heapify(int i ){
		int parent = i;
		int left = (i * 2) + 1;
		int right = (i * 2) + 2;

		if(left < size && heap[parent] < heap[left]) {
			parent = left;
		}

		if(right < size && heap[parent] < heap[right]) {
			parent = right;
		}

		if(parent != i) {
			swap(heap[parent], heap[i]);
			heapify(parent);
		}
	}

public:
	Heap(int capacity) {
		this->cap = capacity;
		this->size = 0;
		this->heap = new int[cap];
	}

	~Heap() {
		delete[] heap;
	}

	void insert(int key) {
		if(size == cap) {
			cout << "Heap is full\n";
			return;
		}

		heap[size++] = key;
		int i = size;

		while(i != 0 && heap[(i-1)/2] > heap[i]) {
			swap(heap[i], heap[(i-1)/2]);
			i = (i - 1) / 2;
		}
	}

	int extMin() {
		if(size < 0) return -1;
		if(size == 1) {
			size--;
			return heap[0];
		}

		int root = heap[0];
		heap[0] = heap[(size--) - 1];
		heapify(0);

		return root;
	}

	void printHeap() {
		for(int i = 0; i < size; ++i) {
			cout << heap[i] << " ";
		}
		cout<<endl;
		return;
	}
};

int main() {
	int capacit;
	cout << "Enter the capacity of heap: ";
	cin >> capacit; 

	Heap heap(capacit);

	for (int i = 0; i < capacit; i++)
	{
		int data;
		cin >> data;
		heap.insert(data);
	}

	cout << "Minium Element: " << heap.extMin() << endl;

	heap.printHeap();

	return 0;	
}