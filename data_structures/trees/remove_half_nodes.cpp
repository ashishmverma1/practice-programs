/*
 * Author:		Ashish Verma
 * Title:		remove all the half nodes
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

Node* removeHalfNodes(Node *root) {
	if (root == NULL) {
		return NULL;
	}
	if (root->left == NULL && root->right == NULL) {
		return root;
	}

	root->left = removeHalfNodes(root->left);
	root->right = removeHalfNodes(root->right);

	Node *temp = NULL;

	if (root->left == NULL) {
		temp = root->right;
		delete root;
		return temp;
	}
	if (root->right == NULL) {
		temp = root->left;
		delete root;
		return temp;
	}

	return root;
}

int main() {
	Node *root = newNode(2);
	root->left = newNode(7);
	root->right = newNode(5);
	root->left->right = newNode(6);
	root->left->right->left = newNode(1);
	root->left->right->right = newNode(11);
	root->right->right = newNode(9);
	root->right->right->left = newNode(4);

	inorder(root);
	cout << endl;
	root = removeHalfNodes(root);
	inorder(root);
	cout << endl;

	return 0;
}
