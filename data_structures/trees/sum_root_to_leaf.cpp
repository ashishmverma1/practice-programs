/*
 * Author:		Ashish Verma
 * Title:		check if given sum exists along any root to leaf path
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

bool checkSumRootToLeaf(Node *root, int givenSum, vector<Node*> path) {
	if (root == NULL) {
		return true;
	}
	path.push_back(root);
	int sum = 0;
	if (root->left == NULL && root->right == NULL) {
		for (unsigned int i = 0; i < path.size(); i++) {
			sum += path[i]->data;
		}
		if (sum == givenSum) {
			return true;
		} else {
			return false;
		}
	} else {
		return checkSumRootToLeaf(root->left, givenSum, path)
				|| checkSumRootToLeaf(root->right, givenSum, path);
	}
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	cout << checkSumRootToLeaf(root, 8, vector<Node*>());
	return 0;
}
