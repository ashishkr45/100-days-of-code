#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Student
{
public:
	int marks;
	string name;

	Student(int marks, string name) {
		this->marks = marks;
		this->name = name;
	}

	bool operator < (const Student &ob) const {
		return this->marks < ob.marks;
	}
};


int main() {
	priority_queue<Student> pq;
	pq.push(Student(89, "Lucifer"));
	pq.push(Student(98, "Daemon Targaryen"));
	pq.push(Student(78, "Tyrion Lannister"));
	pq.push(Student(99, "Rhaenyra Targaryen"));
	pq.push(Student(01, "Ser Criston Cole"));

	while (!pq.empty()) {
		cout << "Top: " << pq.top().name << ", " << pq.top().marks << endl;
		pq.pop();
	}
	return 0;
}