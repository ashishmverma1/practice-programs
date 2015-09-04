/*
 * Author:		Ashish Verma
 * Title:		Find a sorted subsequence of size 3 in linear time
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
#define INFINITE 99999

using namespace std;

void findSortedSubsequence(int ar[], int n) {
	int minI = 0, maxI = n - 1;
	int smaller[n], larger[n];

	smaller[0] = -1;
	for (int i = 1; i < n; i++) {
		if (ar[i] <= ar[minI]) {
			minI = i;
			smaller[i] = -1;
		} else {
			smaller[i] = minI;
		}
	}

	larger[n - 1] = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (ar[i] >= ar[maxI]) {
			maxI = i;
			larger[i] = -1;
		} else {
			larger[i] = maxI;
		}
	}

	for (int i = 0; i < n; i++) {
		if (smaller[i] != -1 && larger[i] != -1) {
			cout << ar[smaller[i]] << ", " << ar[i] << ", " << ar[larger[i]] << endl;
			return;
		}
	}

	cout << "None" << endl;
}

int main() {
	int ar[] = { 12, 11, 10, 5, 6, 2, 30 };
	int n = sizeof(ar) / sizeof(ar[0]);
	findSortedSubsequence(ar, n);
	return 0;
}
