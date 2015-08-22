/*
 * Author:		Ashish Verma
 * Title:		print 2 bst together in sorted order
 *
 */

#include <cmath>
#include <cstdio>
#include <climits>
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

Node *insert(Node *root, int val) {
	Node *n = newNode(val);
	if (root == NULL) {
		return n;
	}
	Node *p = root;
	while (true) {
		if (val < p->data) {
			if (p->left == NULL) {
				p->left = n;
				break;
			} else {
				p = p->left;
			}
		} else {
			if (p->right == NULL) {
				p->right = n;
				break;
			} else {
				p = p->right;
			}
		}
	}
	return root;
}

void printSortedMergeBst(Node *root1, Node *root2) {
	stack<Node*> stk1, stk2;
	Node *p1, *p2;
	p1 = p2 = NULL;

	if (root1 != NULL) {
		stk1.push(root1);
		p1 = root1->left;
	}
	if (root2 != NULL) {
		stk2.push(root2);
		p2 = root2->left;
	}

	while (!stk1.empty() || !stk2.empty() || p1 != NULL || p2 != NULL) {
		while (p1 != NULL) {
			stk1.push(p1);
			p1 = p1->left;
		}
		while (p2 != NULL) {
			stk2.push(p2);
			p2 = p2->left;
		}

		if (!stk1.empty() && !stk2.empty()) {
			if (stk1.top()->data < stk2.top()->data) {
				p1 = stk1.top();
				stk1.pop();
				cout << p1->data << ' ';
				p1 = p1->right;
			} else {
				p2 = stk2.top();
				stk2.pop();
				cout << p2->data << ' ';
				p2 = p2->right;
			}
		} else if (!stk1.empty()) {
			p1 = stk1.top();
			stk1.pop();
			cout << p1->data << ' ';
			p1 = p1->right;
		} else {
			p2 = stk2.top();
			stk2.pop();
			cout << p2->data << ' ';
			p2 = p2->right;
		}
	}
	cout << endl;
}

int main() {

	Node *root = NULL;
	root = insert(root, 8);
	root = insert(root, 10);
	root = insert(root, 3);
	root = insert(root, 1);
	root = insert(root, 6);
	root = insert(root, 14);
	root = insert(root, 4);
	root = insert(root, 7);
	root = insert(root, 13);

	Node *root2 = NULL;
	root2 = insert(root2, 26);
	root2 = insert(root2, 20);
	root2 = insert(root2, 2);
	root2 = insert(root2, 11);
	root2 = insert(root2, 5);
	root2 = insert(root2, 14);
	root2 = insert(root2, 9);
	root2 = insert(root2, 12);
	root2 = insert(root2, 15);

	printSortedMergeBst(root, root2);

	return 0;
}
