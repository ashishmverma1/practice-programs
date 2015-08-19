/*
 * Author:		Ashish Verma
 * Title:		print top view of binary tree
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

void printTopView(Node *root) {
	if (root == NULL) {
		return;
	}
	pair<Node*, int> node;
	queue < pair<Node*, int> > q;
	set<int> hdSet;

	q.push(pair<Node*, int>(root, 0));
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (node.first->left != NULL) {
			q.push(pair<Node*, int>(node.first->left, node.second - 1));
		}
		if (node.first->right != NULL) {
			q.push(pair<Node*, int>(node.first->right, node.second + 1));
		}
		if (hdSet.find(node.second) == hdSet.end()) {
			hdSet.insert(node.second);
			cout << node.first->data << ' ';
		}
	}
	cout << endl;
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);
	root->left->right->left->left = newNode(9);
	root->left->right->left->left->left = newNode(10);
	root->left->right->right = newNode(7);
	root->left->right->right->right = newNode(8);

	printTopView(root);

	return 0;
}
