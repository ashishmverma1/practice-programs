/*
 * Author:		Ashish Verma
 * Title:		tree to DLL by level
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

Node* listInsert(Node *head, Node *n) {
	n->left = NULL;
	n->right = NULL;

	if (head == NULL) {
		return n;
	}

	Node *p = head;
	while (p->right != NULL) {
		p = p->right;
	}

	n->left = p;
	p->right = n;
	return head;
}

void printList(Node *head) {
	while (head != NULL) {
		cout << head->data << ' ';
		head = head->right;
	}
	cout << endl;
}

Node* treeToList(Node *root) {
	queue<Node*> q;
	Node *p, *head = NULL;
	q.push(root);
	while (!q.empty()) {
		p = q.front();
		q.pop();
		if (p->left != NULL) {
			q.push(p->left);
		}
		if (p->right != NULL) {
			q.push(p->right);
		}
		head = listInsert(head, p);
	}
	return head;
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printList(treeToList(root));

	return 0;
}
