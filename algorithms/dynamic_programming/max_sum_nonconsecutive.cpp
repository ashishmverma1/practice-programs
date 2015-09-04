/*
 * Author:		Ashish Verma
 * Title:		max sum of non consecutive
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

int dp[10000] = { 0 };

int maxSum(int ar[], int n, int i = 0) {
	if (i >= n) {
		return 0;
	}
	if (dp[i]) {
		return dp[i];
	}

	int including, excluding;
	including = ar[i] + maxSum(ar, n, i + 2);
	excluding = maxSum(ar, n, i + 1);
	dp[i] = max(including, excluding);
	return dp[i];
}

int main() {
	int ar[] = { 5, 5, 10, 40, 50, 35 };
	int n = sizeof(ar) / sizeof(ar[0]);
	cout << maxSum(ar, n);

	return 0;
}
