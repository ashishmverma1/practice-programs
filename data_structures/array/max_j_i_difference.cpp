/*
 * Author:		Ashish Verma
 * Title:		max (j - i) such that ar[j] > ar[i] & j > i
 *
 */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define debug(x) cout << "DEBUG: " << x << endl

using namespace std;

int findDiff(int ar[], int n) {
	int lmin[n], rmax[n];
	int maxDiff = -1;
	lmin[0] = ar[0];
	for (int i = 1; i < n; i++) {
		lmin[i] = min(lmin[i - 1], ar[i]);
	}
	rmax[n - 1] = ar[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		rmax[i] = max(rmax[i + 1], ar[i]);
	}
	int i = 0, j = 0;
	while (i < n && j < n) {
		if (lmin[i] < rmax[j]) {
			maxDiff = max(maxDiff, j - i);
			j++;
		} else {
			i++;
		}
	}
	return maxDiff;
}

int main() {
	int ar[] = { 83, 78, 80, 81, 79, 82 };
	int n = sizeof(ar) / sizeof(ar[0]);
	cout << findDiff(ar, n);
	return 0;
}
