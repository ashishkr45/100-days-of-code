#include<iostream>
#include<vector>
#include<queue>

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

static int i = -1;
Node* buildTree(vector<int> nodes){
	i++;
	if(nodes[i] == -1)
		return NULL;
	Node* root = new Node(nodes[i]);
	root->left = buildTree(nodes);
	root->right = buildTree(nodes);
	return root;
}

void kthLevel(Node* root, int k){
	if(root == NULL)
		return;
	
	int counter = 0; // representing the current level

	queue<Node*> Q;
	Q.push(root);
	Q.push(NULL);

	while (!Q.empty())
	{
		Node* curr = Q.front();
		Q.pop();

		if (curr == NULL) {
            counter++;
            if (counter == k) {
                while (!Q.empty() && Q.front() != NULL) {
                    cout << Q.front()->data << " ";
                    Q.pop();
                }
                cout << endl;
                return;
            }
            if (!Q.empty())
                Q.push(NULL);
		}else{
			if(curr->left != NULL) Q.push(curr->left);
			if(curr->right != NULL) Q.push(curr->right);
		}
	}
	

}

int main(){
	vector<int> nodes = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
	Node* root = buildTree(nodes);

	int k;
	cin>>k;
	kthLevel(root, k);

	return 0;
}