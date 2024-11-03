#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Node {
public:	
	int data;
	Node* left;
	Node* right;

	Node(int data) : data(data), left(NULL), right(NULL) {}
};

struct Info
{
	bool isBSt;
	int min;
	int max;
	int sz;

	Info(bool bst, int min, int max, int size) : isBSt(bst), min(min), max(max), sz(size) {}
};

static int maxSize = 0;

Info* largestBST(Node* root) {
	if(root == NULL) {
		return new Info(true, INT_MAX, INT_MIN, 0);
	}

	// if(root == NULL) return NULL;
	if(root->left == NULL && root->right == NULL){
		maxSize = max(maxSize, 1); 
		return new Info(true, root->data, root->data, 1);
	}

	Info* leftInfo = largestBST(root->left);
	Info* rightInfo = largestBST(root->right);

	int currMin = min(root->data, min(leftInfo->min, rightInfo->min));
	int currMax = max(root->data, max(leftInfo->max, rightInfo->max));
	int currSz = leftInfo->sz + rightInfo->sz + 1;

	if(leftInfo->isBSt && rightInfo->isBSt
		&& root->data > leftInfo->max 
		&& root->data < rightInfo->min) {
			maxSize = max(maxSize, currSz);
			return new Info(true, currMin, currMax, currSz);
	} 
	return new Info(false, currMin, currMax, currSz);
}

int main() {
	Node* root = new Node(50);
	root->left = new Node(30);
	root->left->left = new Node(5);
	root->left->left->left = new Node(20);

	root->right = new Node(60);
	root->right->left = new Node(45);
	root->right->right = new Node(70);
	root->right->right->left = new Node(65);
	root->right->right->right = new Node(80);

	largestBST(root);
	cout<<"Max BST: " << maxSize <<endl;

	return 0;
}