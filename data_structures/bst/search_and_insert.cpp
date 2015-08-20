/*
 * Author:		Ashish Verma
 * Title:		bst search and insert
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

bool search(Node *root, int val) {
	Node *p = root;
	while (p != NULL) {
		if (p->data == val) {
			return true;
		} else if (p->data < val) {
			p = p->right;
		} else {
			p = p->left;
		}
	}
	return false;
}

int main() {

	Node *root = NULL;
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 4);
	root = insert(root, 6);
	root = insert(root, 7);
	root = insert(root, 8);
	root = insert(root, 10);
	root = insert(root, 13);
	root = insert(root, 14);

	inorder(root);
	cout << endl;

	cout << search(root, 9);

	return 0;
}
