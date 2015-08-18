/*
 * Author:		Ashish Verma
 * Title:		Find lowest common ancestor for given nodes
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

Node* findLCA(Node *root, int a, int b) {
	if (root == NULL) {
		return NULL;
	}
	if (root->data == a || root->data == b) {
		return root;
	}

	Node *left = findLCA(root->left, a, b);
	Node *right = findLCA(root->right, a, b);

	if (left != NULL && right != NULL) {
		return root;
	}

	if (left != NULL) {
		return left;
	} else {
		return right;
	}
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);

	Node * lca = findLCA(root, 4, 2);
	if (lca == NULL) {
		cout << "No LCA" << endl;
	} else {
		cout << lca->data << endl;
	}

	return 0;
}
