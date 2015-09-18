/*
 * Author:		Ashish Verma
 * Title:		n coins in a row. both players pick a coin from either end. Find max score of 1st player
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

int maxScore(int ar[], int n) {
	int dp[n][n] = { 0 };

	for (int i = 0; i < n; i++) {
		dp[i][i] = ar[i];
	}

	for (int len = 2; len <= n; len++) {
		for (int i = 0; i < n - len + 1; i++) {
			int j = i + len - 1;
			dp[i][j] = max(ar[i] + min(dp[i + 1][j - 1], dp[i + 2][j]),
					ar[j] + min(dp[i][j - 2], dp[i + 1][j - 1]));
		}
	}

	return dp[0][n - 1];
}

int main() {

	int ar[] = { 20, 30, 2, 2, 2, 10 };
	int n = sizeof(ar) / sizeof(ar[0]);

	cout << maxScore(ar, n);

	return 0;
}
