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

int main()
{
	vector<int> nodes = {8, 5, 3, 1, 4, 6, 10, 11, 14};
	Node* root = buildBST(nodes);
	inOrder(root);
	cout<<endl;

	search(root, 11);

	delNode(root, 5);
	inOrder(root);
	return 0;
}

int main()
{
	vector<int> nodes = {8, 5, 3, 1, 4, 6, 10, 11, 14};
	Node* root = buildBST(nodes);
	printInRange(root, 4, 10);
	return 0;
}