/*
 * Author:		Ashish Verma
 * Title:		find distance between 2 nodes
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

Node* findLCA(Node *root, int a, int b) {
	if (root == NULL) {
		return NULL;
	}
	if (root->data == a || root->data == b) {
		return root;
	}

	Node *left = findLCA(root->left, a, b);
	Node *right = findLCA(root->right, a, b);

	if (left != NULL && right != NULL) {
		return root;
	}

	if (left != NULL) {
		return left;
	} else {
		return right;
	}
}

int distanceFromRoot(Node *root, int k, int distance) {
	if (root == NULL) {
		return -1;
	}
	if (root->data == k) {
		return distance;
	}
	return max(distanceFromRoot(root->left, k, distance + 1),
			distanceFromRoot(root->right, k, distance + 1));
}

int NodesDistance(Node *root, int a, int b) {
	int lcaDistance = distanceFromRoot(root, findLCA(root, a, b)->data, 0);
	int aDistance = distanceFromRoot(root, a, 0);
	int bDistance = distanceFromRoot(root, b, 0);

	return aDistance + bDistance - 2 * lcaDistance;
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);

	cout << NodesDistance(root, 4, 6);

	return 0;
}
