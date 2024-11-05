#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	priority_queue<int> pq;
	pq.push(5);
	pq.push(69);
	pq.push(88);
	pq.push(0);
	pq.push(1);

	while (!pq.empty()) {
		cout<<"Top: "<<pq.top()<<endl;
		pq.pop();
	}
	cout<<endl;
	priority_queue<int, vector<int>, greater<int>> qp;
	qp.push(5);
	qp.push(69);
	qp.push(88);
	qp.push(0);
	qp.push(1);

	while (!qp.empty()) {
		cout<<"Top: "<<qp.top()<<endl;
		qp.pop();
	}

	cout<<"\nUsing string\n";
	priority_queue<string, vector<string>, greater<string>> st;
	st.push("Hellooooooo");
	st.push("Sussy baka");
	st.push("DumbFuck");
	st.push("Slutty Queen");
	st.push("Dick head");

	while (!st.empty()) {
		cout<<"Top: "<<st.top()<<endl;
		st.pop();
	}

	return 0;
}