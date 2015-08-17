/*
 * Author:		Ashish Verma
 * Title:		delete nodes on paths whose sum is less than 'k'
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

bool deleteNodes(Node *root, int k, int pathSum) {
	if (root == NULL) {
		if (pathSum >= k) {
			return false;
		} else {
			return true;
		}
	}

	pathSum += root->data;
	if (pathSum >= k) {
		return false;
	}

	bool isDeletableLeft = deleteNodes(root->left, k, pathSum);
	bool isDeletableRight = deleteNodes(root->right, k, pathSum);
	if (isDeletableLeft) {
		root->left = NULL;
	}
	if (isDeletableRight) {
		root->right = NULL;
	}
	if (isDeletableLeft && isDeletableRight) {
		delete root;
		return true;
	}
	return false;
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);

	inorder(root);
	cout << endl;
	deleteNodes(root, 5, 0);
	inorder(root);
	cout << endl;

	return 0;
}
