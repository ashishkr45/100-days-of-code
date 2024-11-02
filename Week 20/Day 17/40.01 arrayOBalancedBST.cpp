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

Node* insert(Node* root, int value) {
	if(root == NULL) {
		Node* root = new Node(value);
		return root;
	} if(root->data > value) {
		root->left = insert(root->left, value);
	} else { //if(root->data < value)
		root->right = insert(root->right, value);
	}
	return root;
}

Node* buildBstTree(vector<int> nodes) {
	Node* root = NULL;
	for (int i = 0; i < nodes.size(); i++) {
		root = insert(root, nodes[i]);
	}
	return root;
}

Node* balancedBst(vector<int> nodes, int si, int ei) {
	if(si > ei) {
		return NULL;
	}
	int mid = si + (ei - si) / 2;
	Node* currNode = new Node(nodes[mid]);

	currNode->left = balancedBst(nodes, si, mid-1);
	currNode->right = balancedBst(nodes, mid+1, ei);

	return currNode;
}

void preorder (Node* root) {
	if(root == NULL){
		cout<< " NULL " ;
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

int main()
{
	vector<int> nodes = {-10,-3,0,5,9};
	Node* root = balancedBst(nodes, 0, nodes.size() - 1);

	
	preorder(root);
	return 0;
}