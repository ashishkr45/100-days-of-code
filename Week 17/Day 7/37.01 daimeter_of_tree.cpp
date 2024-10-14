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

static int idx = -1;

Node *build_tree(vector<int> nodes)
{
	idx++;
	if (nodes[idx] == -1)
		return NULL;

	Node *currNode = new Node(nodes[idx]);
	currNode->left = build_tree(nodes);
	currNode->right = build_tree(nodes);
	return currNode;
}

int height(Node *root)
{
	if (root == NULL)
		return 0;

	int leftHt = height(root->left);
	int rightHt = height(root->right);

	int currHt = max(leftHt, rightHt) + 1;
	return currHt;
}

int diameter(Node *root)
{
	if (root == NULL)
		return 0;
	int currDia = height(root->left) + height(root->right) + 1;
	int leftDia = diameter(root->left);
	int rightDia = diameter(root->right);
	return max(currDia, max(leftDia, rightDia));
}

int main()
{
	vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, 6, -1, 7, -1, 8, -1, -1, 3, -1, -1};

	Node *root = build_tree(nodes);
	cout << "Max Diameter: " << diameter(root) << endl;

	return 0;
}