/*
 * Author:		Ashish Verma
 * Title:		XOR memory efficient list
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
	Node *pxn;
};

// finds XOR of 2 Node pointers
Node* xorNode(Node *a, Node *b) {
	return (Node*) ((unsigned long) (a) ^ (unsigned long) (b));
}

// print the list
void printList(Node *head) {
	Node *prev = NULL, *temp;
	if (head == NULL) {
		cout << "NULL" << endl;
	} else {
		Node *p = head;
		while (p != NULL) {
			cout << p->data << "->";
			temp = p;
			p = xorNode(prev, p->pxn);
			prev = temp;
		}
		cout << "NULL" << endl;
	}
}

// to insert a node
Node* insertNode(Node *head, int data) {
	Node *n = new Node;
	n->data = data;
	n->pxn = xorNode(NULL, head);
	if (head != NULL) {
		Node *next = xorNode(NULL, head->pxn);
		head->pxn = xorNode(n, next);
	}
	return n;
}

int main() {

	Node *head1, *head2;
	int n1, val;
//	int n2;

	head1 = head2 = NULL;

	cin >> n1;
//	cin >> n2;
	while (n1--) {
		cin >> val;
		head1 = insertNode(head1, val);
	}

//	while (n2--) {
//		cin >> val;
//		head2 = insertNode(head2, val);
//	}

	printList(head1);
//	printList(maxSumTwoLists(head1, head2));

	return 0;
}
