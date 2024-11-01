#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) : data(data), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val) {
	if (root == NULL) {
		Node* newNode = new Node(val);
		return newNode;
	}
	if (root->data > val) {
		root->left = insert(root->left, val);
	} else {
		root->right = insert(root->right, val);
	}
	return root;
}

Node* buildBST(vector <int> nodes){
	Node* root = NULL;
	for (int i = 0; i < (int)nodes.size(); i++)
		root = insert(root, nodes[i]);
	return root;	
}

bool BSTvalidater(Node* root, Node* min, Node* max) {
	if(root == NULL) 
		return true;
	
	if(min != NULL && root->data < min->data)
		return false;
	if(max != NULL && root->data > max->data)
		return false;
	
	return BSTvalidater(root->left, min, root) 
		&& BSTvalidater(root->right, root, max);
}

bool BST_cap(Node* root) {
	return BSTvalidater(root, NULL, NULL);
}

int main()
{
	vector<int> nodes = {10, 5, 15, 12, 20, 8, 7};
	Node* root = buildBST(nodes);

	root->data = 25;
	cout << BST_cap(root);
	return 0;
}