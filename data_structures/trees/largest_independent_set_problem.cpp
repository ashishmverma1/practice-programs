/*
 * Author:		Ashish Verma
 * Title:		Largest Independent Set Problem (largest set of nodes such that none has common edge
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
	int lisp;
};

Node* newNode(int data) {
	Node *n = new Node;
	n->data = data;
	n->left = n->right = NULL;
	n->lisp = 0;
	return n;
}

int LISP(Node *root) {
	if (root == NULL) {
		return 0;
	}
	if (root->lisp) {
		return root->lisp;
	}
	if (root->left == NULL && root->right == NULL) {
		root->lisp = 1;
		return 1;
	}

	int lispIncludingRoot, lispExcludingRoot;
	lispExcludingRoot = LISP(root->left) + LISP(root->right);
	lispIncludingRoot = 1;
	if (root->left != NULL) {
		lispIncludingRoot += LISP(root->left->left);
		lispIncludingRoot += LISP(root->left->right);
	}
	if (root->right != NULL) {
		lispIncludingRoot += LISP(root->right->left);
		lispIncludingRoot += LISP(root->right->right);
	}
	root->lisp = max(lispExcludingRoot, lispIncludingRoot);
	return root->lisp;
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->right = newNode(8);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);
	root->left->right->right = newNode(7);
	cout << LISP(root) << endl;
	return 0;
}
