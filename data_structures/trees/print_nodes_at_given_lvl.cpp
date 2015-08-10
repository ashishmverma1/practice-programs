/*
 * Author:		Ashish Verma
 * Title:		print particular level in a tree
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

void printLevel(Node *root, int lvl) {
	if (root == NULL) {
		return;
	}
	if (lvl == 1) {
		cout << root->data << ' ';
	} else {
		printLevel(root->left, lvl - 1);
		printLevel(root->right, lvl - 1);
	}
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printLevel(root, 2);

	return 0;
}
