/*
? BST properties:
-left subTree < current node
-right subTree > current node

*value of all the nodes must be unique to satisfy the above property
	we can add duplicate nodes but it should follow then above rules.

*-Inorder Traversal of BST gives a sorted(assending) sequence(or array).

* Deletion of a Node
	1)No child(leaf Node)
	2)1 child
	3)2 children

	*1) No child Node(leaf Node): 
		-search for the Node
		-find which of the above cases it is
	*3) Now we have 3 cases
		i. root is a leaf node, then just return NULL to its parent(return NULL)
		ii. root's have a child, whichever child is not-null we'll return that(return root->left)
		iii. root have two childs, then we'll replace that node with the, Inorder Successor		
	
	!Inorder Successor
	Inorder Successor of that root node will be bigger than that of the currRoot
	*that means I'll be in the right subTree of the root
	*it'll be the left most part of the rigth_subTree, which donen't has left child(root->left == NULL)

*/

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;

	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

void inOrder(Node* root){
	if(root == NULL)
		return;

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void preOrder(Node* root){
	if(root == NULL)
		return;

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

bool search(Node* root, int key){
	if(root == NULL)
		return false;  
	if(root->data == key)
		return true;
	else if (root->data > key)
		return search(root->left, key);
	else
		return search(root->right, key);
}

Node* Successor(Node* root){
	while (root->left != NULL)
		root = root->left;
	return root;
}

Node* delNode(Node* root, int key){
	if(root == NULL)
		return NULL;
	if (root->data > key) //left-subTree
		root->left = delNode(root->left, key);
	else if(root->data < key) //right-subTree
		root->right = delNode(root->right, key);
	else{
		if (root->left == NULL && root->right == NULL){ //case 1: 0 children
			delete root;
			return NULL;
		}
		if (root->left == NULL || root->right == NULL){ //case 2: 1 children
			return root->left == NULL ? root->right : root->right;
		}
		// case 3: 2 children
		Node* successor = Successor(root->right);
		root->data = successor->data; // we are changing root->data with Inorder Successor
		//now we are deleting the actual Successor from the tree here and storing it in right of root.
		root->right = delNode(root->right, successor->data);
		return root;
	}
	return root;
}

Node *insert(Node *root, int val) // O(logn)
{
	if (root == NULL)
	{
		root = new Node(val);
		return root;
	}

	if (val < root->data) // left subTree
	{
		root->left = insert(root->left, val);
	}
	else // right subTree
	{
		root->right = insert(root->right, val);
	}
	return root;
}

Node* Build_BST(vector<int> nodes)
{
	Node *root = NULL;
	for (int i = 0; i < (int)nodes.size(); i++)
	{
		root = insert(root, nodes[i]);
	}
	return root;
}

int main()
{
	vector<int> nodes = {8, 5, 3, 1, 4, 6, 10, 11, 14};
	Node* root = Build_BST(nodes);
	inOrder(root);
	cout<<endl;

	preOrder(root);
	cout<<endl;

    cout << (search(root, 9) ? "found in the BST!" : "not found in the BST!") << endl;

	delNode(root, 5);
	inOrder(root);
	return 0;
}