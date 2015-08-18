/*
 * Author:		Ashish Verma
 * Title:		print nodes at distance k from leaf nodes
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

void inorder(Node *root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << ' ';
	inorder(root->right);
}

void printNodes(Node *root, unsigned int k, vector<Node*> path) {
	if (root == NULL) {
		return;
	}

	path.push_back(root);

	if (root->left == NULL && root->right == NULL) {
		if (path.size() > k) {
			cout << path[path.size() - k - 1]->data << ' ';
		}
		return;
	}

	printNodes(root->left, k, path);
	printNodes(root->right, k, path);
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);

	printNodes(root, 3, vector<Node*>());

	return 0;
}
