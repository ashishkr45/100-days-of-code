#include <iostream>
#include <vector>

using namespace std;

class Heap {
	vector<int> vec;
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