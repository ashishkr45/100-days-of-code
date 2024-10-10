#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
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

Node *buildTree(vector<int> nodes)
{
	idx++;

	if (nodes[idx] == -1)
		return NULL;

	Node *current = new Node(nodes[idx]);
	current->left = buildTree(nodes);
	current->right = buildTree(nodes);

	return current;
}

void levelOrder(Node *root)
{
	if (root == NULL)
		return;
	queue<Node *> Q;
	Q.push(root);
	Q.push(NULL);

	int sum = 0;

	while (!Q.empty())
	{
		Node *current = Q.front();
		Q.pop();

		if (current == NULL) // figure out this shit
		{
			cout << sum << endl;
			sum = 0;
			if (Q.empty())
				break;
			Q.push(NULL);
		}
		else
		{
			sum += current->data;

			if (current->left != NULL)
			{
				Q.push(current->left);
			}
			if (current->right != NULL)
			{
				Q.push(current->right);
			}
		}
	}
}

int main()
{
	vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

	Node *root = buildTree(nodes);

	levelOrder(root);

	return 0;
}
