/*
 * Author:		Ashish Verma
 * Title:		find min cost to reach last station by breaking journey at any number of
 * 				intermediate stations
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

#define INF 99999

const int n = 4;

int findMinCost(int cost[n][n]) {
	int dp[n];
	dp[0] = 0;
	dp[1] = cost[0][1];

	for (int i = 2; i < n; i++) {
		dp[i] = INT_MAX;
		for (int j = 0; j < i; j++) {
			dp[i] = min(dp[i], dp[j] + cost[j][i]);
		}
	}

	return dp[n - 1];
}

int main() {

	int cost[n][n] = { { 0, 15, 80, 90 }, { INF, 0, 40, 50 }, { INF, INF, 0, 70 }, { INF, INF, INF,
			0 } };
	cout << findMinCost(cost);

	return 0;
}
