/*
 * Author:		Ashish Verma
 * Title:		construct tree form inorder and preorder
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

int searchData(int ar[], int data, int start, int end) {
	for (int i = start; i <= end; i++) {
		if (ar[i] == data) {
			return i;
		}
	}
	return -1;
}

Node* constructTree(int inorder[], int preorder[], int inStart, int inEnd) {
	static int preIndex = 0;
	if (inStart > inEnd) {
		return NULL;
	}
	Node *n = newNode(preorder[preIndex++]);
	if (inStart == inEnd) {
		return n;
	}
	int loc = searchData(inorder, n->data, inStart, inEnd);
	n->left = constructTree(inorder, preorder, inStart, loc - 1);
	n->right = constructTree(inorder, preorder, loc + 1, inEnd);
	return n;
}

int main() {
	int preorder[] = { 1, 2, 4, 5, 3 };
	int inorder[] = { 4, 2, 5, 1, 3 };
	Node *root = constructTree(inorder, preorder, 0, 4);
	inorderTraversal(root);
	return 0;
}
