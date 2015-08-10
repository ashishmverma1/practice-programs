/*
 * Author:	 Ashish Verma
 * Title:		 Questions on singly linked list
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

// print the linked list
void printList(Node *head) {
	if (head == NULL) {
		cout << "NULL" << endl;
	} else {
		while (head != NULL) {
			cout << head->data << "->";
			head = head->next;
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
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = n;
	}
	return head;
}

// find length of linked list
int findLength(Node *head) {
	if (head == NULL) {
		return 0;
	} else {
		return (1 + findLength(head->next));
	}
}

// check presence of a node in the list
bool isPresent(Node *head, int data) {
	if (head == NULL) {
		return false;
	} else {
		if (head->data == data) {
			return true;
		} else {
			return isPresent(head->next, data);
		}
	}
}

// delete entire list
Node* deleteList(Node *head) {
	if (head == NULL) {
		delete head;
		return NULL;
	}

	deleteList(head->next);
	delete head;
	return NULL;
}

// check if the linked list is palindrome
bool checkPalindrome(Node *head) {
	if (head == NULL) {
		return true;
	}

	Node *p, *q;
	p = q = head;

	stack<Node*> stk;
	stk.push(p);

	bool isPalindrome = true;

	while (q != NULL && q->next != NULL && q->next->next != NULL) {
		p = p->next;
		stk.push(p);
		q = q->next->next;
	}

	if (q->next == NULL) {
		// odd length
		stk.pop();
	}

	p = p->next;
	while (!stk.empty() && p != NULL) {
		if (stk.top()->data != p->data) {
			isPalindrome = false;
			break;
		}
		stk.pop();
		p = p->next;
	}

	return isPalindrome;
}

// pair wise swap the list
Node* pairwiseSwapList(Node *head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	Node *prev, *cur1, *cur2;

	prev = head;
	head = head->next;
	prev->next = prev->next->next;
	head->next = prev;

	prev = head->next;
	bool atleastTwoElementsRemaining;

	if (prev->next == NULL || prev->next->next == NULL) {
		atleastTwoElementsRemaining = false;
	} else {
		atleastTwoElementsRemaining = true;
	}

	while (atleastTwoElementsRemaining) {
		cur1 = prev->next;
		cur2 = cur1->next;

		prev->next = cur2;
		cur1->next = cur2->next;
		cur2->next = cur1;

		prev = cur1;
		if (prev->next == NULL || prev->next->next == NULL) {
			atleastTwoElementsRemaining = false;
		} else {
			atleastTwoElementsRemaining = true;
		}
	}

	return head;
}

// find intersection of 2 sorted lists
Node* intersectSortedLists(Node *head1, Node *head2) {
	Node *head3 = NULL;

	while (head1 != NULL) {
		while (head2 != NULL && head2->data < head1->data) {
			head2 = head2->next;
		}

		if (head2 == NULL) {
			break;
		}

		if (head1->data == head2->data) {
			head3 = insertNode(head3, head1->data);
		}

		while (head2 != NULL && head2->data == head1->data) {
			head2 = head2->next;
		}

		head1 = head1->next;
	}

	return head3;
}

// delete alternate nodes
void deleteAlternate(Node *head) {
	Node *del;
	while (head != NULL && head->next != NULL) {
		del = head->next;
		head->next = del->next;
		head = head->next;
		delete del;
	}
}

// merge 2 sorted lists
Node* sortedMerge(Node *head1, Node *head2) {
	Node *head3, *p;

	// init head3
	if (head1 != NULL && head2 == NULL) {
		return head1;
	} else if (head1 == NULL && head2 != NULL) {
		return head2;
	} else if (head1 == NULL && head2 == NULL) {
		return NULL;
	} else if (head1->data > head2->data) {
		head3 = head2;
		head2 = head2->next;
	} else {
		head3 = head1;
		head1 = head1->next;
	}

	p = head3;

	while (head1 != NULL && head2 != NULL) {
		if (head1->data < head2->data) {
			p->next = head1;
			head1 = head1->next;
		} else {
			p->next = head2;
			head2 = head2->next;
		}
		p = p->next;
	}

	while (head1 != NULL) {
		p->next = head1;
		head1 = head1->next;
		p = p->next;
	}

	while (head2 != NULL) {
		p->next = head2;
		head2 = head2->next;
		p = p->next;
	}

	return head3;
}

// split list into halves
void splitIntoHalves(Node *head, Node **firstHalf, Node **secondHalf) {
	*firstHalf = head;
	Node *slow, *fast;

	slow = head;
	fast = head->next;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	*secondHalf = slow->next;
	slow->next = NULL;
}

// performs merge-sort on given list
Node* mergeSort(Node *head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	Node *firstHalf, *secondHalf;
	splitIntoHalves(head, &firstHalf, &secondHalf);

	firstHalf = mergeSort(firstHalf);
	secondHalf = mergeSort(secondHalf);

	return sortedMerge(firstHalf, secondHalf);
}

// reverse the entire list
Node* reverseList(Node *head) {
	Node *prev, *cur, *next;
	cur = head;
	prev = next = NULL;
	while (cur != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

// reverse list in groups of 'k' size
Node* reverseGroupsK(Node *head, int k) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	Node *prev, *cur, *next;
	cur = head;
	prev = next = NULL;

	int count = 0;

	while (cur != NULL && count < k) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		count++;
	}

	head->next = reverseGroupsK(cur, k);
	return prev;
}

// reverse list in alternate groups of 'k' size (modification of 'reverseGroupsK')
Node* reverseAlternateGroupsK(Node *head, int k, bool dontReverse) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	Node *prev, *cur, *next;
	cur = head;
	prev = next = NULL;

	int count = 0;

	if (dontReverse) {
		while (cur != NULL && count < k) {
			prev = cur;
			cur = cur->next;
			count++;
		}

		prev->next = reverseAlternateGroupsK(cur, k, !dontReverse);
		return head;

	} else {
		while (cur != NULL && count < k) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
			count++;
		}

		head->next = reverseAlternateGroupsK(cur, k, !dontReverse);
		return prev;
	}
}

// delete nodes which have a greater element anywhere on their right
Node* deleteIfGreaterOnRight(Node *head) {
	head = reverseList(head);
	int max = -999999;
	Node *p, *prev;
	p = head;

	while (p != NULL) {
		if (p->data >= max) {
			max = p->data;
		} else {
			prev->next = p->next;
			delete p;
			p = prev;
		}

		prev = p;
		p = p->next;
	}

	head = reverseList(head);
	return head;
}

// make all even appear before odd in same order
Node* segregateEvenOdd(Node *head) {
	Node *even, *odd, *evenP, *oddP, *p;
	even = odd = evenP = oddP = NULL;
	p = head;

	while (p != NULL) {
		if (p->data % 2 == 0) {
			if (even == NULL) {
				even = p;
				evenP = p;
			} else {
				evenP->next = p;
				evenP = evenP->next;
			}
		} else {
			if (odd == NULL) {
				odd = p;
				oddP = p;
			} else {
				oddP->next = p;
				oddP = oddP->next;
			}
		}
		p = p->next;
	}

	head = even;
	evenP->next = odd;
	oddP->next = NULL;

	return head;
}

// add two numbers with digits in form of a linked list, units digit at front
Node* addLinkListNumbers(Node *head1, Node *head2) {
	if (head1 == NULL) {
		return head2;
	} else if (head2 == NULL) {
		return head1;
	}

	Node *ans = NULL, *n, *p;

	int sum, carry = 0;

	while (head1 != NULL && head2 != NULL) {
		n = new Node;
		n->next = NULL;
		sum = head1->data + head2->data + carry;
		carry = sum / 10;
		sum = sum % 10;
		n->data = sum;

		if (ans == NULL) {
			ans = n;
			p = ans;
		} else {
			p->next = n;
			p = n;
		}

		head1 = head1->next;
		head2 = head2->next;
	}

	while (head1 != NULL) {
		n = new Node;
		n->next = NULL;
		sum = head1->data + carry;
		carry = sum / 10;
		sum = sum % 10;
		n->data = sum;
		p->next = n;
		p = n;
		head1 = head1->next;
	}

	while (head2 != NULL) {
		n = new Node;
		n->next = NULL;
		sum = head2->data + carry;
		carry = sum / 10;
		sum = sum % 10;
		n->data = sum;
		p->next = n;
		p = n;
		head2 = head2->next;
	}

	if (carry != 0) {
		n = new Node;
		n->next = NULL;
		n->data = carry;
		p->next = n;
	}

	return ans;
}

// rotate list anti-clockwise by 'k' steps
Node* rotateList(Node *head, int k) {
	Node *next, *last;

	last = head;
	while (last->next != NULL) {
		last = last->next;
	}

	for (int i = 0; i < k; i++) {
		last->next = head;
		last = head;
		next = head->next;
		head->next = NULL;
		head = next;
	}
	return head;
}

// 2 same-sized linked lists maximum sum. change paths between two lists at same valued nodes
Node* maxSumTwoLists(Node *head1, Node *head2) {
	int sum1, sum2;
	sum1 = sum2 = 0;

	Node *ans = NULL;
	Node *p1, *p2;
	Node *lastCommon1, *lastCommon2;

	lastCommon1 = lastCommon2 = NULL;

	p1 = head1;
	p2 = head2;

	while (p1 != NULL && p2 != NULL) {
		sum1 += p1->data;
		sum2 += p2->data;

		if ((p1->data == p2->data) || (p1->next == NULL && p2->next == NULL)) {
			if (sum1 > sum2) {
				if (ans == NULL) {
					ans = head1;
				}
				if (lastCommon1 != NULL) {
					lastCommon2->next = lastCommon1->next;
				}

			} else {
				if (ans == NULL) {
					ans = head2;
				}
				if (lastCommon2 != NULL) {
					lastCommon1->next = lastCommon2->next;
				}
			}
			lastCommon1 = p1;
			lastCommon2 = p2;
			sum1 = sum2 = 0;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return ans;
}

int main() {

	Node *head1, *head2;
	int n1, val;
	int n2;

	head1 = head2 = NULL;

	cin >> n1;
	cin >> n2;
	while (n1--) {
		cin >> val;
		head1 = insertNode(head1, val);
	}

	while (n2--) {
		cin >> val;
		head2 = insertNode(head2, val);
	}

	printList(head1);
	printList(head2);
	printList(maxSumTwoLists(head1, head2));

	return 0;
}
