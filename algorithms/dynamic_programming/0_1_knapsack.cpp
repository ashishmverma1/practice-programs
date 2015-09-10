/*
 * Author:		Ashish Verma
 * Title:		find max val 0/1 knapsack
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

int knapsack(int w[], int p[], int n, int maxW) {
	int dp[n + 1][maxW + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= maxW; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			} else if (w[i - 1] <= j) {
				dp[i][j] = max(p[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n][maxW];
}

int main() {

	int p[] = { 60, 100, 120 };
	int w[] = { 10, 20, 30 };

	cout << knapsack(w, p, 3, 50);

	return 0;
}
