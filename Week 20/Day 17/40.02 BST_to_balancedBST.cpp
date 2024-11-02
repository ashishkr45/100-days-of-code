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

void bstToVec(Node* root, vector<int> &nodes) {
	if(root == NULL)
		return;
	bstToVec(root->left, nodes);
	nodes.push_back(root->data);
	bstToVec(root->right, nodes);

}

Node* bstTobalanced(Node* root) {
	vector<int> nodes;
	bstToVec(root, nodes);

	return balancedBst(nodes, 0, nodes.size()-1);
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

int main() {
	Node* node1 = new Node(6);
	Node* node2 = new Node(5);
	Node* node3 = new Node(4);
	Node* node4 = new Node(3);
	Node* node5 = new Node(7);
	Node* node6 = new Node(8);
	Node* node7 = new Node(9);
	node1->left = node2;
	node2->left = node3;
	node3->left = node4;
	node1->right = node5;
	node5->right = node6;
	node6->right = node7;

	node1 = bstTobalanced(node1);

	preorder(node1);
	cout<<endl;
	return 0;
}