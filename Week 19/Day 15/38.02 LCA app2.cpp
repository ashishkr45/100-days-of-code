#include <iostream>
#include <vector>

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
Node* buildTree(vector <int> nodes){
	it++;
	if(nodes[it] == -1) return NULL;

	Node* root = new Node(nodes[it]);

	root->left = buildTree(nodes);
	root->right = buildTree(nodes);

	return root;
}

Node* LCA(Node* root, int n1, int n2){ //time - O(n), space - O(1)
	if(root == NULL) return NULL;

	if(root->data == n1 || root->data == n2)
		return root;
	
	Node* leftLCA = LCA(root->left, n1, n2);
	Node* rightLCA = LCA(root->right, n1, n2);

	if(leftLCA != NULL && rightLCA != NULL)
		return root;
	return leftLCA == NULL ? rightLCA : leftLCA;
}

int main() {
	vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
	Node* root = buildTree(nodes);

	int n1 = 4, n2 = 5;
	Node* nodeLCA = LCA(root, n1, n2);
	cout<<"Lowest Commen Ancestor: "<<nodeLCA->data <<endl;

	return 0;
}