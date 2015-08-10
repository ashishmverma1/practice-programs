/*
 * Author:		Ashish Verma
 * Title:		max lvl wise width of tree
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

int height(Node *root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

vector<int> nodesAtGivenLevel(Node *root, int lvl, vector<int> nodes) {
	if (root == NULL) {
		return nodes;
	}
	if (lvl == 1) {
		nodes.push_back(root->data);
	} else {
		vector<int> left = nodesAtGivenLevel(root->left, lvl - 1, nodes);
		vector<int> right = nodesAtGivenLevel(root->right, lvl - 1, nodes);
		nodes.insert(nodes.end(), left.begin(), left.end());
		nodes.insert(nodes.end(), right.begin(), right.end());
	}
	return nodes;
}

int maxWidthTree(Node *root) {
	int maxWidth = 0, curWidth;
	for (int i = 1; i <= height(root); i++) {
		curWidth = nodesAtGivenLevel(root, i, vector<int>()).size();
		maxWidth = max(maxWidth, curWidth);
	}
	return maxWidth;
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	cout << maxWidthTree(root);
	return 0;
}
