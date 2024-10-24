#include <iostream>
#include <map>
#include <queue>
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

static int idx = -1;
Node* buildTree(vector<int> nodes){
	idx++;
	if(nodes[idx] == -1)
		return NULL;
	Node* root = new Node(nodes[idx]);
	root->left = buildTree(nodes);
	root->right = buildTree(nodes);
	return root;
}

void topView(Node* root) {
	queue<pair<Node*, int>> q; //we storeing (nodes, horizontal_dist)
	map<int, int> m; //(horizontal_dist, node->data) HD is the key

	q.push(make_pair(root, 0));

	while (!q.empty()) {
		pair<Node*, int> curr = q.front();
		q.pop();

		Node* currNode = curr.first; // current Node 
		int currHD = curr.second; //current Node Horizontal Dist.

		if(m.count(currHD) == 0){ //HD is unique, HD -> add in map
			m[currHD] = currNode->data;
		}

		if(currNode->left != NULL){
			pair<Node*, int> leftChild = make_pair(currNode->left, currHD - 1); //going left in noLine = -1
			q.push(leftChild);
		}

		if(currNode->right != NULL){
			pair<Node*, int> rightChild = make_pair(currNode->right, currHD +  1); //going right in noLine = +1
			q.push(rightChild);
		}		
	}
	
	for(auto it: m){
		cout << it.second<<" ";
	}
	cout << endl;
}

int main(){
	vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
	Node* root = buildTree(nodes);

	topView(root);
	return 0;
}