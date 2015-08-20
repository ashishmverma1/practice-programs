/*
 * Author:		Ashish Verma
 * Title:		sorted array to bst
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

Node *arrayToBst(int ar[], int start, int end) {
	if (start > end) {
		return NULL;
	}
	int mid = (start + end) / 2;
	Node *root = newNode(ar[mid]);
	root->left = arrayToBst(ar, start, mid - 1);
	root->right = arrayToBst(ar, mid + 1, end);
	return root;
}

int main() {

	int ar[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(ar) / sizeof(int);

	Node *root = arrayToBst(ar, 0, n - 1);

	inorder(root);
	cout << endl;

	return 0;
}
