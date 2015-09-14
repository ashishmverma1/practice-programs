/*
 * Author:		Ashish Verma
 * Title:		min number of coins to make change
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

int findMinCoins(int coins[], int n, int v) {
	int dp[v + 1] = { 0 };
	for (int i = 1; i <= v; i++) {
		dp[i] = INT_MAX;
	}

	for (int val = 1; val <= v; val++) {
		for (int i = 0; i < n; i++) {
			if (coins[i] <= val) {
				dp[val] = min(dp[val], dp[val - coins[i]] + 1);
			}
		}
	}

	return dp[v];
}

int main() {

	int ar[] = { 9, 6, 5, 1 };
	int n = sizeof(ar) / sizeof(ar[0]);

	cout << findMinCoins(ar, n, 11);

	return 0;
}
