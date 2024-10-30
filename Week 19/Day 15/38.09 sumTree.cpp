#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

static int it = -1;
Node* buildTree(vector<int>& nodes) {
    it++;
    if (it >= nodes.size() || nodes[it] == -1)
        return NULL;

    Node* root = new Node(nodes[it]);
    root->left = buildTree(nodes);
    root->right = buildTree(nodes);

    return root;
}

void levelOrder(Node *root)
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

int sumTree(Node* root) {
    if (root == NULL)
        return 0;

    int leftOld = sumTree(root->left);
    int rightOld = sumTree(root->right);

    int currOld = root->data;

    root->data = leftOld + rightOld;

    if (root->left != NULL)
        root->data += root->left->data;

    if (root->right != NULL)
        root->data += root->right->data;

    return currOld;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    sumTree(root);
    levelOrder(root);

    return 0;
}