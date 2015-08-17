/*
 * Author:		Ashish Verma
 * Title:		print postorder from given inorder and preorder
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

int search(int ar[], int n, int val) {
	for (int i = 0; i < n; i++) {
		if (ar[i] == val) {
			return i;
		}
	}
	return -1;
}

void printPostorder(int pre[], int in[], int n) {
	int rootLoc = search(in, n, pre[0]);

	// left subtree is not empty, traverse left subtree
	if (rootLoc != 0) {
		printPostorder(pre + 1, in, rootLoc);
	}

	// right subtree is not empty, traverse right subtree
	if (rootLoc != n - 1) {
		printPostorder(pre + rootLoc + 1, in + rootLoc + 1, n - rootLoc - 1);
	}

	cout << in[rootLoc] << ' ';
}

int main() {
	int pre[] = { 1, 2, 4, 5, 3, 6 };
	int in[] = { 4, 2, 5, 1, 3, 6 };
	printPostorder(pre, in, 6);
	return 0;
}
