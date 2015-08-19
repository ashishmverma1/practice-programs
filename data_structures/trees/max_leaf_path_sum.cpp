/*
 * Author:		Ashish Verma
 * Title:		maximum path sum between two leaves
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

int maxPathSum(Node *root, int &sum) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return root->data;
	}

	int leftSum = maxPathSum(root->left, sum);
	int rightSum = maxPathSum(root->right, sum);
	int curSum = leftSum + rightSum + root->data;
	sum = max(sum, curSum);

	if (leftSum == 0 || rightSum == 0) {
		return curSum;
	}
	return max(leftSum, rightSum) + root->data;
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);

	int ans = 0;
	maxPathSum(root, ans);
	cout << ans;

	return 0;
}
