/*
 * Author:		Ashish Verma
 * Title:		Questions on doubly linked list
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
	Node *prev;
};

// print the list
void printList(Node *head) {
	if (head == NULL) {
		cout << "NULL" << endl;
	} else {
		Node *p = head;
		while (p != NULL) {
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
	n->prev = NULL;

	if (head == NULL) {
		head = n;
	} else {
		Node *p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = n;
		n->prev = p;
	}
	return head;
}

// reverse the list
Node* reverseList(Node *head) {
	Node *temp, *last;
	while (head != NULL) {
		temp = head->next;
		head->next = head->prev;
		head->prev = temp;
		last = head;
		head = head->prev;
	}

	return last;
}

// linked list is such that prev points to any random node. clone this list!
Node* cloneRandomPrevList(Node *head) {
	Node *ans, *n, *p;

	// duplicate list, inserting duplicates after originals
	p = head;
	while (p != NULL) {
		n = new Node;
		n->data = p->data;
		n->next = p->next;
		p->next = n;
		p = n->next;
	}

	// set prev on duplicates
	p = head;
	ans = head->next;
	while (p != NULL) {
		p->next->prev = p->prev->next;
		p = p->next->next;
	}

	// seperate duplicates
	p = head;
	while (p != NULL) {
		n = p->next;
		p->next = n->next;
		if (n->next != NULL) {
			n->next = n->next->next;
		}
		p = p->next;
	}

	return ans;
}

// swap kth node from beginning with the kth node form end
Node* swapKthNode(Node *head, int k) {
	Node *kthBeg, *kthEnd, *p, *temp;

	p = kthBeg = kthEnd = head;
	for (int i = 1; i < k; i++) {
		kthBeg = kthBeg->next;
	}

	p = kthBeg;
	while (p->next != NULL) {
		p = p->next;
		kthEnd = kthEnd->next;
	}

	temp = kthBeg->next;
	kthBeg->next = kthEnd->next;
	kthEnd->next = temp;

	temp = kthBeg->prev;
	kthBeg->prev = kthEnd->prev;
	kthEnd->prev = temp;

	if (kthBeg->prev != NULL) {
		kthBeg->prev->next = kthBeg;
	}
	if (kthBeg->next != NULL) {
		kthBeg->next->prev = kthBeg;
	}
	if (kthEnd->prev != NULL) {
		kthEnd->prev->next = kthEnd;
	}
	if (kthEnd->next != NULL) {
		kthEnd->next->prev = kthEnd;
	}

	if (kthBeg == head) {
		head = kthEnd;
	} else if (kthEnd == head) {
		head = kthBeg;
	}
	return head;
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
	printList(swapKthNode(head1, 1));
//	printList(maxSumTwoLists(head1, head2));

	return 0;
}
