#include <iostream>
using namespace std;

template <class D>

D maxVal(D a, D b) {
	return a < b ? b : a;
}

int main() {
	cout << maxVal(3.9, 9.0) <<endl;
}