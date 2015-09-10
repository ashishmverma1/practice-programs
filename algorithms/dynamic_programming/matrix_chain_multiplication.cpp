/*
 * Author:		Ashish Verma
 * Title:		find min scalar multiplications req for matrix chain multiplication
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

int findMinMultiplications(int dimension[], int n) {
	int dp[n][n];
	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}

	for (int length = 2; length < n; length++) {
		for (int i = 1; i <= n - length + 1; i++) {
			int j = i + length - 1;
			dp[i][j] = INT_MAX;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j],
						dp[i][k] + dp[k + 1][j] + dimension[i - 1] * dimension[k] * dimension[j]);
			}
		}
	}

	return dp[1][n - 1];
}

int main() {

	int dimension[] = { 1, 2, 3, 4 };
	int n = sizeof(dimension) / sizeof(dimension[0]);

	cout << findMinMultiplications(dimension, n);

	return 0;
}
