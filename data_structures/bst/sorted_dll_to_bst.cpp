/*
 * Author:		Ashish Verma
 * Title:		sorted dll to balanced bst
 *
 */

#include <cmath>
#include <cstdio>
#include <climits>
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

Node *dllInsert(Node *root, int data) {
	Node *n = newNode(data);
	if (root == NULL) {
		return n;
	}

	Node *p = root;
	while (p->right != NULL) {
		p = p->right;
	}
	p->right = n;
	n->left = p;
	return root;
}

Node *getDllMiddle(Node *root) {
	if (root == NULL) {
		return NULL;
	}
	Node *p = root;
	Node *q = root->right;
	while (q != NULL && q->right != NULL) {
		p = p->right;
		q = q->right->right;
	}
	return p;
}

Node *dllToBst(Node *root) {
	if (root == NULL) {
		return NULL;
	}

	Node *left, *mid, *right;
	mid = getDllMiddle(root);

	right = mid->right;
	if (mid->right != NULL) {
		mid->right->left = NULL;
	}

	if (root == mid) {
		left = NULL;
	} else {
		left = root;
		mid->left->right = NULL;
	}

	mid->left = dllToBst(left);
	mid->right = dllToBst(right);
	return mid;
}

int main() {

	Node *root = NULL;
	for (int i = 1; i <= 7; i++) {
		root = dllInsert(root, i);
	}
	root = dllToBst(root);
	inorder(root);

	return 0;
}
