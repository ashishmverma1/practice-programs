/*
 * Author:		Ashish Verma
 * Title:		convert tree to its sum tree
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

void inorderTraversal(Node *root) {
	if (root == NULL) {
		return;
	}
	inorderTraversal(root->left);
	cout << root->data << ' ';
	inorderTraversal(root->right);
}

// returns sum of left and right sub trees
int convertToSumTree(Node *root) {
	if (root == NULL) {
		return 0;
	}
	int oldData = root->data;
	root->data = convertToSumTree(root->left) + convertToSumTree(root->right);
	return oldData + root->data;
}

int main() {

	Node *root = newNode(10);
	root->left = newNode(-2);
	root->right = newNode(6);
	root->left->left = newNode(8);
	root->left->right = newNode(-4);
	root->right->left = newNode(7);
	root->right->right = newNode(5);

	inorderTraversal(root);
	cout << endl;
	convertToSumTree(root);
	inorderTraversal(root);
	return 0;
}
