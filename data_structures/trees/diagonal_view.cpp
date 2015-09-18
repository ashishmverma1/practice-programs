/*
 * Author:		Ashish Verma
 * Title:		check if given space-less string can be formed using given dictionary of words
 *
 */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>

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

void printDiagonalView(Node *root) {
	if (root == NULL) {
		return;
	}
	queue<Node*> q;
	Node *p = root;
	while (!q.empty() || p != NULL) {
		if (p == NULL) {
			p = q.front();
			q.pop();
		}
		if (p->left != NULL) {
			q.push(p->left);
		}
		cout << p->data << " ";
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
	root->left->right->left = newNode(6);

	printDiagonalView(root);

	return 0;
}
