/*
 * Author:		Ashish Verma
 * Title:		max product subarray
 *
 */

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <fstream>

#define debug(x) cout << "DEBUG: " << x << endl

using namespace std;

int maxProductSubarray(int ar[], int n) {
	int minEndingHere, maxEndingHere, maxYet, temp;
	minEndingHere = maxEndingHere = maxYet = 1;

	for (int i = 0; i < n; i++) {
		if (ar[i] > 0) {
			maxEndingHere *= ar[i];
			minEndingHere = min(minEndingHere * ar[i], 1);
		} else if (ar[i] < 0) {
			temp = maxEndingHere;
			maxEndingHere = max(1, minEndingHere * ar[i]);
			minEndingHere = ar[i] * temp;
		} else {
			maxEndingHere = 1;
			minEndingHere = 1;
		}
		maxYet = max(maxYet, maxEndingHere);
	}

	return maxYet;
}

int main() {
	int ar[] = { -2, -3, 0, -2, -40 };
	int n = sizeof(ar) / sizeof(ar[0]);

	cout << maxProductSubarray(ar, n);

	return 0;
}
