/*
 * Author:		Ashish Verma
 * Title:		Questions on circular linked list
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
	Node *next;
};

// print the list
void printList(Node *head) {
	if (head == NULL) {
		cout << "NULL" << endl;
	} else {
		cout << head->data << "->";
		Node *p = head->next;
		while (p != head) {
			cout << p->data << "->";
			p = p->next;
		}
		cout << "NULL" << endl;
	}
}

// to insert a node
Node* insertNode(Node *head, int data) {
	Node *n = new Node;
	n->data = data;
	n->next = NULL;

	if (head == NULL) {
		head = n;
	} else {
		Node *p = head;
		while (p->next != head) {
			p = p->next;
		}
		p->next = n;
	}
	n->next = head;
	return head;
}

// to insert a node
Node* sortedInsertNode(Node *head, int data) {
	Node *n = new Node;
	n->data = data;
	n->next = NULL;

	Node *p = head;

	if (head == NULL) {
		head = n;
		n->next = head;
	} else if (head->data > data) {
		n->next = head;
		while (p->next != head) {
			p = p->next;
		}
		p->next = n;
		head = n;
	} else {
		while (p->next != head && p->next->data <= data) {
			p = p->next;
		}
		n->next = p->next;
		p->next = n;
	}
	return head;
}

// split list into halves
void splitIntoHalves(Node *head, Node **firstHalf, Node **secondHalf) {
	*firstHalf = head;
	if (head->next == head) {
		*secondHalf = NULL;
	} else {
		Node *slow, *fast;

		slow = head;
		fast = head->next;

		while (fast->next != head && fast->next->next != head) {
			slow = slow->next;
			fast = fast->next->next;
		}

		if (fast->next != head) {		// odd sized list
			fast = fast->next;
			slow = slow->next;
		}

		*secondHalf = slow->next;
		fast->next = *secondHalf;
		slow->next = head;
	}
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
