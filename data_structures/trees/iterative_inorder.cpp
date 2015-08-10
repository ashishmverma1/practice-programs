/*
 * Author:		Ashish Verma
 * Title:		iterative inorder
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
	stack<Node*> stk;
	Node *p = root;
	stk.push(p);
	p = p->left;
	while (!stk.empty() || p != NULL) {
		while (p != NULL) {
			stk.push(p);
			p = p->left;
		}
		p = stk.top();
		stk.pop();
		cout << p->data << ' ';
		p = p->right;
	}
	cout << endl;
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	inorder(root);
	return 0;
}
