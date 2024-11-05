#include <iostream>
#include <vector>

using namespace std;

class Heap {
	vector<int> vec; //complete binary tree
public:
	void push (int data) {
		vec.push_back(data); //step: 1

		// step: 2 fixing the heap
		int childIdx = vec.size() - 1;
		int parentIdx = (childIdx - 1) / 2;

		while (parentIdx >= 0 && vec[childIdx] > vec[parentIdx]) // to make a min heap we'll just reverse this comparision condiution
		{
			swap(vec[childIdx], vec[parentIdx]);
			childIdx = parentIdx;
			parentIdx = (childIdx - 1) / 2;
		}
	}

	void pop() {

	}

	int top() {
		return vec[0];
	}

	bool empty() {
		return vec.empty() == 0;
	}
};

int main() {
	Heap heap;
	heap.push(10);
	heap.push(20);
	heap.push(56);
	heap.push(69);
	heap.push(30);

	cout<<heap.top()<<endl;

	return 0;
}