#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

/*we'll fallow level order traversal*/
void bottomView(Node* root){
	queue<pair<Node*, int>> Q; //(Node, horizontal dist.)
	map<int, int> m; //(horizontal dist., node->data)

	Q.push(make_pair(root, 0)); //hori dist(root) = 0

	while (!Q.empty())
	{
		pair<Node*, int> curr = Q.front();
		Q.pop();

		Node* currNode = curr.first;
		int currHD = curr.second;

		/*latest one we'l; get the unique bottom nodes of the tree*/
		m[currHD] = currNode->data; //upadating the value of currHd by the lates one

		if(currNode->left != NULL)  {
			pair<Node*, int> leftChild = make_pair(currNode->left, currHD - 1);
			Q.push(leftChild); //adding the newNodes
		}

		if(currNode->right != NULL){
			pair<Node*, int> rightChild = make_pair(currNode->right, currHD + 1);
			Q.push(rightChild); //adding the newNodes
		}
	}
	
	for(auto it: m){
		cout<<it.second<<" ";
	}
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
	bottomView(root);
	return 0;
}