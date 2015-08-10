/*
 * Author:		Ashish Verma
 * Title:		double tree, duplicate each node as its left child
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

void doubleTree(Node *root) {
	if (root == NULL) {
		return;
	}
	doubleTree(root->left);
	doubleTree(root->right);
	Node *n = newNode(root->data);
	n->left = root->left;
	root->left = n;
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	inorderTraversal(root);
	cout << endl;
	doubleTree(root);
	inorderTraversal(root);
	cout << endl;
	return 0;
}
