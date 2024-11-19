#include <iostream>
using namespace std;

template <class tep1, class tep2>

void sum(tep1 a, tep2 b) {
	cout<<"Sum is: " << a + b<<endl;
}

int main() {
	sum (5, 5.2);
	return 0;
}