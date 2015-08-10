/*
 * Author:		Ashish Verma
 * Title:		print boundary of tree anti-clockwise
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

#define debug(x) cout << endl << "DEBUG: " << x << endl

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

vector<Node*> nodesAtLevel(Node *root, int lvl, vector<Node*> nodes) {
	if (root == NULL) {
		return nodes;
	}
	if (lvl == 1) {
		nodes.push_back(root);
	} else {
		vector<Node*> left = nodesAtLevel(root->left, lvl - 1, nodes);
		vector<Node*> right = nodesAtLevel(root->right, lvl - 1, nodes);
		nodes.insert(nodes.end(), left.begin(), left.end());
		nodes.insert(nodes.end(), right.begin(), right.end());
	}
	return nodes;
}

void printBoundary(Node *root) {
	vector < vector<Node*> > levels;
	for (int i = 1; i <= height(root); i++) {
		levels.push_back(nodesAtLevel(root, i, vector<Node*>()));
	}
	for (unsigned int i = 0; i < levels.size(); i++) {
		cout << levels[i][0]->data << ' ';
	}
	for (int i = levels.size() - 1; i >= 0; i--) {
		if (levels[i].size() > 1) {
			cout << levels[i].back()->data << ' ';
		}
	}
	cout << endl;
}

int main() {
	Node *root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->right->right = newNode(25);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);

	printBoundary(root);
	return 0;
}
