#include<iostream>
using namespace std;

class Node 
{
public:
	int data;
	Node* next;
	Node* prev;

	Node(int data){
		this->data = data;
		prev = next = NULL;
	}	
};

Node* insertBack(Node* head, int num){
	Node* newNode = new Node(num); //node to insert
	if(head == NULL){
		head = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
		return head;
	}else{
		Node* temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;	
		newNode->next = head;
		head->prev = newNode;
		return head;
	}
}

Node* insertFront(Node* head, int data){
	Node* newNode = new Node(data); //node to insert
	if(head == NULL){
		head = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
		return head;
	}else{
		Node* temp = head; //tail-to-be
		while (temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;	
		newNode->next = head;
		head->prev = newNode;
		return newNode;
	}
}

void printNodes(Node* head){
	Node* temp = head;
	if(temp == NULL){
		cout<<"list is empty\n";
		return;
	}

	do{
		cout<<temp->data<<" ";
		temp = temp->next;
	}while(temp != head);
	cout<<endl;	
}

int main(){
	int num = 1;
	Node* head = NULL;

	while (num > 0){
		cin >> num;
		if(num > 0) // Only insert if num is positive
			head = insertFront(head, num);
	}

	insertBack(head, 69);
	
	printNodes(head);

	return 0;	
}