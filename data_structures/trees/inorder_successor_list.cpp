/*
 * Author:		Ashish Verma
 * Title:		set "next" to inorder successor
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
	Node *next;
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

void setInorderSuccessor(Node *root) {
	static Node *next = NULL;
	if (root == NULL) {
		return;
	}
	setInorderSuccessor(root->right);
	root->next = next;
	next = root;
	setInorderSuccessor(root->left);
}

void printList(Node *head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	setInorderSuccessor(root);
	printList(root->left->left);
	return 0;
}
