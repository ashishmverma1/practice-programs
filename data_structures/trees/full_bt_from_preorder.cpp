/*
 * Author:		Ashish Verma
 * Title:		construct full BT from preorder
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

int findLargest(int ar[], int low, int high) {
	int largestVal = -999999, largestIndex;
	for (int i = low; i <= high; i++) {
		if (ar[i] > largestVal) {
			largestVal = ar[i];
			largestIndex = i;
		}
	}
	return largestIndex;
}

Node* constructTree(int preorder[], bool isLeaf[], int *index, int n) {
	if (*index == n) {
		return NULL;
	}
	Node *p = newNode(preorder[(*index)++]);
	if (!isLeaf[(*index) - 1]) {
		p->left = constructTree(preorder, isLeaf, index, n);
		p->right = constructTree(preorder, isLeaf, index, n);
	}
	return p;
}

int main() {
	int preorder[] = { 10, 30, 20, 5, 15 };
	bool isLeaf[] = { 0, 0, 1, 1, 1 };
	inorderTraversal(constructTree(preorder, isLeaf, new int, 5));
	return 0;
}
