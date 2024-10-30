#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data){
		this->data = data;
		left = right = NULL;
	}
};

static int it = -1;
Node* buildTree(vector<int> nodes) {
	it++;
	if(nodes[it] == -1)
		return NULL;
	
	Node* root = new Node(nodes[it]);
	root->left = buildTree(nodes);
	root->right = buildTree(nodes);

	return root;
}

int kthAncestor(Node* root, int k, int n) { // O(n)
	if(root == NULL)
		return -1;
	
	if(root->data == n)
		return 0;

	int leftDist = kthAncestor(root->left, k, n);
	int rightDist = kthAncestor(root->right, k, n);

	if(leftDist == -1 && rightDist == -1)
		return -1;
	
	int validDist = leftDist == -1 ? rightDist : leftDist;

	if(validDist + 1 == k)
		cout << "Kth Ancestor: " << root->data << endl;
	
	return validDist + 1;
}

int main() {
	vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
	Node* root = buildTree(nodes);

	kthAncestor(root, 1, 6);

	return 0;
}