/*
 * Author:		Ashish Verma
 * Title:		longest increasing subsequence
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

int findLIS(int ar[], int n) {
	int maxLength = INT_MIN;
	int dp[n];
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (ar[j] < ar[i]) {
				dp[i] = max(dp[i], 1 + dp[j]);
				maxLength = max(maxLength, dp[i]);
			}
		}
	}

	return maxLength;
}

int main() {
	int ar[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(ar) / sizeof(ar[0]);
	cout << findLIS(ar, n) << endl;
	return 0;
}
