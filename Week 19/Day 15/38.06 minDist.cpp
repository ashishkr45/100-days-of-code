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

int dist(Node* root, int n){
	if(root == NULL) 
		return -1;
	if(root->data == n) 
		return 0;

	int leftDist = dist(root->left, n);

	if(leftDist != -1) 
		return leftDist + 1;

	int rightDist = dist(root->right, n);

	if(rightDist != -1) 
		return rightDist + 1;

	return -1;
}

int minDist(Node* root, int n1, int n2){
	Node* nodeLCA = LCA(root, n1, n2);

	int dist1 = dist(nodeLCA, n1);
	int dist2 = dist(nodeLCA, n2);

	return dist1 + dist2;
}

int main() {
	vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
	Node* root = buildTree(nodes);

	int n1 = 5, n2 = 3;
	Node* nodeLCA = LCA(root, n1, n2);
	cout<<"Lowest Commen Ancestor: "<<nodeLCA->data <<endl;

	cout<<"Distance between "<<n1<<" and "<<n2<<": "<<minDist(root, n1, n2)<<endl;

	return 0;
}