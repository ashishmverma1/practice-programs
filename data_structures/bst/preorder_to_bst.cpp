/*
 * Author:		Ashish Verma
 * Title:		construct bst from preorder
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

Node *preToBst(int pre[], int n, int key, int *i = new int(0), int min = INT_MIN, int max = INT_MAX) {

	if (*i >= n) {
		return NULL;
	}
	Node *root = NULL;

	if (min < key && key < max) {
		root = newNode(key);
		(*i)++;
		if (*i < n) {
			root->left = preToBst(pre, n, pre[*i], i, min, key);
			root->right = preToBst(pre, n, pre[*i], i, key, max);
		}
	}

	return root;
}

int main() {

	int pre[] = { 10, 5, 1, 7, 40, 50 };
	int n = sizeof(pre) / sizeof(int);
	inorder(preToBst(pre, n, pre[0]));

	return 0;
}
