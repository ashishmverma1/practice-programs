/*
 * Author:		Ashish Verma
 * Title:		max sum increasing subsequence
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

int findLIS(int ar[], int n, int start, int dp[]) {
	if (dp[start] != 0) {
		return dp[start];
	}
	dp[start] = ar[start];
	for (int j = start + 1; j < n; j++) {
		if (ar[j] > ar[start]) {
			dp[start] = max(dp[start], ar[start] + findLIS(ar, n, j, dp));
		}
	}

	return dp[start];
}

int findLIS(int ar[], int n) {
	int dp[n] = { 0 };

	for (int i = 0; i < n; i++) {
		findLIS(ar, n, i, dp);
	}

	int maxLength = INT_MIN;
	for (int i = 0; i < n; i++) {
		maxLength = max(maxLength, dp[i]);
	}
	return maxLength;
}

int main() {
	int ar[] = { 1, 101, 2, 3, 100, 4, 5 };
	int n = sizeof(ar) / sizeof(ar[0]);
	cout << findLIS(ar, n) << endl;
	return 0;
}
