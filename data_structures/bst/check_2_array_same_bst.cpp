/*
 * Author:		Ashish Verma
 * Title:		check if 2 input arrays form same bst
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

bool areSameBst(int a[], int b[], int n, int i1 = 0, int i2 = 0, int minVal = INT_MIN, int maxVal =
		INT_MAX) {
	int j, k;

	for (j = i1; j < n; j++) {
		if (a[j] > minVal && a[j] < maxVal) {
			break;
		}
	}
	for (k = i2; k < n; k++) {
		if (b[k] > minVal && b[k] < maxVal) {
			break;
		}
	}

	// both are leaf
	if (j == n && k == n) {
		return true;
	}

	// only one of them are root or data dont match
	if (j == n || k == n || a[j] != b[k]) {
		return false;
	}

	return areSameBst(a, b, n, j + 1, k + 1, a[j], maxVal)
			&& areSameBst(a, b, n, j + 1, k + 1, minVal, a[j]);
}

int main() {

	int a[] = { 8, 3, 6, 1, 4, 7, 10, 14, 13 };
	int b[] = { 8, 10, 14, 3, 6, 4, 1, 7, 13 };
	int n = sizeof(a) / sizeof(int);

	cout << areSameBst(a, b, n);

	return 0;
}
