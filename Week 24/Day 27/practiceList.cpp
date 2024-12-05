#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

Node* push_front(Node* head, int data) {
	Node* newNode = new Node(data);
	if (head == NULL) {
		head = newNode;
		return newNode;
	}

	newNode->next = head;
	return newNode;
}

Node* push_back(Node* head, int data) {
	Node* newNode = new Node(data);
	if (head == NULL) {
		head = newNode;
		return newNode;
	}

	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	return head;
}

Node* delete_back(Node* head) {
	if (head == NULL) { 
		return NULL;
	}
	if (head->next == NULL) { 
		delete head;
		return NULL;
	}

	Node* temp = head;
	while (temp->next->next != NULL) {
		temp = temp->next;
	}

	delete temp->next;
	temp->next = nullptr;
	return head;
}

Node* delete_front(Node* head) {
	if (head == NULL) { 
		return NULL;
	}

	Node* temp = head->next;
	delete head;
	return temp;
}

void printList(Node* head) {
	if (head == NULL) {
		return;
	}

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}

	return;
}

int main() {
	int size;
	cin >> size;

	Node* head = NULL;

	for (int i = 0; i < size; i++) {
		int data;
		cin >> data;
		head = push_back(head, data);
	}

	printList(head);

	return 0;
}
