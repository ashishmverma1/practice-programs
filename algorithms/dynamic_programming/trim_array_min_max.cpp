/*
 * Author:		Ashish Verma
 * Title:		min number of elemnets to remove from ends of array so that (min * 2 > max)
 * 				for remaining elements
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
#include <list>

#define debug(x) cout << "DEBUG: " << x << endl

using namespace std;

int getMin(int ar[], int low, int high) {
	int minVal = INT_MAX;
	while (low <= high) {
		minVal = min(minVal, ar[low++]);
	}
	return minVal;
}

int getMax(int ar[], int low, int high) {
	int maxVal = INT_MIN;
	while (low <= high) {
		maxVal = max(maxVal, ar[low++]);
	}
	return maxVal;
}

int minRemovals(int ar[], int n) {
	int dp[n][n] = { 0 };

	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}

	for (int len = 2; len <= n; len++) {
		for (int i = 0; i < n - len + 1; i++) {
			int j = i + len - 1;
			int mx = getMax(ar, i, j);
			int mn = getMin(ar, i, j);
			if (mn * 2 > mx) {
				dp[i][j] = 0;
			} else {
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
			}
		}
	}

	return dp[0][n - 1];
}

int main() {

	int ar[] = { 4, 5, 100, 9, 10, 11, 12, 15, 200 };
	int n = sizeof(ar) / sizeof(ar[0]);

	cout << minRemovals(ar, n);

	return 0;
}
