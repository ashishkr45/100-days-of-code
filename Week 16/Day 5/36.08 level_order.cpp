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

class Tree
{
private:
    static int idx;

public:
    Tree()
    {
        idx = -1;
    }

    Node *buildTree(vector<int> nodes)
    {
        idx++;

        if (nodes[idx] == -1)
        {
            return NULL;
        }
        Node *currNode = new Node(nodes[idx]);
        currNode->left = buildTree(nodes);
        currNode->right = buildTree(nodes);

        return currNode;
    }

    void preOrder(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node *root)
    {
        if (root == NULL)
            return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void postOrder(Node *root)
    {
        if (root == NULL)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    void levelOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
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
        cout << endl;
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
};

int Tree::idx = -1;

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Tree t;

    Node *root = t.buildTree(nodes);

    cout << "Root: " << root->data << endl;

    cout << "Pre-Order: ";
    t.preOrder(root);
    cout << endl;

    cout << "In-order: ";
    t.inOrder(root);
    cout << endl;

    cout << "Post-Order: ";
    t.postOrder(root);
    cout << endl;

    cout << "Level Order: ";
    t.levelOrder(root);
    cout << endl;

    cout << "Level Order-vartion: " << endl;
    t.levelOrder_vartion(root);
    cout << endl;

    return 0;
}
