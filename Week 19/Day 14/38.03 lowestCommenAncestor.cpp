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

static int it = -1;
Node* buildTree(vector<int> nodes){
	it++;

	if (nodes[it] == -1)
		return NULL;
	
	Node* root = new Node(nodes[it]);
	root->left = buildTree(nodes);
	root->right = buildTree(nodes);

	return root;
}

bool CommenAncestorPath(Node* root, int n, vector<int> &path){
	if(root == NULL){
		 return false;
	}

	path.push_back(root->data); 

	if(root->data == n){
		return true;
	}

	bool isLeft = CommenAncestorPath(root->left, n, path);
	bool isright = CommenAncestorPath(root->right, n, path);

	if(isLeft || isright){
		return true;
	}

	path.pop_back();
	return false;
}

int LCA(Node* root, int n1, int n2){
	vector<int> path1;
	vector<int> path2;

	CommenAncestorPath(root, n1, path1);
	CommenAncestorPath(root, n2, path2);
	
	int lca = -1;
	for (int i = 0, j = 0; i <(int) path1.size() && j <(int) path2.size(); i++, j++){
		if(path1[i] != path2[j]) return lca;

		lca = path1[i];
	}
	
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

	int n1, n2;
	cin>>n1>>n2;
	
	cout<<LCA(root, n1, n2);

	return 0;
}