#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;

public:
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

static int idx = -1;

Node *buildTree(vector<int> nodes)
{
	idx++;
	if (nodes[idx] == -1)
		return NULL;
	Node *currNode = new Node(nodes[idx]);
	currNode->left = buildTree(nodes);
	currNode->right = buildTree(nodes);

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

void levelOrder_vartion(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	queue<Node *> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty())
	{
		Node *curr = q.front();
		q.pop();

		if (curr == NULL)
		{
			cout << endl;
			if (q.empty())
				break;
			q.push(NULL); // for the lext layer
		}
		else
		{
			cout << curr->data << " ";

			if (curr->left != NULL)
			{
				q.push(curr->left);
			}

			if (curr->right != NULL)
			{
				q.push(curr->right);
			}
		}
	}
}

int nodeCount(Node *root)
{
	if (root == NULL)
		return 0;
	int leftC = nodeCount(root->left);
	int rightC = nodeCount(root->right);
	return leftC + rightC + 1;
}

int nodeSum(Node *root)
{
	if (root == NULL)
		return 0;
	int leftSum = nodeSum(root->left);
	int rightSum = nodeSum(root->right);

	int currSum = leftSum + rightSum + root->data;
	cout << "Sum =" << currSum << endl;
	return currSum;
}

int main()
{
	vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};

	Node *root = buildTree(nodes);
	levelOrder_vartion(root);

	cout << "Heigth of the tree: " << height(root) << endl;
	cout << "Total no. of nodes: " << nodeCount(root) << endl;
	cout << "Sum of all nodes: " << nodeSum(root) << endl;
	return 0;
}