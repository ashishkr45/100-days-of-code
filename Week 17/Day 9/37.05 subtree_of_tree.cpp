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

static int idx = -1; // iterator for (static)recurstion

Node *buildTree(vector<int> nodes)
{
	idx++;
	if (nodes[idx] == -1)
		return NULL;
	Node *root = new Node(nodes[idx]);
	root->left = buildTree(nodes);
	root->right = buildTree(nodes);
	return root;
}

bool is_Identical(Node *root1, Node *root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;
	if (root1 == NULL || root2 == NULL)
		return false;
	if (root1->data != root2->data)
		return false;

	return is_Identical(root1->left, root2->right) && is_Identical(root1->right, root2->right);
}

bool subTree(Node *root, Node *subRoot)
{
	if (root == NULL && subRoot == NULL)
	{
		return true;
	}
	else if (root == NULL || subRoot == NULL)
	{
		return false;
	}

	if (root->data == subRoot->data)
	{
		/*figuring out deep-shit*/
		if (is_Identical(root, subRoot))
			return true;
	}
	bool isLeftSubTree = subTree(root->left, subRoot);

	if (!isLeftSubTree)
		subTree(root->right, subRoot);
	return true;
}

int main()
{
	vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1}; // tree data

	Node *root = buildTree(nodes);

	Node *subTreeRoot = new Node(2);
	subTreeRoot->left = new Node(4);
	subTreeRoot->right = new Node(5);

	cout << (subTree(root, subTreeRoot) ? "Subtree exists!" : "Subtree does not exist!") << endl;

	return 0;
}