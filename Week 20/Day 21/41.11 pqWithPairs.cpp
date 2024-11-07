#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct ComparePair {
	bool operator () (pair<int, string> &p1, pair<int, string> &p2) {
		return p1.first < p2.first;
	}
};

int main() {
	//deafault heap is always max heap - on basis of pair->first property
	priority_queue<pair<int, string>, vector<pair<int, string>>, ComparePair> pq;
	pq.push(make_pair(89, "Lucifer"));
	pq.push(make_pair(98, "Daemon Targaryen"));
	pq.push(make_pair(78, "Tyrion Lannister"));
	pq.push(make_pair(99, "Rhaenyra Targaryen"));
	pq.push(make_pair(01, "Ser Criston Cole"));

	while (!pq.empty()) {
		cout << "Top: " << pq.top().first << ", " << pq.top().second << endl;
		pq.pop();
	}
	return 0;
}