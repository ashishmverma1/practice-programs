/*
 * Author:		Ashish Verma
 * Title:		ways coin change problem
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

int findCoinsWays(int coins[], int n, int v) {
	int dp[v + 1][n];
	for (int j = 0; j < n; j++) {
		dp[0][j] = 1;
	}

	int including, excluding;

	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < n; j++) {
			including = excluding = 0;
			if (i - coins[j] >= 0) {
				including = dp[i - coins[j]][j];
			}
			if (j > 0) {
				excluding = dp[i][j - 1];
			}
			dp[i][j] = including + excluding;
		}
	}
	return dp[v][n - 1];
}

int main() {

	int ar[] = { 2, 5, 3, 6 };
	int n = sizeof(ar) / sizeof(ar[0]);

	cout << findCoinsWays(ar, n, 10);

	return 0;
}
