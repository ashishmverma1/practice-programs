/*
 * Author:		Ashish Verma
 * Title:		find size of minimum vertex cover of binary tree
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

int vertexCover(Node *root, map<Node*, int> *m) {
	if (root == NULL || (root->left == NULL && root->right == NULL)) {
		return 0;
	}
	if (m->find(root) != m->end()) {
		return m->find(root)->second;
	}

	int includingRoot = 1 + vertexCover(root->left, m) + vertexCover(root->right, m);

	int excludingRoot = 0;
	if (root->left != NULL) {
		excludingRoot += 1 + vertexCover(root->left->left, m) + vertexCover(root->left->right, m);
	}
	if (root->right != NULL) {
		excludingRoot += 1 + vertexCover(root->right->left, m) + vertexCover(root->right->right, m);
	}

	m->insert(pair<Node*, int>(root, min(includingRoot, excludingRoot)));
	return m->find(root)->second;
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);

	cout << vertexCover(root, new map<Node*, int>());

	return 0;
}
