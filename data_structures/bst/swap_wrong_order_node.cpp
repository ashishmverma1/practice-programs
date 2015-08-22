/*
 * Author:		Ashish Verma
 * Title:		if any 2 nodes are swapped in bst, find and fix them
 *
 */

#include <cmath>
#include <cstdio>
#include <climits>
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

void swapWrongOrderNodes(Node *root, Node **wrong1, Node **wrong2, Node **last) {
	if (root == NULL) {
		return;
	}
	swapWrongOrderNodes(root->left, wrong1, wrong2, last);
	if (*last != NULL && (*last)->data > root->data) {
		if (*wrong1 == NULL) {
			*wrong1 = *last;
		}
		*wrong2 = root;
	}
	*last = root;
	swapWrongOrderNodes(root->right, wrong1, wrong2, last);
}

void swapWrongOrderNodes(Node *root) {
	Node *wrong1, *wrong2, *last;
	wrong1 = wrong2 = last = NULL;
	swapWrongOrderNodes(root, &wrong1, &wrong2, &last);
	if (wrong1 != NULL && wrong2 != NULL) {
		int temp;
		temp = wrong1->data;
		wrong1->data = wrong2->data;
		wrong2->data = temp;
	}
}

int main() {

	Node *root = newNode(8);
	root->left = newNode(3);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);
	root->right = newNode(13);
	root->right->right = newNode(14);
	root->right->right->left = newNode(10);

	inorder(root);
	cout << endl;
	swapWrongOrderNodes(root);
	inorder(root);
	cout << endl;

	return 0;
}
