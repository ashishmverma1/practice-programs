/*
 * Author:		Ashish Verma
 * Title:		find min cost to reach from (0,0) to (m,n) in m*n matrix, where each cell contains
 * 				cost to pass through that cell. Total cost includes source and dest costs
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

const int r = 3;
const int c = 3;

int findMinCost(int cost[r][c]) {
	int dp[r][c];
	dp[0][0] = cost[0][0];

	for (int i = 1; i < c; i++) {
		dp[0][i] = dp[0][i - 1] + cost[0][i];
	}
	for (int i = 1; i < r; i++) {
		dp[i][0] = dp[i - 1][0] + cost[i][0];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			dp[i][j] = cost[i][j] + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
		}
	}
	return dp[r - 1][c - 1];
}

int main() {

	int cost[r][c] = { { 1, 2, 3 }, { 4, 8, 2 }, { 1, 5, 3 } };

	cout << findMinCost(cost);

	return 0;
}
