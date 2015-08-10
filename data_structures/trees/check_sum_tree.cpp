/*
 * Author:		Ashish Verma
 * Title:		check if sum tree
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
bool isSumTree(Node *root) {
	if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
		return true;
	}
	if ((root->left == NULL && root->right->data != root->data)
			|| (root->right == NULL && root->left->data != root->data)
			|| (root->left->data + root->right->data != root->data)) {
		return false;
	}
	return isSumTree(root->left) && isSumTree(root->right);
}

int main() {

	Node *root = newNode(12);
	root->left = newNode(9);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << isSumTree(root);
	return 0;
}
