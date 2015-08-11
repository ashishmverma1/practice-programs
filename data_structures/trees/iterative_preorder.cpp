/*
 * Author:		Ashish Verma
 * Title:		iterative preorder traversal
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

void iterativePreorderTraversal(Node *root) {
	stack<Node*> stk;
	Node *p;
	if (root != NULL) {
		stk.push(root);
	}
	while (!stk.empty()) {
		p = stk.top();
		stk.pop();
		cout << p->data << ' ';
		if (p->right != NULL) {
			stk.push(p->right);
		}
		if (p->left != NULL) {
			stk.push(p->left);
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

	iterativePreorderTraversal(root);
	return 0;
}
