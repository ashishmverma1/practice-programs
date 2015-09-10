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

int nCr(int n, int r) {
	int dp[n + 1][r + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= r; j++) {
			if (j == 0 || j == i) {
				dp[i][j] = 1;
			} else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
	}
	return dp[n][r];
}

int main() {

	cout << nCr(5, 3);

	return 0;
}
