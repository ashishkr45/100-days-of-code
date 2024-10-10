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
/*this idx will be updating continusily so that we can get the data from the main function*/
static int idx = -1;

void preOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void InOrder(Node *root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node *BuildTree(vector<int> nodes)
{
    idx++;

    if (nodes[idx] == -1)
    {
        return NULL;
    }

    Node *currNode = new Node(nodes[idx]); // creating the node
    currNode->left = BuildTree(nodes);     // call for the left-subtree
    currNode->right = BuildTree(nodes);    // call for the right-subtree

    return currNode;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = BuildTree(nodes);

    cout << "Root: " << root->data << endl; // 1

    cout << "Pre-Order: ";
    preOrder(root);
    cout << endl;

    cout << "In-order: ";
    InOrder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    return 0;
}