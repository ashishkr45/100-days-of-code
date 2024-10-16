#include <iostream>
#include <string>

using namespace std;

// Base class
class Person
{
protected:
	string name;
	int age;

public:
	Person(const string &name, int age) : name(name), age(age) {}

	void displayInfo() const
	{
		cout << "Name: " << name << ", Age: " << age << endl;
	}
};

// Derived class for students
class Student : public Person
{
private:
	string studentID;

public:
	Student(const string &name, int age, const string &studentID)
		: Person(name, age), studentID(studentID) {}

	void displayInfo() const
	{
		Person::displayInfo(); // Call the base class method
		cout << "Student ID: " << studentID << endl;
	}
};

// Derived class for teachers
class Teacher : public Person
{
private:
	string subject;

public:
	Teacher(const string &name, int age, const string &subject)
		: Person(name, age), subject(subject) {}

	void displayInfo() const
	{
		Person::displayInfo(); // Call the base class method
		cout << "Subject: " << subject << endl;
	}
};

int main()
{
	// Create a Student object
	Student student("Alice", 20, "S12345");
	student.displayInfo();

	// Create a Teacher object
	Teacher teacher("Mr. Smith", 35, "Mathematics");
	teacher.displayInfo();

	return 0;
}
