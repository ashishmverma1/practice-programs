/*
 * Author:		Ashish Verma
 * Title:		longest bitonic subsequence
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

void findLIS(int ar[], int n, int dp[]) {
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (ar[i] > ar[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
}

void findLDS(int ar[], int n, int dp[]) {
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (ar[i] > ar[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
}

int findLBS(int ar[], int n) {
	int lis[n], lds[n];

	findLIS(ar, n, lis);
	findLDS(ar, n, lds);

	int maxLength = INT_MIN;
	for (int i = 0; i < n; i++) {
		maxLength = max(maxLength, lis[i] + lds[i] - 1);
	}
	return maxLength;
}

int main() {
	int ar[] = { 1, 11, 2, 10, 4, 5, 2, 1 };
	int n = sizeof(ar) / sizeof(ar[0]);
	cout << findLBS(ar, n) << endl;
	return 0;
}
