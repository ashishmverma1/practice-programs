/*0
 * Author:		Ashish Verma
 * Title:		check if 2 trees are isomorphic
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

bool isIsomorphic(Node *root1, Node *root2) {
	if (root1 == NULL && root2 == NULL) {
		return true;
	}
	if (root1 == NULL || root2 == NULL || root1->data != root2->data) {
		return false;
	}
	return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right))
			|| (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left));
}

int main() {

	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	Node *root2 = newNode(1);
	root2->left = newNode(2);
	root2->right = newNode(3);
	root2->left->left = newNode(5);
	root2->left->right = newNode(4);

	cout << isIsomorphic(root, root2);

	return 0;
}
