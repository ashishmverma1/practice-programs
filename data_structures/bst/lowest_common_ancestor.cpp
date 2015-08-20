/*
 * Author:		Ashish Verma
 * Title:		lowest common ancestor
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

Node *insert(Node *root, int val) {
	Node *n = newNode(val);
	if (root == NULL) {
		return n;
	}
	Node *p = root;
	while (true) {
		if (val < p->data) {
			if (p->left == NULL) {
				p->left = n;
				break;
			} else {
				p = p->left;
			}
		} else {
			if (p->right == NULL) {
				p->right = n;
				break;
			} else {
				p = p->right;
			}
		}
	}
	return root;
}

int lca(Node *root, int a, int b) {
	if (root == NULL) {
		return -1;
	}
	if (root->data < a && root->data < b) {
		return lca(root->right, a, b);
	} else if (root->data > a && root->data > b) {
		return lca(root->left, a, b);
	}
	return root->data;
}

int main() {

	Node *root = NULL;
	root = insert(root, 8);
	root = insert(root, 10);
	root = insert(root, 3);
	root = insert(root, 1);
	root = insert(root, 6);
	root = insert(root, 14);
	root = insert(root, 4);
	root = insert(root, 7);
	root = insert(root, 13);

	cout << lca(root, 7, 1);

	return 0;
}
