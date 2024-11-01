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
	if (root == NULL){
		Node* root = new Node(val);
		return root;
	}
	if (root->data > val){
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

void inOrder(Node* root){
	if(root == NULL) return;
	inOrder(root->left);
	cout << root->data <<"\t";
	inOrder(root->right);
}

void search(Node* root, int key){
	if(root == NULL){
		cout << "INVALID\n" << endl;
		return;
	}
	if(root->data == key){
		cout<<"Key Found!!\n"<<endl;
	} else if(root->data < key){
		search(root->right, key);
	} else {
		search(root->left, key);
	}
}

Node* successor(Node* root) {
	while (root->left != NULL)
		root = root->left;
	return root;
}

Node* delNode(Node* root, int key){
	if(root == NULL) return NULL;
	if(root->data > key)
		root->left = delNode(root->left, key);
	else if(root->data < key)
		root->right = delNode(root->right, key);
	else{
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		} if(root->left == NULL || root->right == NULL) {
			return root->left == NULL ? root->right : root->left;
		} else {
			Node* success = successor(root->right);
			root->data = success->data;
			root->right = delNode(root->right, success->data);
		}
	}
	return root;
}

void printInRange(Node* root, int si, int ei){
	if(root == NULL){
		return;
	}
	if(root->data >= si && root->data <= ei){
		printInRange(root->left, si, ei);
		cout << root->data <<" ";
		printInRange(root->right, si, ei);
	} else if(root->data < si) {
		printInRange(root->right, si, ei);
	} else { //if(root->data > ei)
		printInRange(root->left, si, ei);
	}
}

void printVec(vector<int> nodes) {
	for (int i = 0; i <(int) nodes.size(); i++){
		cout<< nodes[i] << " ";
	}
	cout<<endl;
	return;
}

void pathHelper(Node* root, vector<int> &nodes){
	if(root == NULL)
		return;

	nodes.push_back(root->data);

	if(root->left == NULL && root->right == NULL){
		printVec(nodes);
		nodes.pop_back();
		return;
	}

	pathHelper(root->left, nodes);
	pathHelper(root->right, nodes);

	nodes.pop_back();
}

void pathOleaf(Node* root) {
	vector<int> nodes;
	pathHelper(root, nodes);
	return;
}

int main()
{
	vector<int> nodes = {8, 5, 3, 1, 4, 6, 10, 11, 14};
	Node* root = buildBST(nodes);
	pathOleaf(root);
	return 0;
}