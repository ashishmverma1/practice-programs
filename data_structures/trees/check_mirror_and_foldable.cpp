/*
 * Author:		Ashish Verma
 * Title:		check if 2 trees are mirror image of each other; and,
 * Title:		check if tree is foldable (left and right subtrees are mirror)
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

bool checkMirror(Node *root1, Node *root2) {
	if (root1 == NULL && root2 == NULL) {
		return true;
	}
	if (root1 == NULL || root2 == NULL) {
		return false;
	}

	return checkMirror(root1->left, root2->right)
			&& checkMirror(root1->right, root2->left);
}

bool checkFoldable(Node *root) {
	return checkMirror(root->left, root->right);
}

int main() {

	Node *root1 = newNode(1);
	root1->left = newNode(2);
	root1->right = newNode(3);
	root1->left->left = newNode(4);
	root1->left->right = newNode(5);

	Node *root2 = newNode(1);
	root2->right = newNode(2);
	root2->left = newNode(3);
	root2->right->right = newNode(4);
	root2->right->left = newNode(5);

	cout << checkMirror(root1, root2);
	return 0;
}
