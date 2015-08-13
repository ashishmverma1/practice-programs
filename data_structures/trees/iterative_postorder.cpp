/*
 * Author:		Ashish Verma
 * Title:		iterative postorder traversal
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

void iterativePostorderTraversal(Node *root) {
	stack<Node*> stk, ans;
	if (root != NULL) {
		stk.push(root);
	}
	while (!stk.empty()) {
		ans.push(stk.top());
		stk.pop();
		if (ans.top()->left != NULL) {
			stk.push(ans.top()->left);
		}
		if (ans.top()->right != NULL) {
			stk.push(ans.top()->right);
		}
	}
	while (!ans.empty()) {
		cout << ans.top()->data << ' ';
		ans.pop();
	}
	cout << endl;
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	iterativePostorderTraversal(root);
	return 0;
}
