#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

Node* insert(Node* root, int data) {
	if(root == NULL) {
		root = new Node(data);
		return root;
	}
	if(data < root->data) {
		root->left = insert(root->left, data);
	}else {
		root->right = insert(root->right, data);
	}
	return root;
}

bool find(Node* root, int data) {
	if(root == NULL) {
		return 0;
	}
	if(data == root->data){
		return 1;
	} else if(data < root->data) {
		return find(root->left, data);
	} else {
		return find(root->right, data);
	}
	return 0;
}

void inOrder(Node* root) {
	if(root == nullptr)
		return;
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void preOrder(Node* root) {
	if(root == nullptr) {
		return;
	}
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(Node* root) {
	if(root == nullptr)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

void levelOrder(Node* root) {
	if(root == nullptr) 
		return;

	Node* queue[100];
	int front = 0, rear = 0;
	queue[front++] = root;

	while(front < rear) {
		Node* current = queue[rear++];
		cout << current->data << " ";

		if(current->left != NULL)
			queue[front++] = current->left;
		if(current->right != NULL) 
			queue[front++] = current->right;
	}
	cout << endl;
}

static int idx = -1;

Node* buildBST (Node* root, vector<int> nodes) {
	idx++;
}

int main() {
	cout << "Enter the nodes of tree, -1 to stop\n";

	Node* root = nullptr;

	// int data;
	// cin >> data;
	// while(data != -1) {
	// 	root = insert(root, data);
	// 	cin >> data;
	// }

	vector<int> vec = {5, 2, 89, 69, 88};
	root = buildBSt(vec);

	cout << "Root 69 is: " << find(root, 69) << endl;

	inOrder(root);
	cout << endl;

	preOrder(root);
	cout << endl;

	postOrder(root);
	cout << endl;

	levelOrder(root);
	cout << endl;
	
	return 0;
}