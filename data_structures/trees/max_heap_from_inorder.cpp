/*
 * Author:		Ashish Verma
 * Title:		construct special bt (key of every node is greater than keys in left and right children)
 * 				from inorder
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

Node* constructTree(int inorder[], int low, int high) {
	if (low > high) {
		return NULL;
	}

	int loc = findLargest(inorder, low, high);
	Node *n = newNode(inorder[loc]);
	n->left = constructTree(inorder, low, loc - 1);
	n->right = constructTree(inorder, loc + 1, high);
	return n;
}

int main() {
	int inorder[] = { 1, 5, 10, 40, 30, 15, 28, 20 };
	inorderTraversal(constructTree(inorder, 0, 7));
	return 0;
}
