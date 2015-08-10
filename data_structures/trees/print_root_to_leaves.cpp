/*
 * Author:		Ashish Verma
 * Title:		print path root to all leaves
 *
 */

#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define debug(x) cout << "DEBUG: " << x << endl

using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

Node* newNode(int data) {
	Node *n = new Node;
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

void printRootToLeaf(Node *root, vector<Node*> path) {
	if (root == NULL) {
		return;
	}

	path.push_back(root);

	if (root->left == NULL && root->right == NULL) {
		for (unsigned int i = 0; i < path.size(); i++) {
			cout << path[i]->data << ' ';
		}
		cout << endl;
	}

	printRootToLeaf(root->left, path);
	printRootToLeaf(root->right, path);
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printRootToLeaf(root, vector<Node*>());

	return 0;
}
