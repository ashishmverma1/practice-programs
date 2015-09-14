/*
 * Author:		Ashish Verma
 * Title:		Find min value to start within 2D grid such that bot points are always > 0.
 * 				On passing through array, score in grid gets added. -inf < A[i][j] < +inf
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

const int m = 3;
const int n = 3;

int minPoints(int ar[m][n], int m, int n) {

	int dp[m][n];

	dp[m - 1][n - 1] = (ar[m - 1][n - 1] >= 0) ? 1 : (abs(ar[m - 1][n - 1]) + 1);
	for (int j = n - 2; j >= 0; j--) {
		dp[m - 1][j] = max(dp[m - 1][j + 1] - ar[m - 1][j], 1);
	}
	for (int i = m - 2; i >= 0; i--) {
		dp[i][n - 1] = max(dp[i + 1][n - 1] - ar[i][n - 1], 1);
	}

	int minFromHere;
	for (int i = m - 2; i >= 0; i--) {
		for (int j = n - 2; j >= 0; j--) {
			minFromHere = min(dp[i + 1][j], dp[i][j + 1]);
			dp[i][j] = max(minFromHere - ar[i][j], 1);
		}
	}

	return dp[0][0];
}

int main() {

	int ar[m][n] = { { -2, -3, 3 }, { -5, -10, 1 }, { 10, 30, -5 } };

	cout << minPoints(ar, m, n);

	return 0;
}
