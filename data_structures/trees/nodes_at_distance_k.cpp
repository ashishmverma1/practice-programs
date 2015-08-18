/*
 * Author:		Ashish Verma
 * Title:		print nodes at distance k from given node
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

void printKDistanceDown(Node *root, int k) {
	if (root == NULL || k < 0) {
		return;
	}
	if (k == 0) {
		cout << root->data << ' ';
	}
	printKDistanceDown(root->left, k - 1);
	printKDistanceDown(root->right, k - 1);
}

int printNodes(Node *root, int k, int val) {
	if (root == NULL) {
		return -1;
	}

	if (root->data == val) {
		printKDistanceDown(root, k);
		return 1;
	}

	int leftDist = printNodes(root->left, k, val);
	if (leftDist != -1) {
		if (leftDist == k) {
			cout << root->data << ' ';
		} else {
			printKDistanceDown(root->right, k - leftDist - 1);
		}
		return leftDist + 1;
	}

	int rightDist = printNodes(root->right, k, val);
	if (rightDist != -1) {
		if (rightDist == k) {
			cout << root->data << ' ';
		} else {
			printKDistanceDown(root->left, k - rightDist - 1);
		}
		return rightDist + 1;
	}

	return -1;
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);

	printNodes(root, 2, 5);

	return 0;
}
