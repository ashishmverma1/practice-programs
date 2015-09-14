/*
 * Author:		Ashish Verma
 * Title:		find min number of squars whose sum makes up n
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

int findMinSquares(int n) {
	int dp[n + 1] = { 0 };
	for (int i = 1; i <= n; i++) {
		if (i == 1 || i == 2 || i == 3) {
			dp[i] = i;
		} else {
			dp[i] = i;
			for (int j = 1; j * j <= i; j++) {
				dp[i] = min(dp[i], 1 + dp[i - j * j]);
			}
		}
	}
	return dp[n];
}

int main() {

	cout << findMinSquares(100);

	return 0;
}
