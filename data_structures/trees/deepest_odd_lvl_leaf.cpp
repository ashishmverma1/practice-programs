/*
 * Author:		Ashish Verma
 * Title:		lvl of deepest leaf present at odd lvl
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

int deepestOddLvlLeaf(Node *root, int curLvl) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL && curLvl % 2 == 1) {
		return curLvl;
	}
	return max(deepestOddLvlLeaf(root->left, curLvl + 1),
			deepestOddLvlLeaf(root->right, curLvl + 1));
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);

	cout << deepestOddLvlLeaf(root, 1) << endl;

	return 0;
}
