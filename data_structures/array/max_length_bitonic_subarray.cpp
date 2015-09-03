/*
 * Author:		Ashish Verma
 * Title:		max length bitonic subarray (array increasing at first, then decreasing)
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

int maxBitonicLength(int ar[], int n) {
	int curLength, maxLength = INT_MIN;
	bool change;
	int i = 0;
	while (i < n) {
		change = false;
		curLength = 1;
		while (i < n - 1 && ar[i] < ar[i + 1]) {
			i++;
			curLength++;
			change = true;
		}
		while (i < n - 1 && ar[i] > ar[i + 1]) {
			i++;
			curLength++;
			change = true;
		}
		maxLength = max(maxLength, curLength);
		if (!change) {
			i++;
		}
	}
	return maxLength;
}

int main() {
	int ar[] = { 12, 4, 78, 90, 45, 23, 1 };
	int n = sizeof(ar) / sizeof(ar[0]);
	cout << maxBitonicLength(ar, n);
	return 0;
}
