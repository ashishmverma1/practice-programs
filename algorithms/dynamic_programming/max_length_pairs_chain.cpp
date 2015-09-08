/*
 * Author:		Ashish Verma
 * Title:		find max length of chain of pairs (a, b) -> (c, d) such that b < c. Order doesnt matters.
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

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first < b.first;
}

int maxChainLength(pair<int, int> ar[], int n) {
	sort(ar, ar + n, comp);
	int dp[n];
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (ar[j].second < ar[i].first) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int maxLen = 1;
	for (int i = 0; i < n; i++) {
		maxLen = max(maxLen, dp[i]);
	}
	return maxLen;
}

int main() {
	pair<int, int> ar[] = { { 5, 24 }, { 15, 25 }, { 27, 40 }, { 50, 60 } };
	int n = sizeof(ar) / sizeof(ar[0]);

	cout << maxChainLength(ar, n);

	return 0;
}
