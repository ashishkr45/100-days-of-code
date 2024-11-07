#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
	vector<int> vec;

	void heapify(int i) { // making this function private
	/*We dont want it's asscess outside the class*/
		if(i >= (int)vec.size()) {
			return;
		}

		int left = 2*i + 1;
		int right = 2*i + 2;

		int maxI = i;

		if(left <(int) vec.size() && vec[left] > vec[maxI]) {
			maxI = left;
		}

		if(right <(int) vec.size() && vec[right] > vec[maxI]) {
			maxI = right;
		}

		swap(vec[i], vec[maxI]);
		if(maxI != i) {
			heapify(maxI);
		}
	}

public:
	void push (int data) {
		vec.push_back(data);

		int childIdx = vec.size() - 1;
		int parentIdx = (childIdx - 1) / 2;

		while (parentIdx >= 0 && vec[childIdx] > vec[parentIdx])
		{
			swap(vec[childIdx], vec[parentIdx]);
			childIdx = parentIdx;
			parentIdx = (childIdx - 1) / 2;
		}
	}

	void pop() {
		//step 1: swap root(larges Idx and last elem)
		swap(vec[0], vec[vec.size() - 1]);

		//step 2: delete the last idx
		vec.pop_back();

		//step 3: call heapify for the root idx
		heapify(0);
	}

	int top() {
		return vec[0];
	}

	bool empty() {
		return vec.empty();
	}
};

int main() {
	Heap heap;
	heap.push(9);
	heap.push(4);
	heap.push(8);
	heap.push(1);
	heap.push(2);
	heap.push(5);

	while (!heap.empty()) {
		cout << "Top: "<< heap.top() << endl; 
		heap.pop();
	}
	
	return 0;
}