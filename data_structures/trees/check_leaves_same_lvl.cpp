/*
 * Author:		Ashish Verma
 * Title:		check if all leafs are at same lvl
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

bool checkSameLvlLeaf(Node *root, int curLvl, int *lastLeafAtLvl) {
	if (root == NULL) {
		return true;
	}
	if (root->left == NULL && root->right == NULL) {
		if (*lastLeafAtLvl == 0) {
			*lastLeafAtLvl = curLvl;
		}
		return (curLvl == *lastLeafAtLvl);
	}
	return checkSameLvlLeaf(root->left, curLvl + 1, lastLeafAtLvl)
			&& checkSameLvlLeaf(root->right, curLvl + 1, lastLeafAtLvl);
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);

	cout << checkSameLvlLeaf(root, 1, new int) << endl;

	return 0;
}
