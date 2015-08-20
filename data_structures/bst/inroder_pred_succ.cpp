/*
 * Author:		Ashish Verma
 * Title:		get inorder successor and predecessor
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

void getInorderSuccessorPred(Node *root, int val, int &prev, int &next) {
	if (root == NULL) {
		return;
	}
	getInorderSuccessorPred(root->left, val, prev, next);
	if (root->data < val) {
		prev = max(prev, root->data);
	} else if (root->data > val) {
		next = min(root->data, next);
	}
	getInorderSuccessorPred(root->right, val, prev, next);
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

	int prev = INT_MIN;
	int next = INT_MAX;
	getInorderSuccessorPred(root, 14, prev, next);
	if (prev != INT_MIN) {
		cout << "P: " << prev << endl;
	}
	if (next != INT_MAX) {
		cout << "S: " << next << endl;
	}

	return 0;
}
