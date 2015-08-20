/*
 * Author:		Ashish Verma
 * Title:		bst search, insert, delete
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

Node *getMinValueNode(Node *root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node *deleteNode(Node *root, int val) {
	if (root == NULL) {
		return NULL;
	}
	if (root->data == val) {
		// both are NULL
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}

		// either of them are NULL
		if (root->left == NULL) {
			Node *temp = root->right;
			delete root;
			return temp;
		}
		if (root->right == NULL) {
			Node *temp = root->left;
			delete root;
			return temp;
		}

		// none of them are NULL
		Node *temp = getMinValueNode(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);

	} else if (root->data > val) {
		root->left = deleteNode(root->left, val);
	} else {
		root->right = deleteNode(root->right, val);
	}
	return root;
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
	deleteNode(root, 14);
	inorder(root);

	return 0;
}
