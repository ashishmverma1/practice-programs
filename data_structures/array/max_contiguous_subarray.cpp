/*
 * Author:		Ashish Verma
 * Title:		max contiguous subarray
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

int maxContiguousSum(int ar[], int n) {
	int maxSoFar = INT_MIN;
	int maxEndingHere = 0;
	int checkMaxNegative = INT_MIN;
	for (int i = 0; i < n; i++) {
		maxEndingHere += ar[i];
		maxEndingHere = max(maxEndingHere, 0);
		maxSoFar = max(maxSoFar, maxEndingHere);
		checkMaxNegative = max(checkMaxNegative, ar[i]);
	}
	if (checkMaxNegative < 0) {
		return checkMaxNegative;
	}
	return maxSoFar;
}

int main() {
	int ar[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(ar) / sizeof(ar[0]);

	cout << maxContiguousSum(ar, n) << endl;

	return 0;
}
