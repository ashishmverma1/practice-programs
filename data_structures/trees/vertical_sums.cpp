/*
 * Author:		Ashish Verma
 * Title:		find all vertical sums
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

void inorderTraversal(Node *root) {
	if (root == NULL) {
		return;
	}
	inorderTraversal(root->left);
	cout << root->data << ' ';
	inorderTraversal(root->right);
}

map<int, int> findVerticalSums(Node *root, int horizontalDistance) {
	static map<int, int> sum;
	if (root == NULL) {
		return map<int, int>();
	}
	if (sum.find(horizontalDistance) != sum.end()) {
		sum[horizontalDistance] += root->data;
	} else {
		sum.insert(pair<int, int>(horizontalDistance, root->data));
	}
	findVerticalSums(root->left, horizontalDistance - 1);
	findVerticalSums(root->right, horizontalDistance + 1);
	return sum;
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	map<int, int> sum = findVerticalSums(root, 0);
	for (map<int, int>::iterator it = sum.begin(); it != sum.end(); it++) {
		cout << it->second << ' ';
	}
	return 0;
}
