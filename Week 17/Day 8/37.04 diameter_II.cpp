#include <iostream>
#include <vector>
#include <queue>
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

Node *buildTree(vector<int> nodes)
{
	if (nodes.empty() || nodes[0] == -1) // corner cases, still a thing?
		return NULL;

	Node *root = new Node(nodes[0]);

	queue<Node *> q;
	q.push(root);

	int idx = 1;

	while (idx < (int)nodes.size())
	{
		Node *current = q.front();
		q.pop();

		if (idx < (int)nodes.size() && nodes[idx] != -1)
		{
			current->left = new Node(nodes[idx]);
			q.push(current->left);
		}
		idx++;

		if (idx < (int)nodes.size() && nodes[idx] != -1)
		{
			current->right = new Node(nodes[idx]);
			q.push(current->right);
		}
		idx++;
	}
	return root;
}

void preOrder(Node *root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

pair<int, int> Dia_n_Ht(Node *root)
{
	if (root == NULL)
		return make_pair(0, 0);

	pair<int, int> leftInfo = Dia_n_Ht(root->left); // pair(diameter, height)
	pair<int, int> rightInfo = Dia_n_Ht(root->right);

	int finalDia = max(leftInfo.second + rightInfo.second + 1, max(leftInfo.first, rightInfo.first));
	int finalHt = max(leftInfo.second, rightInfo.second) + 1;

	return make_pair(finalDia, finalHt);
}

int main()
{
	vector<int> nodes;

	int num; // container for the nodes data(initailly)

	while (cin >> num && num != -1)
	{
		nodes.push_back(num);
	}

	Node *root = buildTree(nodes);

	preOrder(root);
	cout << endl;

	cout << "Height: " << Dia_n_Ht(root).second << endl;
	cout << "Diameter: " << Dia_n_Ht(root).first << endl;

	return 0;
}