/*
 * Author:		Ashish Verma
 * Title:		given an array representation of complete bst, print array elements in sorted order
 *
 */

#include <cmath>
#include <cstdio>
#include <climits>
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

void inorder(int ar[], int cur, int n) {
	if (cur >= n) {
		return;
	}
	inorder(ar, cur * 2 + 1, n);
	cout << ar[cur] << ' ';
	inorder(ar, cur * 2 + 2, n);
}

int main() {
	int ar[] = { 4, 2, 5, 1, 3 };
	int n = sizeof(ar) / sizeof(int);
	inorder(ar, 0, n);
	return 0;
}
