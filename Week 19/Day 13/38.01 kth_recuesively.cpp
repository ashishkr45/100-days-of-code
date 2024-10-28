#include<iostream>
#include<vector>
#include<queue>

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

static int i = -1;
Node* buildTree(vector<int> nodes){
	i++;
	if(nodes[i] == -1)
		return NULL;
	Node* root = new Node(nodes[i]);
	root->left = buildTree(nodes);
	root->right = buildTree(nodes);
	return root;
}

void kthHelper(Node* root, int k, int currLevel){
	if(root == NULL) return;

	if(currLevel == k){
		cout << root->data << " ";
		return;
	}

	kthHelper(root->left, k, currLevel+1);
	kthHelper(root->right, k, currLevel+1);
}

void kthLevel(Node* root, int k){ //o(n)
	kthHelper(root, k, 1);
	/*if in some qns(letcode main_fn not given) we are needing some ext paramenter
	which isn't given in the pre-made fn then, we'll make our own fn and call it inside the
	given fn.
	*/
	cout<<endl;
}

int main(){
	vector<int> nodes = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
	/*
	     1
       /   \
      2     3
     / \     \
    4   5     6
       /
      7
	
	*/
	Node* root = buildTree(nodes);

	int k;
	cin>>k;
	kthLevel(root, k);

	return 0;
}